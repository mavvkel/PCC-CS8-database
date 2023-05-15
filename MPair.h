#ifndef MPAIR_H
#define MPAIR_H
#include <vector>
#include <iostream>

template <typename k, typename v>
struct MPair {
        k key;
        std::vector<v> value_list;

        // === CTORS === //
        MPair(const k& d, const v& e) : key(d) {
            value_list.push_back(e);}
        MPair(const k& d = k(), const std::vector<v>& e = std::vector<v>()) :
            key(d), value_list(e) {}

        //INLINED
        bool operator==(const MPair<k, v>& rhs) const {return key == rhs.key;}
        bool operator!=(const MPair<k, v>& rhs) const {return key != rhs.key;}
        bool operator<(const MPair<k, v>& rhs) const {return key < rhs.key;}
        bool operator>(const MPair<k, v>& rhs) const {return key > rhs.key;}
        bool operator<=(const MPair<k, v>& rhs) const {return key <= rhs.key;}
        bool operator>=(const MPair<k, v>& rhs) const {return key >= rhs.key;}

        friend std::ostream& operator <<(std::ostream& outs,
                                    const MPair<k, v>& print_me) {
            outs << '[' << print_me.key << '|' << print_me.value_list << ']';
            return outs;
        }
};

#endif // MPAIR_H
