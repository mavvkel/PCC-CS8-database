#include "SQL.h"

SQL::SQL() {
    command_count = 0;
}

void SQL::run() {
    string command;

    print_managed();
    while (true) {
        cout << "> ";
        std::getline(std::cin, command);
        if(command == "quit")
            break;
        Parser pr(command);
        cout << '[' << command_count++ << "]: " << command << '\n';

        MultiMap<string, string> ptree_ret = pr.get_ptree();

        ///cout << ptree_ret << '\n';  // DEBUG

        if(!command_type_checking(ptree_ret))
            if(!ptree_ret.empty() && ptree_ret["Command"][0] == "batch") {
                std::ifstream fin;
                fin.open(ptree_ret["File"][0] + ".txt");

                if(!fin.fail()) {
                    while(!fin.eof()) {
                        std::getline(fin, command);

                        if(command.empty()) {}
                        else if (command.at(0) == '/' && command.at(1) == '/')
                            cout << command << "\n";
                        else {
                        cout << '[' << command_count++ << "]: " << command
                             << '\n';
                            Parser prf(command);
                            MultiMap<string, string> ptree_retf =
                                    prf.get_ptree();
                            command_type_checking(ptree_retf);
                        }
                    }
                }
                else
                    cout << "FILE NOT FOUND\n";
                fin.close();
            }
    }
}

void SQL::print_managed() {
    cout << "------ Currently Managed SQL Tables: ------\n";
    for(size_t i=0; i<managed_names.size(); i++)
        cout << managed_names[i] << '\n';
    cout << "-------------------------------------------\n";
}

bool SQL::command_type_checking(MultiMap<string, string>& ptree_ret) {

    if(!ptree_ret.empty() && ptree_ret["Command"][0] == "select") {
        string table_name = ptree_ret["Table"][0];
        Table t(table_name);
        cout << t.select_where(ptree_ret["Fields"], ptree_ret["Condition"])
                << '\n';
        return true;
    }
    else if(!ptree_ret.empty() && (ptree_ret["Command"][0] == "make" ||
                                   ptree_ret["Command"][0] == "create")) {
        tables_managed.insert(ptree_ret["Table"][0],
                Table(ptree_ret["Table"][0], ptree_ret["Fields"]));
        managed_names.push_back(ptree_ret["Table"][0]);
        cout << '\n';
        print_managed();
        cout << '\n';
        return true;
    }
    else if(!ptree_ret.empty() && ptree_ret["Command"][0] == "insert") {
        tables_managed[ptree_ret["Table"][0]].insert_into(ptree_ret["Fields"]);
        return true;
    }
    return false;
}
