//////////////////////////////////////////////////////////////////////////////
///
///     Record class:
///     @abstract Record is a "card" containing info fields about an item;
///             it reads and writes Records to binary files
///
///     @param the number of the fields in a Record as well as their length
///             are arbitrarily limited by the static private consts (20 atm)
///     @param formatting of a Record output is setw to the max field length,
///             fields are separated by |
///
///     @note uses concepts of reading and writing binary files using fstream,
///
//////////////////////////////////////////////////////////////////////////////
#ifndef RECORD_H
#define RECORD_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <vector>
using std::fstream;
using std::ostream;
using std::string;
using std::ios_base;
using std::cout;
using std::vector;

class Record {
        typedef vector<string> vstr;

    public:
        Record() {                                  // INLINED
            for(size_t i=0; i<MAX_FIELDS_NUMBER; i++)
                record[i][0] = '\0';
            recno = -1;
        }

        Record(vstr fields) {                       // INLINED
            for(size_t i=0; i<MAX_FIELDS_NUMBER; i++)
                record[i][0] = '\0';
            for(size_t i=0; i<fields.size(); i++)
                strcpy(record[i], fields[i].c_str());
            recno = -1;
        }

        // === MUTATORS === //
        long long read(fstream& ins, long long recno);
        void clear();

        // === ACCESSORS === //
        long long write(fstream& outs);
        vstr get_fields() const;
        bool is_empty() const;
        friend ostream& operator<<(ostream& outs,
                                   const Record& r);
    private:
        static const int MAX_FIELDS_NUMBER = 20;
        static const int MAX_FIELD_SIZE = 20;
        int recno;
        char record[MAX_FIELDS_NUMBER][MAX_FIELD_SIZE];
};

#endif // RECORD_H
