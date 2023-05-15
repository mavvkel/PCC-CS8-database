//////////////////////////////////////////////////////////////////////////////
///
///     BPlusTree class:
///     @abstract   BTree data structure, that stores all the items in the
///             leaves and is iterable through next ptr that links
///             neighbouring leaves
///
///     @param  utilizes Array Utility fxns
///
///     @todo   remove & its helpers;
///
//////////////////////////////////////////////////////////////////////////////
#ifndef BPLUSTREE_H
#define BPLUSTREE_H
#include <iostream>
#include <iomanip>
#include "Array_Utility_Functions.h"
using std::ostream;

template <typename T>
class BPlusTree {
    public:

        class Iterator {
            public:
                friend class BPlusTree;

                Iterator(BPlusTree<T>* p = nullptr, int cdp = 0) : p_ptr(p),
                    current_data_point(cdp) {}


                T& operator*() {
                    assert(p_ptr);
                    assert(current_data_point < p_ptr->data_count);
                    return p_ptr->data[current_data_point];
                }

                Iterator& operator++() {
                    if(current_data_point == p_ptr->data_count-1) {
                        p_ptr = p_ptr->next;
                        current_data_point = 0;
                    }
                    else
                        current_data_point++;

                    return *this;
                }

                friend Iterator operator++(Iterator& it, int unused) {
                    Iterator hold;
                    hold = it;
                    ++it;
                    return hold;
                }

                friend bool operator!=(const Iterator& lhs,
                                       const Iterator& rhs) {
                    return lhs.p_ptr != rhs.p_ptr ||
                            lhs.current_data_point != rhs.current_data_point;
                }


            private:
                BPlusTree<T>* p_ptr;
                int current_data_point;
        };

        BPlusTree();

        // === BIG 3 === //
        ~BPlusTree();
        BPlusTree<T>& operator=(const BPlusTree<T>& RHS);
        BPlusTree(const BPlusTree<T>& other);

        // === MUTATORS === //
        void insert(const T& entry);
        T* find(const T& entry);
        T& get(const T& entry);
        void clear_tree();
        void remove(const T& entry);

        // === ACCESSORS === //
        bool contains(const T& entry) const;
        const T* find(const T& entry) const;
        bool empty() const {return data_count == 0;}        //INLINED
        void print_tree(int level = 0, ostream &outs = std::cout) const;
        int size() const;
        friend ostream& operator<<(ostream& outs,
                                   const BPlusTree<T>& print_me) {
            print_me.print_tree(0, outs);
            return outs;
        }                                                   // INLINED
        bool is_valid() const;

        Iterator begin() {return Iterator(this->find_min());}   // INLINED
        Iterator end() {return Iterator();}                     // INLINED
        Iterator find_it(const T& key);
        Iterator lower_bound(const T& key);
        Iterator upper_bound(const T& key);

    private:
        static const int MINIMUM = 1;
        static const int MAXIMUM = 2 * MINIMUM;

        int data_count;                    //number of data elements
        T data[MAXIMUM + 1];               //holds the keys
        int child_count;                   //number of children
        BPlusTree<T>* subset[MAXIMUM + 2];        //subtrees

        BPlusTree<T>* next;


        // === HELPERS === //
        bool is_leaf() const {return child_count == 0;}   //INLINED

        void loose_insert(const T& entry);
        void fix_excess(int i);

        BPlusTree<T>* find_min();               // for Iterator.begin()

        void copy_tree(const BPlusTree<T>& other, BPlusTree<T>*& last_leaf);

        void loose_remove(const T& entry);
        void fix_shortage(int i);

        void remove_biggest(T& entry);
        void merge_with_next_subset(int i);
        void rotate_left(int i);
        void rotate_right(int i);
        BPlusTree<T>* smallest_rhs() {                      // INLINED
            return (is_leaf()) ? this : subset[0]->find_min();
        }

        bool is_valid_rec() const;
};


// === CTORS =================================================================
template <typename T>
BPlusTree<T>::BPlusTree() {
    data_count = 0;
    child_count = 0;
    for(int i = 0; i < MAXIMUM + 2; i++)
        subset[i] = nullptr;
    next = nullptr;
}


// === BIG 3 =================================================================
template <typename T>
BPlusTree<T>::BPlusTree(const BPlusTree<T>& other) {
    data_count = 0;
    child_count = 0;
    for(int i = 0; i < MAXIMUM + 2; i++)
        subset[i] = nullptr;
    next = nullptr;

    BPlusTree<T>* tmp = nullptr;
    this->copy_tree(other, tmp);
}

