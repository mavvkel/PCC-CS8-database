//////////////////////////////////////////////////////////////////////////////
///
///     @details Concepts used: writing to/ reading from a binary file,
///         encoding info about a record spec in the first bits, Tokenization
///         & command parsing and interpretation, Shunting Yard & evaluation
///         of postfix notation
///
//////////////////////////////////////////////////////////////////////////////
#include "../../Includes/SQL.h"
#include "../../Includes/FTokenizer.h"


void test_Table();

void test_BPlusTree();

void test_Command_Parser();

void test_BPT_Iterator();

void SQL_test();

void test_BPlusTree_remove();

void test_canvasBPlusTree();

void test_btree_auto(int tree_size=5000, int how_many=500, bool report=false);

bool test_btree_auto(int how_many, bool report=true);

int Random(int lo, int hi);

void MultiMap_test_fxn();

MultiMapPlus<string, long> get_word_indices(char* file_name);

int main() {
    cout << '\n';

    //test_Table();

    //test_BPlusTree();

    //test_Command_Parser();

    //test_BPT_Iterator();

    SQL_test();

    //test_BPlusTree_remove();

    //test_btree_auto(1000, 100, false);

    //MultiMap_test_fxn();

    return 0;
}

void test_Table() {
    vector<string> v1 = {"Last", "First", "Dept"};
    Table t1("employees", v1);


    t1.insert_into({"Horry", "Bob", "CS"});
    t1.insert_into({"Fisher", "Derek", "CS"});
    t1.insert_into({"Olajuwon", "Hakeem", "Math"});
    t1.insert_into({"Olajuwon", "Abdul", "English"});
    t1.insert_into({"Durden", "Tyler", "Math"});
    t1.insert_into({"Oliver", "John", "Math"});
    t1.insert_into({"Smith", "Rick", "Natural Sciences"});

    cout << "t1:\n" << t1;
    Table t2("employees");

    cout << "\n============================================================\n";
    cout << "t2:\n" << t2;

    t2.insert_into({"Jackman", "Hugh", "Payroll"});

    cout << "\n============================================================\n";
    cout << "t2:\n" << t2;
    Table t3("employees");

    cout << "\n============================================================\n";
    cout << "t3:\n" << t3;

    t3.insert_into({"Bowman", "Ky", "Languages"});


    cout << "\n============================================================\n";
    cout << "t1:\n" << t1;
    cout << "t2:\n" << t2;
    cout << "t3:\n" << t3;

    // if I made changes to the file using t3, should I update t2?
    cout << "\n============================================================\n";

    Table t4 = t3.select_where({"*"}, {"Dept", "=", "Math"});
    Table t5 = t3.select_where({"Last"}, {"Dept", "=", "CS"});
    Table t6 = t3.select_where({"First", "Last"}, {"Dept", "=", "Math"});

    cout << "t4:\n" << t4;
    cout << "t5:\n" << t5;
    cout << "t6:\n" << t6;
    cout << "\n============================================================\n";

    string command;
    cout << "Input the command:\n";
    std::getline(std::cin, command);
    Parser pr(command);

    MultiMap<string, string> ptree_ret = pr.get_ptree();

    // multimap gives vectors, what about the [0]? --DropBox
    if(ptree_ret["command"][0] == "select") {
        string table_name = ptree_ret["table"][0];
        cout << ptree_ret << '\n';
        Table t(table_name);
        cout << t.select_where(ptree_ret["fields"], {"Dept", "=", "Math"})
             << '\n';
    }
    cout << "\n========================= END TEST =========================\n";
}

