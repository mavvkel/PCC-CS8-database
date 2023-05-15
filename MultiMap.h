#ifndef MULTIMAP_H
#define MULTIMAP_H
#include "BTree.h"
#include "MPair.h"

//////////////////////////////////////////////////////////////////////////////
///
///     Map class:
///     @abstract   MultiMap is a shell class around BTree that binds it with
///             MPair storing key and vector of values; it creates a mapping
///             between the first and the second template parameters
///
///     @param  utilizes array untility functions
///     @param  utilizes BTree class
///     @param  utilizes MPair class
///
///     @note   erase member fxn erases the whole vector (deletes the whole
///             Pair object)
///
///     @todo   resolve the get fxn mess
///
//////////////////////////////////////////////////////////////////////////////
template <typename k, typename v>
class MultiMap {
    public:
        // === MUTATORS ===//
        void clear();
        void insert(const k& key, const v& value);
        void erase(const k& key);
        std::vector<v>& operator[](const k& key);

        // === ACCESSORS === //
        int size() const;
        bool empty() const;
        bool contains(const k& key) const ;
        bool is_valid();
        const std::vector<v>& operator[](const k& key) const;
        std::vector<v>& get(const k& key);

           friend ostream& operator<<(ostream& outs,
                                      const MultiMap<k, v>& print_me) {
               outs << print_me.m_multimap << '\n';
               return outs;
           }

    private:
        BTree< MPair<k, v> > m_multimap;
};


// === MUTATORS ==============================================================
template <typename k, typename v>
void MultiMap<k, v>::clear() {
    m_multimap.clear_tree();
}

template <typename k, typename v>
void MultiMap<k, v>::insert(const k& key, const v& value) {
    MPair<k, v> entry(key, value);

    MPair<k, v>* found_ptr = m_multimap.find(entry);
    if(found_ptr)
        found_ptr->value_list += value;
    else
        m_multimap.insert(entry);
}

template <typename k, typename v>
void MultiMap<k, v>::erase(const k& key) {
    if(contains(key)) {
        MPair<k, v> key_Pair(key);
        m_multimap.remove(key_Pair);
    }
}

template <typename k, typename v>
std::vector<v>& MultiMap<k, v>::operator[](const k& key) {
    MPair<k, v> key_Pair(key);
    return m_multimap.get(key_Pair).value_list;
}


// === ACCESSORS =============================================================
template <typename k, typename v>
int MultiMap<k, v>::size() const {
    return m_multimap.size();
}

template <typename k, typename v>
bool MultiMap<k, v>::empty() const {
    return m_multimap.empty();
}

template <typename k, typename v>
bool MultiMap<k, v>::contains(const k& key) const {
    MPair<k, v> target;
    target.key = key;
    return m_multimap.contains(target);
}

template <typename k, typename v>
bool MultiMap<k, v>::is_valid() {
    return m_multimap.is_valid();
}

template <typename k, typename v>
const std::vector<v>& MultiMap<k, v>::operator[](const k& key) const {
    MPair<k, v> key_Pair(key);
    assert(m_multimap.find(key_Pair));

    return m_multimap.get(key_Pair).value_list;
}

template <typename k, typename v>
std::vector<v>& MultiMap<k, v>::get(const k& key) {
    MPair<k, v> key_MPair(key);
    return m_multimap.get(key_MPair).value_list;
}

#endif // MULTIMAP_H
