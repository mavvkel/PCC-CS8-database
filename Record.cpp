#include "Record.h"

typedef vector<string> vstr;

void Record::clear() {
    recno = -1;
    for(size_t i=0; i<MAX_FIELDS_NUMBER; i++)
        record[i][0] = '\0';
}

long long Record::read(fstream &ins, long long recno) {
    this->clear();

    long long pos = recno * sizeof(record);
    ins.seekg(pos, ios_base::beg);


    ins.read(&record[0][0], sizeof(record));
    return ins.gcount();
}


// === ACCESSORS =============================================================
long long Record::write(fstream &outs) {
    //write to the end of the file.
    outs.seekg(0, outs.end);

    long long pos = outs.tellp();

    outs.write(&record[0][0], sizeof(record));

    return pos / sizeof(record);
}

vstr Record::get_fields() const {
    vstr fields;

    for(size_t i=0; i<MAX_FIELDS_NUMBER; i++) {
        string tmp = record[i];
        if(tmp.length())
            fields.push_back(tmp);
    }

    return fields;
}

bool Record::is_empty() const {
    return this->get_fields().size() == 0;
}

ostream& operator<<(ostream& outs, const Record& r) {
    size_t fields_used = r.get_fields().size();
    for(size_t i=0; i<fields_used; i++)
        outs << '|' << std::setw(20) << std::left << r.record[i];
    outs << std::setw(0) << '|';
    return outs;
}
