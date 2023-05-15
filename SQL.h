//////////////////////////////////////////////////////////////////////////////
///
///     SQL class:
///     @abstract   SQL class is a command language interpreter that allows
///             for manipulation of Table objects; available comands include
///             select, insert into, make/create, quit, batch;
///
///     @param  utilizes Parser, MutliMapPlus and Table classes
///     @param  inputing a query with nonexistent Table field/ file name will
///             trigger map assertions
///     @param  lines in batch file starting with // are displayed to the
///             screen and ignored
///     @param  to open a batch file input the file name WITHOUT the extension
///     @param  batch files MUST NOT contain queries to open other batch files
///
///     @todo   'managed' command, deleting Tables/.tbl files, loading found
///             .tbl files with init
///
//////////////////////////////////////////////////////////////////////////////
#ifndef SQL_H
#define SQL_H

#include "../../Includes/Table.h"
#include "../../Includes/MultiMapPlus.h"
#include "../../Includes/Parser.h"

class SQL {
    public:
        SQL();
        void run();

    private:
        Map<string, Table> tables_managed;
        vector<string> managed_names;
        size_t command_count;

        void print_managed();
        bool command_type_checking(MultiMap<string, string>& ptree_ret);
};

#endif // SQL_H