void test_BPlusTree() {
    BPlusTree<int> bpt1;
    BPlusTree<int> bpt2;


    int rem_num = 0;
    const int* found_ptr;

    cout << "bt1: \n" << bpt1 << '\n';
    while(rem_num != -999) {
        cout << "Insert number: ";
        std::cin >> rem_num;

        bpt1.insert(rem_num);

        cout << "bpt1: \n" << bpt1 << '\n' << '\n';

        cout << "Iterated list of items int bpt1: [";
        for(BPlusTree<int>::Iterator it = bpt1.begin(); it != bpt1.end(); ++it)
            cout << *it << ' ';
        cout << "]\n";
        cout << '[';
        for(BPlusTree<int>::Iterator it = bpt1.begin(); it != bpt1.end(); it++)
            cout << *it << ' ';
        cout << "]\n";
    }

    int* found_mutable;

    while(rem_num != -998) {
        cout << "Insert number to find: ";
        std::cin >> rem_num;

        found_ptr = bpt1.find(rem_num);

        (found_ptr) ? cout << "FOUND: " << *found_ptr << '\n' :
                              cout << "NOT FOUND\n";

    }

    while(rem_num != -997) {
        cout << "Insert number to check if contained: ";
        std::cin >> rem_num;


        (bpt1.contains(rem_num)) ? cout << "FOUND\n" :
                              cout << "NOT FOUND\n";

    }

    while(rem_num != -996) {
        cout << "Insert number to find: ";
        std::cin >> rem_num;

        found_mutable = bpt1.find(rem_num);

        (found_mutable) ? cout << "FOUND: " << *found_mutable << '\n' :
                              cout << "NOT FOUND\n";

        if(found_mutable) {
            cout << "Insert number to switch: ";
            std::cin >> rem_num;

            *found_mutable = rem_num;
            cout << "bpt1: \n" << bpt1 << '\n';
        }
    }

    cout << "Is bpt1 empty: "; (bpt1.empty()) ? cout << "YES\n" :
                                                        cout << "NO\n";
    cout << "Is bpt2 empty: "; (bpt2.empty()) ? cout << "YES\n" :
                                                        cout << "NO\n";

    cout << "\n========================== BIG 3 ===========================\n";
    cout << "\n========================== = op ===========================\n";
    BPlusTree<int> bpt3;
    BPlusTree<int> bpt4;
    bpt3 = bpt1;
    bpt4 = bpt3;

    cout << "Iterated list of items int bpt1: [";
    for(BPlusTree<int>::Iterator it = bpt1.begin(); it != bpt1.end(); ++it)
        cout << *it << ' ';
    cout << "]\n";

    cout << "Iterated list of items int bpt3: [";
    for(BPlusTree<int>::Iterator it = bpt3.begin(); it != bpt3.end(); ++it)
        cout << *it << ' ';
    cout << "]\n";

    cout << "Iterated list of items int bpt4: [";
    for(BPlusTree<int>::Iterator it = bpt4.begin(); it != bpt4.end(); ++it)
        cout << *it << ' ';
    cout << "]\n";

    cout << '\n';
    cout << "bpt1:" << bpt1 << "\n\n";
    cout << "bpt3:" << bpt3 << "\n\n";
    cout << "bpt4:" << bpt4 << "\n\n";


    bpt1.insert(3000);
    bpt3.insert(5000);
    bpt4.insert(-1999);

    cout << "bpt1:" << bpt1 << "\n\n";
    cout << "bpt3:" << bpt3 << "\n\n";
    cout << "bpt4:" << bpt4 << "\n\n";
    cout << "\n======================== copy ctor =========================\n";

    BPlusTree<int> bpt5(bpt1);
    BPlusTree<int> bpt6(bpt4);
    BPlusTree<int> bpt7(bpt6);



    cout << "Iterated list of items int bpt1: [";
    for(BPlusTree<int>::Iterator it = bpt1.begin(); it != bpt1.end(); ++it)
        cout << *it << ' ';
    cout << "]\n";

    cout << "Iterated list of items int bpt5: [";
    for(BPlusTree<int>::Iterator it = bpt5.begin(); it != bpt5.end(); ++it)
        cout << *it << ' ';
    cout << "]\n";

    cout << "Iterated list of items int bpt6: [";
    for(BPlusTree<int>::Iterator it = bpt6.begin(); it != bpt6.end(); ++it)
        cout << *it << ' ';
    cout << "]\n";

    cout << "Iterated list of items int bpt7: [";
    for(BPlusTree<int>::Iterator it = bpt7.begin(); it != bpt7.end(); ++it)
        cout << *it << ' ';
    cout << "]\n";

    cout << '\n';
    cout << "bpt1:" << bpt1 << "\n\n";
    cout << "bpt5:" << bpt5 << "\n\n";
    cout << "bpt6:" << bpt6 << "\n\n";
    cout << "bpt7:" << bpt7 << "\n\n";


    bpt1.insert(-5000);
    bpt6.clear_tree();
    bpt7.insert(9992);

    cout << "bpt1:" << bpt1 << "\n\n";
    cout << "bpt5:" << bpt5 << "\n\n";
    cout << "bpt6:" << bpt6 << "\n\n";
    cout << "bpt7:" << bpt7 << "\n\n";

    cout << "Iterated list of items int bpt6: [";
    for(BPlusTree<int>::Iterator it = bpt6.begin(); it != bpt6.end(); ++it)
        cout << *it << ' ';
    cout << "]\n";

    cout << "\n============================================================\n";

    MultiMapPlus<string, int> mmp1;
    MultiMapPlus<string, int> mmp2;

    string input;
    cout << "mmp1: \n" << mmp1 << '\n';

    while(input != "quit") {
        cout << "Input: ";
        std::cin >> input;
        cout << "Input val: ";
        std::cin >> rem_num;

        mmp1.insert(input, rem_num);

        cout << "mmp1: \n" << mmp1 << '\n';

        for(MultiMapPlus<string, int>::Iterator it = mmp1.begin();
            it != mmp1.end(); ++it)
            cout << *it << ' ';
        cout << '\n';
    }

    while(input != "quit1") {
        cout << "Input contains: ";
        std::cin >> input;

        (mmp1.contains(input)) ? cout << "FOUND\n" :
                              cout << "NOT FOUND\n";
    }

    while(input != "quit2") {
        cout << "Value at: ";
        std::cin >> input;

        (mmp1[input].size()) ? cout << "FOUND: " << mmp1[input] << '\n' :
                              cout << "NOT FOUND\n";
    }
}

