//////////////////////////////////////////////////////////////////////////////
///
///     BTree class:
///     @abstract   BTree data structure stores the data in a tree that sorts
///             the data based on > precedence
///
///     @param  utilizes Array Utility fxns
///
///     @todo   resolve get mess
///
//////////////////////////////////////////////////////////////////////////////
#ifndef BTREE_H
#define BTREE_H
#include <iostream>
#include <iomanip>
#include "Array_Utility_Functions.h"
using std::ostream;

template <typename T>
class BTree {
    public:
        BTree();


        // === BIG 3 === //
        ~BTree();
        BTree<T>& operator=(const BTree<T>& RHS);
        BTree(const BTree<T>& other);


        // === MUTATORS === //
        void clear_tree();
        void insert(const T& entry);
        void remove(const T& entry);


        // === ACCESSORS === //
        bool contains(const T& entry) const;
        T& get(const T& entry);
        const T& get(const T& entry) const;
        T* find(const T& entry);
        const T* find(const T& entry) const;
        bool is_valid();

        int size() const;
        bool empty() const {return data_count == 0;}        //INLINED
        void print_tree(int level = 0, ostream &outs = std::cout) const;

        friend ostream& operator<<(ostream& outs, const BTree<T>& print_me) {
            print_me.print_tree(0, outs);
            return outs;
        }                                                   // INLINED

    private:
        static const int MINIMUM = 1;
        static const int MAXIMUM = 2 * MINIMUM;

        int data_count;                    //number of data elements
        T data[MAXIMUM + 1];               //holds the keys
        int child_count;                   //number of children
        BTree<T>* subset[MAXIMUM + 2];        //subtrees


        // === HELPERS === //
        bool is_leaf() const {return child_count == 0;}   //INLINED

        void loose_insert(const T& entry);
        void fix_excess(int i);

        void loose_remove(const T& entry);
        void fix_shortage(int i);

        void remove_biggest(T& entry);
        void merge_with_next_subset(int i);
        void rotate_left(int i);
        void rotate_right(int i);

        bool is_valid_rec();
};


// === CTORS =================================================================
template <typename T>
BTree<T>::BTree() {
    data_count = 0;
    child_count = 0;
    for(int i = 0; i < MAXIMUM + 2; i++)
        subset[i] = nullptr;
}


// === BIG 3 =================================================================
template <typename T>
BTree<T>& BTree<T>::operator=(const BTree<T>& RHS) {
    if(this != &RHS) {              // preventing self-assignment
        this->clear_tree();

        copy_array(data, RHS.data, data_count, RHS.data_count);

        for(int i = 0; i < RHS.child_count; i++) {
            subset[i] = new BTree;
            *subset[i] = *RHS.subset[i];
        }

        child_count = RHS.child_count;
    }
    return *this;
}

template <typename T>
BTree<T>::BTree(const BTree<T>& other) {
    child_count = 0;
    *this = other;
}

template <typename T>
BTree<T>::~BTree() {
    this->clear_tree();
}


// === MUTATORS ==============================================================
template <typename T>
void BTree<T>::clear_tree() {
    data_count = 0;

    for(int i = 0; i < child_count; i++) {
        subset[i]->clear_tree();
        delete subset[i];
        subset[i] = nullptr;
    }
    child_count = 0;
}

