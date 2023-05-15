#ifndef QUEUE_H
#define QUEUE_H
#include "LinkedListFunctions.h"
#include <cassert>

template <class T>
class Queue {
    public:

        class Iterator{
            public:
                friend class Queue;         //give access to list to access _ptr
                Iterator(Node<T>* p = nullptr) : _ptr(p) {}

                operator bool() const {    //casting operator: true if _ptr
                                           //not nullptr
                    return _ptr != nullptr;
                }


                T& operator*() {            //dereference operator
                    assert(_ptr);
                    return _ptr->_item;
                }

                T* operator->() {       //member access operator
                    return &_ptr;
                }

                bool is_null() {        //true if _ptr is NULL
                    return _ptr == nullptr;
                }

                friend bool operator !=(const Iterator& left,
                                        const Iterator& right) {
                                                        //true if left != right
                    return left._ptr != right._ptr;
                }

                friend bool operator ==(const Iterator& left,
                                        const Iterator& right) {
                                                        //true if left == right
                    return left._ptr == right._ptr;
                }

                Iterator& operator++() {     //member operator: ++it;
                                            //or ++it = new_value
                    assert(_ptr);
                    _ptr = _ptr->_next;
                    return *this;
                }

                Iterator& operator--() {     //member operator: --it;
                                            //or --it = new_value
                    assert(_ptr);
                    _ptr = _ptr->_prev;
                    return *this;
                }

                friend Iterator operator++(Iterator& it,
                                           int unused) {
                                                       //friend operator: it++
                    assert(it._ptr);
                    Iterator hold;
                    hold = it;
                    it._ptr = it._ptr->_next;
                    return hold;
                }

                friend Iterator operator--(Iterator& it,
                                           int unused) {
                                                        //friend operator: it--
                    assert(it._ptr);
                    Iterator hold;
                    hold = it;
                    it._ptr = it._ptr->_prev;
                    return hold;
                }

            private:
                Node<T>* _ptr;              //pointer being encapsulated
            };

        Queue() : _head(nullptr), _tail(nullptr), _size(0) {}

        // BIG 3
        Queue(const Queue<T>& other);
        ~Queue();
        Queue<T>& operator=(const Queue& rhs);

        void push(T item);
        T pop();
        bool empty();
        T front();
        unsigned int size();
        Node<T>* _find(const T& item);

        template <class E>
        friend ostream& operator<<(ostream& outs, const Queue<E>& q);

    private:
        Node<T>* _head;
        Node<T>* _tail;
        unsigned int _size;

};

template <class T>
ostream& operator<<(ostream& outs, const Queue<T>& q) {
    return print_list(q._head, outs);
}

//=============================== BIG 3 =======================================

template <class T>
Queue<T>::Queue(const Queue<T> &other) {
    this->_head = nullptr;
    this->_tail = nullptr;
    this->_size = 0;
    Node<T>* current = other._head;

    while(current) {
        this->push(current->_item);
        current = current->_next;
    }
}

template <class T>
Queue<T>::~Queue() {
    while(_head)
        this->pop();
}

template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& rhs) {
    this->~Queue();
    Node<T>* current = rhs._head;

    while(current) {
        this->push(current->_item);
        current = current->_next;
    }
    return *this;
}

//=============================================================================

template <class T>
void Queue<T>::push(T item) {
    if(_tail) {
        insert_after(this->_head, this->_tail, item);
        _tail = _tail->_next;
    }
    else {
        insert_head(this->_head, item);
        _tail = this->_head;
    }
    _size++;
}

template <class T>
T Queue<T>::pop() {
    _size--;
    if(!_head->_next)
        _tail = nullptr;
    return delete_head(this->_head);
}

template <class T>
bool Queue<T>::empty() {
    return this->_head == nullptr;
}

template <class T>
T Queue<T>::front() {
    assert(_head);
    return this->_head->_item;
}

template <typename T>
unsigned int Queue<T>::size() {
    return this->_size;
}

template <class T>
Node<T>* Queue<T>::_find(const T& item) {
    return find(this->_head, item);
}

#endif // QUEUE_H
