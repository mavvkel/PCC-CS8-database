#ifndef STACK_H
#define STACK_H
#include "LinkedListFunctions.h"

template <typename T>
class Stack {
    public:

        class Iterator{
            public:
                friend class Stack;         //give access to list to access _ptr
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

        Stack() : _top(nullptr), _size(0) {}

        // BIG 3
        Stack(const Stack<T>& other);
        ~Stack();
        Stack<T>& operator=(const Stack<T>& rhs);

        void push(T item);
        T pop();
        T top();
        bool empty();
        unsigned int size();
        Node<T>* _find(const T& item);

        template <typename E>
        friend ostream& operator<<(ostream& outs, const Stack<E>& s);

    private:
        Node<T>* _top;
        unsigned int _size;

};


template <typename T>
ostream& operator<<(ostream& outs, const Stack<T>& s) {
    return print_list(s._top, outs);
}

//=============================== BIG 3 =======================================

template <typename T>
Stack<T>::Stack(const Stack<T>& other) {
    this->_top = nullptr;
    this->_size = 0;
    Node<T>* current = other._top;

    if(current) {
        while(current->_next)
            current = current->_next;

        while(current) {
            this->push(current->_item);
            current = current->_prev;
        }
    }
}

template <typename T>
Stack<T>::~Stack() {
    while(_top)
        this->pop();
}

template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& rhs) {
    this->~Stack();
    Node<T>* current = rhs._top;

    if(current) {
        while(current->_next)
            current = current->_next;

        while(current) {
            this->push(current->_item);
            current = current->_prev;
        }
    }
    return *this;
}

//=============================================================================

template <class T>
void Stack<T>::push(T item) {
    _size++;
    insert_head(this->_top, item);
}

template <class T>
T Stack<T>::pop() {
    _size--;
    return delete_head(this->_top);
}

template <typename T>
T Stack<T>::top() {
    assert(_top);
    return this->_top->_item;
}

template <typename T>
bool Stack<T>::empty() {
    return _top == nullptr;
}

template <typename T>
unsigned int Stack<T>::size() {
    return this->_size;
}

template <class T>
Node<T>* Stack<T>::_find(const T& item) {
    return find(this->_top, item);
}

#endif // STACK_H
