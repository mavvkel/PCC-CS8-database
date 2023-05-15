//////////////////////////////////////////////////////////////////////////////
///
///     Table class:
///     @abstract Table stores Records of people/items and allows manipulation
///             of that data; writes the data to binary files
///
///     @param uses Maps, MultiMaps, Record, Stack, Queue classe
///
///     @note uses concepts of reading and writing binary files using fstream,
///             shared static variable among objects; saving flags of ostream
///             and retrieving them from the copy; Shunting Yard algorithm for
///             simple logic and postfix notation evaluation
///
///     @todo   mismatched parentheses cases in SYA; validation of symbols?
///             improve serial number system instead of temp_, make
///             precedence_map static const and create init for it
///
//////////////////////////////////////////////////////////////////////////////
#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <fstream>
#include <algorithm>
#include "MultiMapPlus.h"
#include "Map.h"
#include "Record.h"
#include "queue.h"
#include "Stack.h"
using std::string;
using std::vector;
using std::fstream;
using std::cout;

class Table {
    public:
        // === CTORS === //
        Table(const string& table_name, const vector<string> table_fields);
        Table(const string& table_name);
        Table();

        // === MUTATORS === //
        void insert_into(vector<string> row);

        // === ACCESSORS === //
        Table select_all() const;
        Table select_where(vector<string> columns, vector<string> rows);

        friend ostream& operator<<(ostream& outs, const Table& printMe) {
            std::ios init(nullptr);
            init.copyfmt(outs);

            fstream f;
            printMe.open_fileRW(f, (printMe.t_table_name + ".tbl").c_str());
            f.seekg(0, f.beg);

            string vert_bar(21*printMe.field_names.size() + 7, '=');
            outs << vert_bar << '\n';
            Record next_row;
            size_t count = 0;
            next_row.read(f, count);

            outs << std::left << std::setw(6) << "| #" << next_row << '\n';
            outs << vert_bar << '\n';
            count++;
            next_row.read(f, count);

            while(!next_row.is_empty()) {
                outs << "| " << std::setw(4) << count-1 << next_row << '\n';
                count++;
                next_row.read(f, count);
            }
            f.close();
            outs.copyfmt(init);
            if(printMe.empty)
                outs << '|' << std::setw(vert_bar.length()/2) << "EMPTY"
                     << std::setw(static_cast<int>(vert_bar.length() -
                                                   vert_bar.length()/2))
                     << "|\n";
            outs << vert_bar << '\n';
            return outs;
        }

    private:
        string t_table_name;
        Map<string, MultiMapPlus<string, long long> > tbl_data;
        vector<string> field_names;
        Map<string, size_t> field_indices;
        static long long serial_no;
        long long last_record_no;
        bool empty;
        Map<string, size_t> precedence_map;   // u could make it const, static

        // === HELPER FUNCTIONS === //
        void open_fileW(fstream& f, const char filename[]) const;
        void open_fileRW(fstream& f, const char filename[]) const;
        bool file_exists(const char filename[]) const;

        void init_precedence_map();
        vector<long long> condition_evaluator(vector<string> conditions);
};

#endif // TABLE_H
