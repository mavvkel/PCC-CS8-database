#include "Table.h"

long long Table::serial_no = 0;

// === CTORS =================================================================
Table::Table() {
    init_precedence_map();
    serial_no++;
    t_table_name = "";
    empty = true;
}

Table::Table(const string& table_name, const vector<string> table_fields) {
    init_precedence_map();
    serial_no++;
    t_table_name = table_name;
    field_names = table_fields;

    for(size_t i=0; i<field_names.size(); i++)
        field_indices.insert(field_names[i], i);
    last_record_no = 0;
    empty = true;
    for(size_t i=0; i<table_fields.size(); i++) {
        MultiMapPlus<string, long long> new_map;
        tbl_data.insert(table_fields[i], new_map);
    }

    // writing field names to the file
    fstream f;
    open_fileW(f, (table_name + ".tbl").c_str());
    f.seekg(0, f.end);

    assert(f.tellg() == 0);
    Record table_spec(table_fields);
    table_spec.write(f);
    f.close();
}

Table::Table(const string& table_name) {
    init_precedence_map();
    t_table_name = table_name;
    empty = true;
    last_record_no = 0;

    // open the file for existing table
    fstream f;
    open_fileRW(f, (t_table_name + ".tbl").c_str());
    f.seekg(0, f.beg);

    // read in the fields from the first Record
    Record table_spec;
    table_spec.read(f, 0);
    field_names = table_spec.get_fields();
    for(size_t i=0; i<field_names.size(); i++)
        field_indices.insert(field_names[i], i);

    // build the field maps
    for(size_t i=0; i<field_names.size(); i++) {
        MultiMapPlus<string, long long> new_map;
        tbl_data.insert(field_names[i], new_map);
    }

    // read in the Records from the file
    Record next_row;
    size_t count = 1;
    next_row.read(f, count);

    while(!next_row.is_empty()) {
        for(size_t i=0; i<field_names.size(); i++)
            tbl_data[field_names[i]].insert(next_row.get_fields()[i],
                                            last_record_no);
        last_record_no++;
        count++;
        empty = false;
        next_row.read(f, count);
    }

    f.close();
}


// === MUTATORS ==============================================================
void Table::insert_into(vector<string> row) {
    assert(row.size() == field_names.size());
    assert(file_exists((t_table_name + ".tbl").c_str()));

    // open the file and saving the record
    fstream fin;
    open_fileRW(fin, (t_table_name + ".tbl").c_str());

    Record save_rec(row);
    last_record_no = save_rec.write(fin) - 1;

    for(size_t i=0; i<field_names.size(); i++)
        tbl_data[field_names[i]].insert(row[i], last_record_no);

    empty = false;
    fin.close();
}


// === ACCESSORS =============================================================
Table Table::select_all() const {
    Table return_copy(*this);
    return return_copy;
}

Table Table::select_where(vector<string> columns, vector<string> rows) {
    vector<string> new_fields;
    (columns[0] == "*") ? new_fields = field_names : new_fields = columns;
    Table new_table("temp_" + t_table_name, new_fields);


    // adjusting rows
    vector<long long> found_rows;
    if(rows.empty())
        for(size_t i=0; i<last_record_no; i++)
            found_rows.push_back(i);
    else
        found_rows = condition_evaluator(rows);


    // reading in the found rows from the file
    fstream fin;
    open_fileRW(fin, (t_table_name + ".tbl").c_str());

    for(size_t i=0; i<found_rows.size(); i++) {
        Record insert_rec;
        insert_rec.read(fin, found_rows[i] + 1);


        // adjusting columns
        if(columns[0] != "*") {
            vector<string> all_fields = insert_rec.get_fields();
            vector<string> selected_fields;
            for(size_t i=0; i<columns.size(); i++)
                selected_fields.push_back(all_fields[field_indices
                                          [columns[i]]]);
            new_table.insert_into(selected_fields);
        }
        else
            new_table.insert_into(insert_rec.get_fields());
    }

    fin.close();
    return new_table;
}


// === HELPER FUNCTIONS ======================================================
bool Table::file_exists(const char filename[]) const {
    const bool debug = false;
    fstream ff;
    ff.open (filename,
             std::fstream::in | std::fstream::binary );
    if (ff.fail()){
        if (debug) cout<<"file_exists(): File does NOT exist: "<<filename<<'\n';
        return false;
    }
    if (debug) cout<<"file_exists(): File DOES exist: "<<filename<<'\n';
    ff.close();
    return true;
}

void Table::open_fileRW(fstream& f, const char filename[]) const {
    const bool debug = false;
    //openning a nonexistent file for in|out|app causes a fail()
    //  so, if the file does not exist, create it by openning it for
    //  output:
    if (!file_exists(filename)) {
        f.open(filename, std::fstream::out|std::fstream::binary);

        if (f.fail())
            cout << "file open (RW) failed: with out|" << filename << "]"
                 << '\n';
        else
            if (debug) cout << "open_fileRW: file created successfully: "
                            << filename<<'\n';
    }
    else {
        f.open (filename,
                std::fstream::in | std::fstream::out| std::fstream::binary );
        if (f.fail())
            cout << "file open (RW) failed. [" << filename << "]" << '\n';
    }
}

void Table::open_fileW(fstream& f, const char filename[]) const {
    f.open(filename, std::fstream::out | std::fstream::binary);

    if (f.fail())
        cout << "file open failed: "<< filename << '\n';

}