void test_Command_Parser() {
    vector<string> v1 = {"Last", "First", "Dept", "Age", "State"};
    Table t1("school", v1);


    t1.insert_into({"Horry", "Bob", "CS", "22", "California"});
    t1.insert_into({"Fisher", "Derek", "CS", "18", "California"});
    t1.insert_into({"Olajuwon", "Hakeem", "Math", "32", "Michigan"});
    t1.insert_into({"Olajuwon", "Abdul", "English", "44", "Louisiana"});
    t1.insert_into({"Durden", "Tyler", "Math", "18", "New York"});
    t1.insert_into({"Oliver", "John", "Math", "22", "North Dakota"});
    t1.insert_into({"Smith", "Rick", "Natural Sciences", "52", "Ohio"});
    t1.insert_into({"Smith", "Steve", "Math", "23", "Ohio"});
    t1.insert_into({"Smith", "Josh", "Math", "42", "Michigan"});
    t1.insert_into({"Durden", "Elliot", "CS", "37", "Ohio"});
    t1.insert_into({"Kidd", "Josh", "English", "22", "California"});

    string command;

    while (true) {
        cout << "> ";
        std::getline(std::cin, command);
        if(command == "quit")
            break;
        Parser pr(command);

        MultiMap<string, string> ptree_ret = pr.get_ptree();

        // multimap gives vectors, what about the [0]?
        if(!ptree_ret.empty() && ptree_ret["Command"][0] == "select") {
            string table_name = ptree_ret["Table"][0];
            ///cout << ptree_ret << '\n';  // DEBUG
            Table t(table_name);
            cout << t.select_where(ptree_ret["Fields"], ptree_ret["Condition"])
                    << '\n';
        }
    }
}

void SQL_test() {
    SQL terminal;

    terminal.run();
}