template <typename T>
BPlusTree<T>& BPlusTree<T>::operator=(const BPlusTree<T>& RHS) {
    BPlusTree<T>* tmp = nullptr;
    this->clear_tree();
    this->copy_tree(RHS, tmp);
    return *this;
}

template <typename T>
BPlusTree<T>::~BPlusTree() {
    this->clear_tree();
}


// === ACCESSORS =============================================================
template <typename T>
bool BPlusTree<T>::contains(const T& entry) const {
    int i = first_ge(data, data_count, entry);
    bool found = (i < data_count && data[i] == entry);

    if(found)
        return true;
    else
        return (is_leaf()) ? false : subset[i]->contains(entry);
}

template <typename T>
const T* BPlusTree<T>::find(const T& entry) const {
    int i = first_ge(data, data_count, entry);
    bool found = (i < data_count && data[i] == entry);

    if(found)
        return (is_leaf()) ? &data[i] : subset[i+1]->find(entry);
    else
        return (is_leaf()) ?  nullptr : subset[i]->find(entry);
}

template <typename T>
typename BPlusTree<T>::Iterator BPlusTree<T>::lower_bound(const T& key) {
    int i = first_ge(data, data_count, key);
    bool found = (i < data_count && data[i] == key);

    if(found)
        return (is_leaf()) ? Iterator(this, i) : subset[i+1]->lower_bound(key);
    else {
        if(is_leaf())
            if(i < data_count)
                return Iterator(this, i);
            else
                return (next) ? Iterator(next, 0) : Iterator();

        else
             return subset[i]->lower_bound(key);
    }
}

template <typename T>
typename BPlusTree<T>::Iterator BPlusTree<T>::upper_bound(const T& key) {
    int i = first_ge(data, data_count, key);
    bool found = (i < data_count && data[i] == key);

    if(found) {
        if(is_leaf())
            if(i+1 < data_count)
                return Iterator(this, i+1);
            else
                return (next) ? Iterator(next, 0) : Iterator();

        else
            return subset[i+1]->upper_bound(key);
    }
    else {
        if(is_leaf())
            if(i < data_count)
                return Iterator(this, i);
            else
                return (next) ? Iterator(next, 0) : Iterator();

        else
            return subset[i]->upper_bound(key);
    }
}

template <typename T>
typename BPlusTree<T>::Iterator BPlusTree<T>::find_it(const T& key) {
    int i = first_ge(data, data_count, key);
    bool found = (i < data_count && data[i] == key);

    if(found)
        return (is_leaf()) ? Iterator(this, i) : subset[i+1]->find_it(key);
    else
        return (is_leaf()) ? Iterator() : subset[i]->find_it(key);
}

template <typename T>
bool BPlusTree<T>::is_valid() const {
    // Empty tree is a valid tree
    return (child_count == 0 && data_count == 0) ? true :
                                                   this->is_valid_rec();
}

// === MUTATORS ==============================================================
template <typename T>
void BPlusTree<T>::insert(const T& entry) {
    this->loose_insert(entry);

    if(data_count == MAXIMUM + 1) {
        BPlusTree<T>* middle_child = new BPlusTree<T>;

        copy_array(middle_child->data, this->data, middle_child->data_count,
                   this->data_count);
        copy_array(middle_child->subset, this->subset,
                   middle_child->child_count, this->child_count);

        data_count = 0;
        for(int i = 0; i < child_count; i++)
            subset[i] = nullptr;

        child_count = 1;
        subset[0] = middle_child;
        fix_excess(0);
    }
}

template <typename T>
T* BPlusTree<T>::find(const T& entry) {
    int i = first_ge(data, data_count, entry);
    bool found = (i < data_count && data[i] == entry);

    if(found)
        return (is_leaf()) ? &data[i] : subset[i+1]->find(entry);
    else
        return (is_leaf()) ?  nullptr : subset[i]->find(entry);
}

template <typename T>
T& BPlusTree<T>::get(const T& entry) {
    T* found_ptr = find(entry);

    if(!found_ptr)
        insert(entry);

    return *find(entry);
}

template <typename T>
void BPlusTree<T>::clear_tree() {
    data_count = 0;

    next = nullptr;
    for(int i = 0; i < child_count; i++) {
        subset[i]->clear_tree();
        delete subset[i];
        subset[i] = nullptr;
    }
    child_count = 0;
}