vector<long long> Table::condition_evaluator(vector<string> conditions) {
    Queue<string> postfix_q;
    Stack<string> op_stack;
    Stack<vector<long long> > set_stack;


    // RPN
    while(!conditions.empty()) {
        if(precedence_map.contains(conditions[0])) {
            while(!op_stack.empty() && op_stack.top() != "(" &&
                  op_stack.top() != ")" && precedence_map[op_stack.top()] >=
                  precedence_map[conditions[0]]) {
                postfix_q.push(op_stack.pop());
            }
            op_stack.push(conditions[0]);
            conditions.erase(conditions.begin());
        }
        else if(conditions[0] == "(" || conditions[0] == ")") {
            if(conditions[0] == "(") {
                op_stack.push(conditions[0]);
                conditions.erase(conditions.begin());
            }
            else {
                while(op_stack.top() != "(")
                    postfix_q.push(op_stack.pop());        // mismatched case
                if(op_stack.top() == "(")
                    op_stack.pop();
                conditions.erase(conditions.begin());
            }
        }
        else {
            postfix_q.push(conditions[0]);
            conditions.erase(conditions.begin());
        }
    }

    while(!op_stack.empty())
        postfix_q.push(op_stack.pop());                   // mismatched case II


    ///cout << postfix_q << '\n';   // DEBUG

    // RPN EVALUATION
    while(!postfix_q.empty()) {
        if(precedence_map.contains(postfix_q.front())) {          // op found
            assert(postfix_q.front() != "=");
            assert(postfix_q.front() != ">");
            assert(postfix_q.front() != "<");
            assert(postfix_q.front() != "<=");
            assert(postfix_q.front() != ">=");

            if(postfix_q.front() == "or" || postfix_q.front() == "||") {
                vector<long long> lh_set = set_stack.pop();
                vector<long long> rh_set = set_stack.pop();
                vector<long long> union_set;

                std::set_union(lh_set.begin(), lh_set.end(), rh_set.begin(),
                               rh_set.end(), std::back_inserter(union_set));
                set_stack.push(union_set);
            }
            else if(postfix_q.front() == "and" || postfix_q.front() == "&&") {
                vector<long long> lh_set = set_stack.pop();
                vector<long long> rh_set = set_stack.pop();
                vector<long long> intersection_set;
                sort(lh_set.begin(), lh_set.end());
                sort(rh_set.begin(), rh_set.end());

                std::set_intersection(lh_set.begin(), lh_set.end(),
                                      rh_set.begin(), rh_set.end(),
                                      std::back_inserter(intersection_set));
                set_stack.push(intersection_set);
            }
            else {
                cout << "Operator '" << postfix_q.front() << "' not found\n";
                exit(2);
            }
            postfix_q.pop();

        }
        else {                                                  // symbol found
            string lhs_arg = postfix_q.pop();
            string rhs_arg = postfix_q.pop();
            string op = postfix_q.pop();

            if(op == "=") {
                vector<long long> found_rows = tbl_data[lhs_arg][rhs_arg];
                set_stack.push(found_rows);
            }
            else if(op == ">") {
                vector<long long> found_rows;
                for(MultiMapPlus<string, long long>::Iterator it
                        = tbl_data[lhs_arg].upper_bound(rhs_arg);
                    it != tbl_data[lhs_arg].end(); ++it)
                    found_rows.insert(found_rows.end(),
                                      (*it).value_list.begin(),
                                      (*it).value_list.end());

                set_stack.push(found_rows);
            }
            else if(op == "<") {
                vector<long long> found_rows;
                for(MultiMapPlus<string, long long>::Iterator it
                        = tbl_data[lhs_arg].begin();
                    it != tbl_data[lhs_arg].lower_bound(rhs_arg); ++it)
                    found_rows.insert(found_rows.end(),
                                      (*it).value_list.begin(),
                                      (*it).value_list.end());

                set_stack.push(found_rows);
            }
            else if(op == "<=") {
                vector<long long> found_rows;
                for(MultiMapPlus<string, long long>::Iterator it
                        = tbl_data[lhs_arg].begin();
                    it != tbl_data[lhs_arg].upper_bound(rhs_arg); ++it)
                    found_rows.insert(found_rows.end(),
                                      (*it).value_list.begin(),
                                      (*it).value_list.end());

                set_stack.push(found_rows);
            }
            else if(op == ">=") {
                vector<long long> found_rows;
                for(MultiMapPlus<string, long long>::Iterator it
                        = tbl_data[lhs_arg].lower_bound(rhs_arg);
                    it != tbl_data[lhs_arg].end(); ++it)
                    found_rows.insert(found_rows.end(),
                                      (*it).value_list.begin(),
                                      (*it).value_list.end());

                set_stack.push(found_rows);
            }
            //...
        }
    }
    return set_stack.pop();
}

void Table::init_precedence_map() {
    precedence_map.insert("or", 0);
    precedence_map.insert("and", 1);
    precedence_map.insert("&&", 1);
    precedence_map.insert("||", 0);
    precedence_map.insert("=", 2);
    precedence_map.insert(">", 2);
    precedence_map.insert("<", 2);
    precedence_map.insert(">=", 2);
    precedence_map.insert("<=", 2);
    //...
}
