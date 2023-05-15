//////////////////////////////////////////////////////////////////////////////
///
///     Map class:
///     @abstract Map is a shell class around BTree data container, which
///             allows for mappings of pairs of data f.e. string to a int
///
///     @param utilizes array untility functions
///     @param utilizes BTree class
///
//////////////////////////////////////////////////////////////////////////////
#ifndef MAP_H
#define MAP_H
#include "BTree.h"

template <typename k, typename v>
struct Pair {
        k key;
        v value;

        Pair(const k& d = k(), const v& e = v()) : key(d), value(e) {}

        //INLINED
        bool operator==(const Pair<k, v>& rhs) const {return key == rhs.key;}
        bool operator!=(const Pair<k, v>& rhs) const {return key != rhs.key;}
        bool operator<(const Pair<k, v>& rhs) const {return key < rhs.key;}
        bool operator>(const Pair<k, v>& rhs) const {return key > rhs.key;}
        bool operator<=(const Pair<k, v>& rhs) const {return key <= rhs.key;}
        bool operator>=(const Pair<k, v>& rhs) const {return key >= rhs.key;}

        friend ostream& operator <<(ostream& outs, const Pair<k, v>& print_me) {
            outs << '[' << print_me.key << '|' << print_me.value << ']';
            return outs;
        }
};

template <typename k, typename v>
class Map {
    public:
        // === MUTATORS ===//
        void erase(const k& key);
        void insert(const k& key, const v& value);
        void clear();
        v& operator[](const k& key);
        v& at(const k& key);
        v get(const k& key);

        // === ACCESSORS === //
        int size() const;
        bool empty() const;
        const v& operator[](const k& key) const;
        const v& at(const k& key) const;
        const v get(const k& key) const;
        bool contains(const Pair<k, v>& target) const;
        bool is_valid() {return m_map.is_valid();}           //INLINED

        friend ostream& operator<<(ostream& outs, const Map<k, v>& print_me) {
            outs << print_me.m_map << '\n';
            return outs;
        }

    private:
        BTree< Pair<k, v> > m_map;
};


template <typename k, typename v>
v& Map<k, v>::operator[](const k& key) {
    Pair<k, v> key_Pair;
    key_Pair.key = key;
    assert(m_map.find(key_Pair));

    return m_map.get(key_Pair).value;
}

template <typename k, typename v>
void Map<k, v>::insert(const k& key, const v& value) {
    Pair<k, v> entry;
    entry.key = key;
    entry.value = value;

    m_map.insert(entry);
}

template <typename k, typename v>
int Map<k, v>::size() const {
    return m_map.size();
}

template <typename k, typename v>
bool Map<k, v>::empty() const {
    return m_map.empty();
}

template <typename k, typename v>
v& Map<k, v>::at(const k& key) {
    Pair<k, v> key_Pair;
    key_Pair.key = key;
    assert(m_map.find(key_Pair));

    return m_map.get(key_Pair).value;
}

template <typename k, typename v>
const v& Map<k, v>::operator[](const k& key) const {
    Pair<k, v> key_Pair;
    key_Pair.key = key;
    assert(m_map.find(key_Pair));

    return m_map.get(key_Pair).value;
}

template <typename k, typename v>
const v& Map<k, v>::at(const k& key) const {
    Pair<k, v> key_Pair;
    key_Pair.key = key;
    assert(m_map.find(key_Pair));

    return m_map.get(key_Pair).value;
}

template <typename k, typename v>
void Map<k, v>::erase(const k& key) {
    if(contains(key)) {
        Pair<k, v> key_Pair;
        key_Pair.key = key;

        m_map.remove(key_Pair);
    }
}

template <typename k, typename v>
void Map<k, v>::clear() {
    m_map.clear_tree();
}

template <typename k, typename v>
v Map<k, v>::get(const k& key) {
    Pair<k, v> key_Pair(key);
    return m_map.get(key_Pair).value;
}

template <typename k, typename v>
const v Map<k, v>::get(const k& key) const {
    Pair<k, v> key_Pair(key);
    return m_map.get(key_Pair).value;
}

template <typename k, typename v>
bool Map<k, v>::contains(const Pair<k, v>& target) const {
    return m_map.contains(target);

}

#endif // MAP_H