template <typename T>
void BTree<T>::insert(const T& entry) {
    this->loose_insert(entry);

    if(data_count == MAXIMUM + 1) {
        BTree<T>* middle_child = new BTree<T>;

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
void BTree<T>::remove(const T& entry) {
    loose_remove(entry);

    if(data_count < MINIMUM && !is_leaf()) {
        BTree<T>* shrink_ptr = subset[0];

        merge(data, data_count, shrink_ptr->data, shrink_ptr->data_count);
        child_count = 0;
        merge(subset, child_count, shrink_ptr->subset, shrink_ptr->child_count);

        delete shrink_ptr;
    }
}


// === ACCESSORS =============================================================
template <typename T>
T* BTree<T>::find(const T& entry) {
    int i = first_ge(data, data_count, entry);
    bool found = (i < data_count && data[i] == entry);
    T* found_ptr = nullptr;

    if(found)
        return &data[i];
    else {
        if(is_leaf())
            return nullptr;
        else
            for(int j = i; j < child_count; j++) {
                found_ptr = subset[j]->find(entry);
                if(found_ptr)
                    return found_ptr;
            }
    }
    return found_ptr;
}

template <typename T>
const T* BTree<T>::find(const T& entry) const {
    int i = first_ge(data, data_count, entry);
    bool found = (i < data_count && data[i] == entry);

    if(found) {
        const T* found_ptr = &data[i];
        return found_ptr;
    }
    else {
        if(is_leaf())
            return nullptr;
        else
            for(int j = i; j < child_count; j++) {
                const T* found_ptr = subset[j]->find(entry);
                if(found_ptr)
                    return found_ptr;
            }
    }
    return nullptr;
}

template <typename T>
bool BTree<T>::contains(const T& entry) const {
    return this->find(entry) != nullptr;
}

template <typename T>
T& BTree<T>::get(const T& entry) {
    T* found_ptr = find(entry);

    if(!found_ptr)
        insert(entry);

    return *find(entry);
}

template <typename T>
const T& BTree<T>::get(const T& entry) const {
    assert(find(entry));
    const T* found_ptr = find(entry);
    return *found_ptr;
}

template <typename T>
void BTree<T>::print_tree(int level, ostream &outs) const {
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
int BTree<T>::size() const {
   int sz = data_count;
   for(int i = 0; i < child_count; i++)
       sz += subset[i]->size();
   return sz;
}


// === HELPER FXN ============================================================
template <typename T>
void BTree<T>::loose_insert(const T& entry) {
    int i = first_ge(data, data_count, entry);
    bool found = (i < data_count && data[i] == entry);

    if(found) {}
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
void BTree<T>::fix_excess(int i) {
    BTree<T>* new_child = new BTree<T>;
    insert_item(subset, i + 1, child_count, new_child);

    split(subset[i]->data, subset[i]->data_count, subset[i + 1]->data,
            subset[i + 1]->data_count);
    split(subset[i]->subset, subset[i]->child_count, subset[i + 1]->subset,
            subset[i + 1]->child_count);
    T entry;
    detach_item(subset[i]->data, subset[i]->data_count, entry);
    insert_item(data, i, data_count, entry);
}

template <typename T>
void BTree<T>::loose_remove(const T& entry) {
    int i = first_ge(data, data_count, entry);
    bool found = (i < data_count && data[i] == entry);
    T delete_entry;

    if(found) {
        if(this->is_leaf())
            delete_item(data, i, data_count, delete_entry);
        else {
            subset[i]->remove_biggest(data[i]);
            if(subset[i]->data_count < MINIMUM)
                fix_shortage(i);
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
void BTree<T>::fix_shortage(int i) {
    if(i + 1 < child_count && subset[i + 1]->data_count > MINIMUM)
        rotate_left(i + 1);
    else if(i > 0 && subset[i - 1]->data_count > MINIMUM)
        rotate_right(i - 1);
    else if(i + 1 < child_count)
        merge_with_next_subset(i);
    else
        merge_with_next_subset(i - 1);
}

template <typename T>
void BTree<T>::remove_biggest(T& entry) {
    if(!this->is_leaf()) {
       subset[child_count - 1]->remove_biggest(entry);
       if(subset[child_count - 1]->data_count < MINIMUM)
           fix_shortage(child_count - 1);
    }
    else
        detach_item(data, data_count, entry);
}

template <typename T>
void BTree<T>::merge_with_next_subset(int i) {
    T entry;
    delete_item(data, i, data_count, entry);
    attach_item(subset[i]->data, subset[i]->data_count, entry);

    merge(subset[i]->data, subset[i]->data_count, subset[i + 1]->data,
            subset[i + 1]->data_count);
    merge(subset[i]->subset, subset[i]->child_count, subset[i + 1]->subset,
            subset[i + 1]->child_count);

    BTree<T>* tmp;
    delete_item(subset, i + 1, child_count, tmp);
    delete tmp;
}

template <typename T>
void BTree<T>::rotate_left(int i) {
    assert(0 < i && i < child_count);
    assert(subset[i]->data_count > MINIMUM);
    assert(subset[i - 1]->data_count == MINIMUM - 1);

    attach_item(subset[i - 1]->data, subset[i - 1]->data_count, data[i - 1]);
    delete_item(subset[i]->data, 0, subset[i]->data_count, data[i - 1]);

    if(!subset[i]->is_leaf()) {
        BTree<T>* switch_ptr;
        delete_item(subset[i]->subset, 0, subset[i]->child_count, switch_ptr);
        attach_item(subset[i - 1]->subset, subset[i - 1]->child_count,
                switch_ptr);
    }
}

template <typename T>
void BTree<T>::rotate_right(int i) {
    assert(i < child_count - 1);
    assert(subset[i]->data_count > MINIMUM);
    assert(subset[i + 1]->data_count == MINIMUM - 1);

    insert_item(subset[i + 1]->data, 0, subset[i + 1]->data_count, data[i]);
    detach_item(subset[i]->data, subset[i]->data_count, data[i]);

    if(!subset[i]->is_leaf()) {
        BTree<T>* switch_ptr;
        detach_item(subset[i]->subset, subset[i]->child_count, switch_ptr);
        insert_item(subset[i + 1]->subset, 0, subset[i + 1]->child_count,
                switch_ptr);
    }
}

template <typename T>
bool BTree<T>::is_valid() {
    // Empty tree is valid
    return (child_count == 0 && data_count == 0) ? true :
                                                   this->is_valid_rec();
}

template <typename T>
bool BTree<T>::is_valid_rec() {
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

        for(int i = 0; i < child_count; i++)
            if(!subset[i]->is_valid())
                return false;
    }
    return true;
}

#endif // BTREE_H