void test_BPT_Iterator() {
    BPlusTree<int> bpt1;
    BPlusTree<int> bpt2;


    int rem_num = 0;

    cout << "bt1: \n" << bpt1 << '\n';
    while(rem_num != -999) {
        cout << "Insert number: ";
        std::cin >> rem_num;

        bpt1.insert(rem_num);

        cout << "bpt1: \n" << bpt1 << '\n' << '\n';

        cout << "SIZE: " << bpt1.size() << '\n';
        cout << "Iterated list of items int bpt1: [";
        for(BPlusTree<int>::Iterator it = bpt1.begin(); it != bpt1.end(); ++it)
            cout << *it << ' ';
        cout << "]\n";
        cout << '[';
        for(BPlusTree<int>::Iterator it = bpt1.begin(); it != bpt1.end(); it++)
            cout << *it << ' ';
        cout << "]\n";
    }


    cout << "\n\nFIND_IT\n";
    while(rem_num != -998) {
        cout << "Insert number: ";
        std::cin >> rem_num;

        BPlusTree<int>::Iterator it = bpt1.find_it(rem_num);

        cout << "it: " << *it << '\n';
    }

    cout << "\n\nLOWER_BOUND\n";
    cout << "bt1: \n" << bpt1 << '\n';
    while(rem_num != -997) {
        cout << "Insert number: ";
        std::cin >> rem_num;

        BPlusTree<int>::Iterator it = bpt1.lower_bound(rem_num);

        cout << "it: " << *it << '\n';
    }

    cout << "\n\nUPPER_BOUND\n";
    cout << "bt1: \n" << bpt1 << '\n';
    while(rem_num != -996) {
        cout << "Insert number: ";
        std::cin >> rem_num;

        BPlusTree<int>::Iterator it = bpt1.upper_bound(rem_num);

        cout << "it: " << *it << '\n';
    }

    cout << "SIZE EMPTY: " << bpt2.size() << '\n';

    BPlusTree<int>::Iterator it = bpt2.upper_bound(rem_num);
    (it != bpt2.end()) ? cout << *it : cout << "NULL it";
    cout << '\n';
    it = bpt2.lower_bound(rem_num);
    (it != bpt2.end()) ? cout << *it : cout << "NULL it";
    cout << '\n';

    cout << "\n\n\n\n";
    MultiMapPlus<string, int> mmp1;

    string input;
    cout << "mmp1: \n" << mmp1 << '\n';

    while(input != "quit") {
        cout << "Input: ";
        std::cin >> input;
        cout << "Input val: ";
        std::cin >> rem_num;

        mmp1.insert(input, rem_num);

        cout << "mmp1: \n" << mmp1 << '\n';

        cout << "SIZE: " << mmp1.size() << '\n';
        for(MultiMapPlus<string, int>::Iterator it = mmp1.begin();
            it != mmp1.end(); ++it)
            cout << *it << ' ';
        cout << '\n';
    }

    cout << "\n\nFIND_IT\n";
    while(input != "quit1") {
        cout << "Insert input: ";
        std::cin >> input;

        MultiMapPlus<string, int>::Iterator it = mmp1.find_it(input);

        (it != mmp1.end()) ? cout << "it: " << *it << '\n' :
                                     cout << "nullptr\n";
    }
}

void test_BPlusTree_remove() {

    BPlusTree<int> bpt1;
    BPlusTree<int> bpt2;


    int rem_num = 0;

    while(1) {
        std::cin >> rem_num;

        if(rem_num == -999)
            break;

        bpt1.insert(rem_num);

        (bpt1.is_valid()) ? cout << "VALID\n" : cout << "NOT VALID\n";
    }

    cout << "bpt1: \n" << bpt1 << '\n' << '\n';

    cout << "SIZE: " << bpt1.size() << '\n';
    cout << "Iterated list of items int bpt1: [";
    for(BPlusTree<int>::Iterator it = bpt1.begin(); it != bpt1.end(); ++it)
        cout << *it << ' ';
    cout << "]\n";
    cout << '[';
    for(BPlusTree<int>::Iterator it = bpt1.begin(); it != bpt1.end(); it++)
        cout << *it << ' ';
    cout << "]\n";


    while(1) {
        cout << "Remove number: ";
        std::cin >> rem_num;

        if(rem_num == -999)
            break;

        bpt1.remove(rem_num);

        cout << "bpt1: \n" << bpt1 << '\n' << '\n';

        cout << "SIZE: " << bpt1.size() << '\n';
        cout << "Iterated list of items int bpt1: [";
        for(BPlusTree<int>::Iterator it = bpt1.begin(); it != bpt1.end(); ++it)
            cout << *it << ' ';
        cout << "]\n";
        (bpt1.is_valid()) ? cout << "VALID\n" : cout << "NOT VALID\n";
    }
}

void test_btree_auto(int tree_size, int how_many, bool report) {
    bool verified = true;
    for (int i = 0; i< how_many; i++){
        if(i > how_many - 5)
            report = true;
        else
            report = false;

        if (report && i > how_many - 5){
            cout<<"*********************************************************"<< '\n';
            cout<<" T E S T:    "<<i<< '\n';
            cout<<"*********************************************************"<< '\n';
        }

        if (!test_btree_auto(tree_size, report)){
            cout<<"T E S T :   ["<<i<<"]    F A I L E D ! ! !"<< '\n';
            verified = false;
            return;
        }

    }
    cout<<"**************************************************************************"<< '\n';
    cout<<"**************************************************************************"<< '\n';
    cout<<"             E N D     T E S T: "<<how_many<<" tests of "<<tree_size<<" items: ";
    cout<<(verified?"VERIFIED": "VERIFICATION FAILED")<< '\n';
    cout<<"**************************************************************************"<< '\n';
    cout<<"**************************************************************************"<< '\n';

}

