//////////////////////////////////////////////////////////////////////////////
///
///     MultiMapPlus class:
///     @abstract   MultiMapPlus is a shell class around BPlusTree, binding
///             it with MPair class; it creates a mapping between the first
///             and the second template parameters
///
///     @param  utilizes BPlusTree class
///     @param  utilizes MPair class
///
///     @note   erase member fxn erases the whole vector (deletes the whole
///             Pair object)
///
///     @todo   removes for MMP?, rest of the fxns? resolve get fxn mess
///
//////////////////////////////////////////////////////////////////////////////
#ifndef MULTIMAPPLUS_H
#define MULTIMAPPLUS_H
#include "BPlusTree.h"
#include "MPair.h"

template <typename k, typename v>
class MultiMapPlus {
        typedef BPlusTree< MPair<k, v> > BPTMP;
    public:

        class Iterator {
            public:
                friend class MultiMapPlus;

                Iterator(typename BPTMP::Iterator p = BPTMP()) : bpt_it(p) {}

                MPair<k, v>& operator*() {return *bpt_it;}

                Iterator& operator++() {
                    ++bpt_it;
                    return *this;
                }
                friend Iterator operator++(Iterator& it, int unused) {
                    Iterator hold = it;
                    it.bpt_it++;
                    return hold;
                }

                friend bool operator!=(const Iterator& lhs,
                                       const Iterator& rhs) {
                    return lhs.bpt_it != rhs.bpt_it;
                }


            private:
                typename BPTMP::Iterator bpt_it;

        };

        // === ACCESSORS === //
        bool empty() const;
        const std::vector<v>& operator[](const k& key) const;
        bool contains(const k& key) const;
        std::vector<v>& get(const k& key);
        int size() const {return m_multimap.size();}
        ///bool is_valid();

        friend ostream& operator<<(ostream& outs,
                                   const MultiMapPlus<k, v>& print_me) {
            outs << print_me.m_multimap << '\n';
            return outs;
        }

        Iterator begin() {return Iterator(m_multimap.begin());}
        Iterator end() {return Iterator(m_multimap.end());}
        Iterator find_it(const k& key) {
            return Iterator(m_multimap.find_it(key));
        }
        Iterator lower_bound(const k& key) {
            return Iterator(m_multimap.lower_bound(key));
        }
        Iterator upper_bound(const k& key) {
            return Iterator(m_multimap.upper_bound(key));
        }


        // === MUTATORS ===//
        void clear();
        void insert(const k& key, const v& value);
        std::vector<v>& operator[](const k& key);
        ///void erase(const k& key);


    private:
        BPlusTree< MPair<k, v> > m_multimap;
};


// === ACCESSORS =============================================================
template <typename k, typename v>
bool MultiMapPlus<k, v>::empty() const {
    return m_multimap.empty();
}

template <typename k, typename v>
const std::vector<v>& MultiMapPlus<k, v>::operator[](const k& key) const {
    MPair<k, v> key_Pair(key);
    return m_multimap.find(key_Pair)->value_list;
}

template <typename k, typename v>
bool MultiMapPlus<k, v>::contains(const k& key) const {
    MPair<k, v> target(key);
    return m_multimap.contains(target);
}

template <typename k, typename v>
std::vector<v>& MultiMapPlus<k, v>::get(const k& key) {
    MPair<k, v> key_MPair(key);
    return m_multimap.get(key_MPair).value_list;
}


// === MUTATORS ==============================================================
template <typename k, typename v>
void MultiMapPlus<k, v>::clear() {
    m_multimap.clear_tree();
}

template <typename k, typename v>
void MultiMapPlus<k, v>::insert(const k& key, const v& value) {
    MPair<k, v> entry(key, value);

    MPair<k, v>* found_ptr = m_multimap.find(entry);
    if(found_ptr)
        found_ptr->value_list += value;
    else
        m_multimap.insert(entry);
}

template <typename k, typename v>
std::vector<v>& MultiMapPlus<k, v>::operator[](const k& key) {
    MPair<k, v> key_Pair(key);
    return m_multimap.get(key_Pair).value_list;
}

#endif // MULTIMAPPLUS_H
