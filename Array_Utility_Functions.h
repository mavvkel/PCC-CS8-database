#ifndef ARRAY_UTILITY_FUNCTIONS_H
#define ARRAY_UTILITY_FUNCTIONS_H

#include <iostream>
#include <cassert>
#include <vector>

//return the larger of the two items
template <typename T>
T maximal(const T& a, const T& b) {
    return (a > b) ? a : b;
}

//swap the two items
template <typename T>
void swap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

//return index of the largest item in data; returns -1 if data is empty
template <typename T>
int index_of_maximal(T data[], int n) {
    int max_index = -1;
    T max_val;

    if(n > 0) {
        max_val = data[0];
        max_index = 0;
    }

    for(int i = 0; i < n; i++)
        if(max_val < data[i]) {
            max_val = data[i];
            max_index = i;
        }
    return max_index;
}

//insert entry into the ascending sorted array data with lenght n
template <typename T>
void ordered_insert(T data[], int& n, T entry) {
    int insert_index = 0;
    while(data[insert_index] < entry && insert_index < n)
        insert_index++;


    for(int j = n - 1; j >= insert_index; j--)
        data[j + 1] = data[j];


    data[insert_index] = entry;
    n++;
}

//return the index of first element in data that is not less than entry
//if data is empty returns -1
template <typename T>
int first_ge(const T data[], int n, const T& entry) {
    assert(n >= 0);

    int index = 0;
    while(data[index] < entry && index < n)
        index++;

    return index;
}

//append entry to the right of data
template <class T>
void attach_item(T data[], int& n, const T& entry) {
    data[n] = entry;
    n++;
}

//insert entry at index i in data
template <class T>
void insert_item(T data[], int i, int& n, T entry) {
    assert(i <= n);

    if(n == i)
        attach_item(data, n, entry);
    else {
        for(int j = n - 1; j >= i; j--)
            data[j + 1] = data[j];

        data[i] = entry;
        n++;
    }
}

//remove the last element in data and place
//it in entry
template <class T>
void detach_item(T data[], int& n, T& entry) {
    assert(n > 0);
    entry = data[n - 1];
    n--;
}

//delete item at index i and place it in entry
template <class T>
void delete_item(T data[], int i, int& n, T& entry) {
    assert(i >= 0);
    assert(i < n);

    entry = data[i];

    for(int j = i; j < n - 1; j++)
        data[j] = data[j + 1];
    n--;
}

//append data2 to the right of data1
template <class T>
void merge(T data1[], int& n1, T data2[], int& n2) {
    assert(n1 >= 0);
    assert(n2 >= 0);
    assert(data1 != data2);

    for(int i = 0; i < n2; i++)
        data1[n1 + i] = data2[i];

    n1 += n2;
    n2 = 0;
}

//move n/2 elements from the right of data1 and move to data2
template <class T>
void split(T data1[], int& n1, T data2[], int& n2) {
    assert(n1 >= 0);
    assert(n2 >= 0);
    assert(data1 != data2);

    for(int i = n1 - n1/2; i < n1; i++)
        data2[i - n1 + n1/2] = data1[i];

    n2 += n1/2;
    n1 = n1 - n1/2;
}

//copy src[] into dest[]
template <class T>
void copy_array(T dest[], const T src[], int& dest_size, int src_size) {
    assert(dest_size >= 0);
    assert(src_size >= 0);

    if(src != dest) {
        dest_size = src_size;
        for(int i = 0; i < src_size; i++)
            dest[i] = src[i];
    }
}

//print array data
template <class T>
std::ostream& print_array(const T data[], int n, int pos = -1,
                 std::ostream& outs = std::cout) {
    assert(pos < n);

    for(int i = (pos > -1) ? pos : 0; i < n; i++) {
        outs << data[i];
        if(i != n - 1)
            outs << ' ';
    }
    return outs;
}

//item > all data[i]
template <class T>
bool is_gt(const T data[], int n, const T& item) {
    return (n == first_ge(data, n, item));
}

//item <= all data[i]
template <class T>
bool is_le(const T data[], int n, const T& item) {
    return !is_gt(data, n, item);
}


//-------------- Vector Extra operators: ---------------------

template <typename T>
std::ostream& operator<<(std::ostream& outs, const std::vector<T>& list) {
    for(size_t i = 0; i < list.size(); i++) {
        outs << list[i];
        if(i != list.size() - 1)
            outs << ' ';
    }
    return outs;
}

template <typename T>
std::vector<T>& operator+=(std::vector<T>& list, const T& addme) {
    list.push_back(addme);
    return list;
}

#endif // ARRAY_UTILITY_FUNCTIONS_H