bool test_btree_auto(int how_many, bool report) {
    const int MAX = 10000;
    assert(how_many < MAX);
    BPlusTree<int> bpt;
    int a[MAX];
    int original[MAX];
    int deleted_list[MAX];

    int original_size;
    int size;
    int deleted_size = 0;

    //fill a[ ]
    for (int i= 0; i< how_many; i++){
        a[i] = i;
    }

    //shuffle a[ ]: Put this in a function!
    for (int i = 0; i< how_many; i++){
        int from = Random(0, how_many-1);
        int to = Random(0, how_many -1);
        int temp = a[to];
        a[to] = a[from];
        a[from] = temp;
    }

    //copy  a[ ] -> original[ ]:
    copy_array(original, a, how_many, how_many);
    size = how_many;
    original_size = how_many;
    for (int i=0; i<size; i++){
        bpt.insert(a[i]);

    }
    if (report){
        cout<<"========================================================"<< '\n';
        cout<<"  "<< '\n';
        cout<<"========================================================"<< '\n';
        cout<<bpt<< '\n'<< '\n';
    }
    for (int i= 0; i<how_many; i++){
        int r = Random(0, how_many - i - 1);
        if (report && i > how_many - 5){
            cout<<"========================================================"<< '\n';
            cout<<bpt<< '\n';
            cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . "<< '\n';
            cout<<"deleted: "; print_array(deleted_list, deleted_size);
            cout<<"   from: "; print_array(original, original_size);
            cout<< '\n';
            cout<<"  REMOVING ["<<a[r]<<"]"<< '\n';
            cout<<"========================================================"<< '\n';
            cout << i << " of " << how_many << '\n';
        }
        bpt.remove(a[r]);


        delete_item(a, r, size, deleted_list[deleted_size++]);
        if (!bpt.is_valid()){
            cout<<std::setw(6)<<i<<" I N V A L I D   T R E E"<< '\n';
            cout<<"Original Array: "; print_array(original, original_size);
            cout<<"Deleted Items : "; print_array(deleted_list, deleted_size);
            cout<< '\n'<< '\n'<<bpt<< '\n'<< '\n';
            return false;
        }

    }
    if (report) cout<<" V A L I D    T R E E"<< '\n';

    return true;
}

int Random(int lo, int hi)
{
    int r = rand()%(hi-lo+1)+lo;

    return r;
}

void MultiMap_test_fxn() {
    MultiMapPlus<string, long> word_indices;
     word_indices = get_word_indices("solitude.txt");
     cout<<std::endl<<std::endl<<std::endl;

     //list all nodes of the index mmap:
     for (MultiMapPlus<string, long>::Iterator it = word_indices.begin();
          it != word_indices.end(); it++){
         cout<<*it<<std::endl;
     }


     cout<<std::endl<<std::endl<<std::endl;
     cout<<"---------------------------------------------------"<<std::endl;
     string this_word = "ice";
     cout<<"---------------------------------------------------"<<std::endl;
     cout<<"Indices of \""<<this_word<<"\""<<std::endl;
     //list indices of this_word:
     if (word_indices.contains(this_word)){
         cout<<this_word<<": "<<word_indices[this_word]<<std::endl;
     }
     cout<<std::endl<<std::endl<<std::endl;

     cout<<"---------------------------------------------------"<<std::endl;
     string from = "ask";
     string to = "asker";
     //list from .. to:
     cout<<"listing indices from \""<<from<<"\" to \""<<to<<"\""<<std::endl;
     cout<<"---------------------------------------------------"<<std::endl;
     for (MultiMapPlus<string, long>::Iterator it =
                 word_indices.lower_bound(from);
          it != word_indices.upper_bound(to) &&
          it != word_indices.end(); it++){
         cout<<*it<<std::endl;
     }

     cout <<std::endl<<std::endl<<std::endl<< "========== E N D  ====================" << std::endl;
}

MultiMapPlus<string, long> get_word_indices(char* file_name){
    const bool debug = false;
    MultiMapPlus<string, long> word_indices;
    FTokenizer ftk("solitude.txt");
    Token t;
    long count = 0;

    ftk >> t;
    while (ftk.more()){
        //only the "words"
        if (t.string_type() == "ALPHA"){
            string s;
            s = t.token_str();
            word_indices[s] += count;
            count++;
            if (debug)
                cout<<"|"<<t.token_str()<<"|"<<std::endl;
        }
        ftk >> t;
    }
    return word_indices;
}
