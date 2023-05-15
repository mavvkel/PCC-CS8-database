#ifndef LINKEDLISTFUNCTIONS_H
#define LINKEDLISTFUNCTIONS_H

#include <iostream>
#include <cassert>
using std::ostream;
using std::cout;

template <class T>
struct Node {
        T _item;
        Node* _next;
        Node* _prev;
        Node(const T& item = T(), Node<T>* next = nullptr,
             Node<T>* prev = nullptr) : _item(item), _next(next), _prev(prev) {}


        friend ostream& operator<<(ostream& outs, const Node<T>& NodeToPrint) {
            outs << "[" << NodeToPrint._item << "]->";
            return outs;
        }
};


//==============================================================================


//insert at the beginning of the list:
template <class T>
Node<T>* insert_head(Node<T>* &head, T item);

//initializes head to nullptr
template <class T>
Node<T>* init_head(Node<T>* &head);

//delete the Node at the head of the list, reuturn the item:
template <class T>
T delete_head(Node<T>* &head);

//deletes all the Nodes in the list
template<class T>
void delete_all(Node<T>*&head);

//true if head is nullptr, false otherwise.
template <class T>
bool empty(const Node<T>* head);

//makes a copy of the list, returns a pointer to the last Node:
template <class T>
Node<T>* copy_list(const Node<T>* head, Node<T>* &cpy);

//insert_after: if after is nullptr, inserts at head
template <class T>
Node<T>* insert_after(Node<T>* &head, Node<T>* after, const T& item);

//insert_before: if before is nullptr, inserts at head
template <class T>
Node<T>* insert_before(Node<T>* &head, Node<T>* before, const T& item);

//print the list and return outs
template<class T>
ostream& print_list(const Node<T>* head, ostream& outs = cout);


//==============================================================================


template <class T>
Node<T>* insert_head(Node<T>* &head, T item) { //tested
    Node<T>* newNode = new Node<T>(item);

    if(head)
        head->_prev = newNode;
    newNode->_next = head;
    head = newNode;

    return head;
}

template<class T>
Node<T>* init_head(Node<T>* &head) {    // tested
    head = nullptr;
    return head;
}

template <class T>
T delete_head(Node<T>* &head) {     // tested
    Node<T>* tmp = head;
    T deletedItem;

    assert(head);

    deletedItem = head->_item;
    head = head->_next;
    if(head)
        head->_prev = nullptr;
    delete tmp;
    return deletedItem;
}

template<class T>
void delete_all(Node<T>*&head) {    // tested
  while(head)
        delete_head(head);
}

template <class T>
bool empty(const Node<T>* head) {   // tested
    return head == nullptr;
}

template <class T>
Node<T>* insert_after(Node<T>* &head, Node<T>* after, const T& item) {
    if(after) {
        Node<T>* newNode = new Node<T>(item);
        newNode->_next = after->_next;
        newNode->_prev = after;
        if(after->_next)
            after->_next->_prev = newNode;
        after->_next = newNode;
        return newNode;
    }
    else
        return insert_head(head, item);
}

template <class T>
Node<T>* copy_list(const Node<T>* head, Node<T>* &cpy) {    // tested
    delete_all(cpy);
    const Node<T>* current = head;
    Node<T>* last = cpy;

    if(head) {
        while(current->_next)
            current = current->_next;

        while(current) {
            insert_head(cpy, current->_item);
            current = current->_prev;
        }

        last = cpy;
        while(last->_next)
            last = last->_next;
    }

    return last;
}

template <class T>
Node<T>* insert_before(Node<T>* &head, Node<T>* before, const T& item) {
    if(before) {
        Node<T>* newNode = new Node<T>(item);
        newNode->_next = before;
        newNode->_prev = before->_prev;
        if(before != head)
            before->_prev->_next = newNode;
        else
            head = newNode;
        before->_prev = newNode;
        return newNode;
    }
    else
        return insert_head(head, item);
}

template <class T>
Node<T>* find(Node<T>* &head, const T& item) {
    Node<T>* current = head;

    if(head)
        while(current != nullptr && current->_item != item )
            current = current->_next;

    return current;
}

template<class T>
ostream& print_list(const Node<T>* head, ostream& outs) {
    const Node<T>* current = head;

    outs << "H->";
    while(current) {
        outs << *current;
        current = current->_next;
    }
    outs << "|||";

    return  outs;
}

#endif // LINKEDLISTFUNCTIONS_H