template <typename T>
void BPlusTree<T>::remove(const T& entry) {
    loose_remove(entry);

    if(data_count < MINIMUM && !is_leaf()) {
        BPlusTree<T>* shrink_ptr = subset[0];

        merge(data, data_count, shrink_ptr->data, shrink_ptr->data_count);
        child_count = 0;
        merge(subset, child_count, shrink_ptr->subset, shrink_ptr->child_count);

        delete shrink_ptr;
    }
}


// === HELPER FXN ============================================================
template <typename T>
void BPlusTree<T>::loose_insert(const T& entry) {
    int i = first_ge(data, data_count, entry);
    bool found = (i < data_count && data[i] == entry);

    if(found) {
        if(this->is_leaf())
            std::cout << "Duplicates not allowed\n";
        else {
            subset[i+1]->loose_insert(entry);
            if(subset[i+1]->data_count > MAXIMUM)
                fix_excess(i+1);
        }
    }
    else {
        if(this->is_leaf())
            insert_item(data, i, data_count, entry);
        else {
            subset[i]->loose_insert(entry);
            if(subset[i]->data_count > MAXIMUM)
                fix_excess(i);
        }
    }
}

template <typename T>
int BPlusTree<T>::size() const {
    int sz = 0;
    if(is_leaf())
        sz += data_count;

    for(int i=0; i<child_count; i++)
        sz += subset[i]->size();

    return sz;
}

template <typename T>
void BPlusTree<T>::fix_excess(int i) {
    BPlusTree<T>* new_child = new BPlusTree<T>;
    insert_item(subset, i + 1, child_count, new_child);

    split(subset[i]->data, subset[i]->data_count, subset[i + 1]->data,
            subset[i + 1]->data_count);
    split(subset[i]->subset, subset[i]->child_count, subset[i + 1]->subset,
            subset[i + 1]->child_count);
    T entry;
    detach_item(subset[i]->data, subset[i]->data_count, entry);
    insert_item(data, i, data_count, entry);

    if(this->subset[i]->is_leaf()) {
        new_child->next = subset[i]->next;
        subset[i]->next = new_child;
        subset[i+1]->insert(data[i]);
    }
}

template <typename T>
void BPlusTree<T>::print_tree(int level, ostream &outs) const {
    for(int i = child_count - 1; i > 0; i--) {
            subset[i]->print_tree(level + 1, outs);
        outs << std::setw(8 * level) << data[i - 1] << '\n';
    }

    if(is_leaf())
        for(int j = data_count - 1; j >= 0 ; j--)
            outs << std::setw(8 * level) << data[j] << '\n';

    if(!is_leaf())
        subset[0]->print_tree(level + 1, outs);
}

template <typename T>
BPlusTree<T>* BPlusTree<T>::find_min() {
    if(empty())
        return nullptr;
    return (is_leaf()) ? this : subset[0]->find_min();
}

template <typename T>
void BPlusTree<T>::copy_tree(const BPlusTree<T>& other,
                                     BPlusTree<T>*& last_leaf) {
    copy_array(data, other.data, data_count, other.data_count);

    if(!other.is_leaf()) {
        for(int i = 0; i < other.child_count; i++) {
            subset[i] = new BPlusTree;
            subset[i]->copy_tree(*other.subset[i], last_leaf);
        }
    }
    else {
        if(last_leaf)
            last_leaf->next = this;
        last_leaf = this;
    }
    child_count = other.child_count;
}

template <typename T>
void BPlusTree<T>::loose_remove(const T& entry) {
    int i = first_ge(data, data_count, entry);
    bool found = (i < data_count && data[i] == entry);
    T delete_entry;

    if(found) {
        if(this->is_leaf())
            delete_item(data, i, data_count, delete_entry);
        else {
            subset[i+1]->loose_remove(entry);
            if(!subset[i+1]->is_leaf()) {
                int j = first_ge(data, data_count, entry);
                bool found_after = (j < data_count && data[j] == entry);
                if(found_after)
                    data[j] = subset[j+1]->smallest_rhs()->data[0];
            }

            if(subset[i+1]->data_count < MINIMUM)
                fix_shortage(i+1);

            int j = first_ge(data, data_count, entry);
            bool found_after = (j < data_count && data[j] == entry);
            if(found_after)
                data[j] = subset[j+1]->smallest_rhs()->data[0];
        }
    }
    else
        if(!this->is_leaf()) {
            subset[i]->loose_remove(entry);
            if(subset[i]->data_count < MINIMUM)
                fix_shortage(i);
        }
}

template <typename T>
void BPlusTree<T>::fix_shortage(int i) {
    if(i > 0 && subset[i - 1]->data_count > MINIMUM)
        rotate_right(i - 1);
    else if(i + 1 < child_count && subset[i + 1]->data_count > MINIMUM)
        rotate_left(i + 1);
    else if(i > 0)
        merge_with_next_subset(i-1);
    else
        merge_with_next_subset(i);
}

template <typename T>
void BPlusTree<T>::merge_with_next_subset(int i) {
    T entry;
    delete_item(data, i, data_count, entry);
    if(!subset[i+1]->is_leaf())
        attach_item(subset[i]->data, subset[i]->data_count,
                    subset[i+1]->smallest_rhs()->data[0]);

    merge(subset[i]->data, subset[i]->data_count, subset[i + 1]->data,
            subset[i + 1]->data_count);
    merge(subset[i]->subset, subset[i]->child_count, subset[i + 1]->subset,
            subset[i + 1]->child_count);

    BPlusTree<T>* tmp;
    subset[i]->next = subset[i+1]->next;
    delete_item(subset, i + 1, child_count, tmp);
    delete tmp;
}

template <typename T>
void BPlusTree<T>::rotate_left(int i) {
    assert(0 < i && i < child_count);
    assert(subset[i]->data_count > MINIMUM);
    assert(subset[i - 1]->data_count == MINIMUM - 1);

    if(subset[i]->is_leaf()) {
        attach_item(subset[i - 1]->data, subset[i - 1]->data_count,
                subset[i]->data[0]);
        delete_item(subset[i]->data, 0, subset[i]->data_count, data[i - 1]);

        data[i-1] = subset[i]->data[0];
    }
    else {

    attach_item(subset[i - 1]->data, subset[i - 1]->data_count, data[i - 1]);
    delete_item(subset[i]->data, 0, subset[i]->data_count, data[i - 1]);
    }

    if(!subset[i]->is_leaf()) {
        BPlusTree<T>* switch_ptr;
        delete_item(subset[i]->subset, 0, subset[i]->child_count, switch_ptr);
        attach_item(subset[i - 1]->subset, subset[i - 1]->child_count,
                switch_ptr);
    }
}

template <typename T>
void BPlusTree<T>::rotate_right(int i) {
    assert(i < child_count - 1);
    assert(subset[i]->data_count > MINIMUM);
    assert(subset[i + 1]->data_count == MINIMUM - 1);

    if(subset[i+1]->is_leaf()) {
    T transfer_entry;
    detach_item(subset[i]->data, subset[i]->data_count, transfer_entry);
    insert_item(subset[i + 1]->data, 0, subset[i + 1]->data_count,
            transfer_entry);

    data[i] = subset[i+1]->data[0];
    }
    else {
        insert_item(subset[i + 1]->data, 0, subset[i + 1]->data_count, data[i]);
        detach_item(subset[i]->data, subset[i]->data_count, data[i]);
    }


    if(!subset[i]->is_leaf()) {
        BPlusTree<T>* switch_ptr;
        detach_item(subset[i]->subset, subset[i]->child_count, switch_ptr);
        insert_item(subset[i + 1]->subset, 0, subset[i + 1]->child_count,
                switch_ptr);
    }
}

template <typename T>
bool BPlusTree<T>::is_valid_rec() const {
    if(this->data_count < MINIMUM || this->data_count > MAXIMUM)
        return false;
    if(this->child_count < 0 || this->child_count > MAXIMUM + 1)
        return false;

    if(!this->is_leaf() && data_count + 1 != child_count)
        return false;

    for(int i = 0; i < data_count - 1; i++)
        if(data[i] > data[i + 1])
            return false;

    if(!this->is_leaf()) {
        for(int i = 0; i < data_count; i++)
            if(!is_gt(subset[i]->data, subset[i]->data_count, data[i]))
                return false;

        for(int i = 0; i < data_count - 1; i++)
            if(data[i] > subset[i + 1]->data[0])
                return false;

        for(int i=0; i<data_count; i++)
            if(data[i] != subset[i+1]->smallest_rhs()->data[0])
                return false;

        for(int i = 0; i < child_count; i++)
            if(!subset[i]->is_valid())
                return false;
    }
    return true;
}
#endif // BPLUSTREE_H
