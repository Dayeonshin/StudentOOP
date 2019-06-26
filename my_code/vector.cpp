#include <iostream>
#include "vector.h"

using namespace std;


MyVec::MyVec() : sz(0) {
    capacity = DEF_CAPACITY;
    data = new int[DEF_CAPACITY];
}

MyVec::MyVec(int size, int val) {
    sz = size;
    data = new int[sz];
    for(int i = 0; i < sz; i++)
        data[i] = val;
    capacity = 2*sz;
}


MyVec::MyVec(const MyVec& v2) {
    copy(v2);
}

MyVec::~MyVec() {
    delete [] data;
}

MyVec& MyVec::operator=(const MyVec& v2) {
    if (this != &v2) {
        delete [] data;
        copy(v2);
    }
    return *this;
}


MyVec::Iterator MyVec::begin() const {
    return MyVec::Iterator(data);
}

MyVec::Iterator MyVec::end() const {
    return MyVec::Iterator(data + sz);
}


bool operator==(MyVec& v1, MyVec& v2) {
    if (v1.size() == v2.size()) {
        for (int i = 0; i < v2.size(); i++) {
            if(v1[i] != v2[i])
                return false;
        }
        return true;
    }
    else {
        return false;
    }
}


void MyVec::push_back(int val) {
    sz++;
    if (sz > capacity) {
        cout << "Increasing capacity\n";
        int* old_data = data;
        data = new int[capacity * CAPACITY_MULT];
        for (int i = 0; i < sz; i++) {
            data[i] = old_data[i];
        }
        capacity *= CAPACITY_MULT;
        delete [] old_data;
    }
    data[sz - 1] = val;
}


int MyVec::operator[](int i) const {
    return data[i];
}


int& MyVec::operator[](int i) {
    return data[i];
}

void MyVec::copy(const MyVec& v2) {
    sz = v2.sz;
    capacity = v2.capacity;
    data = new int[capacity];
    for (int i = 0; i < sz; i++) {
        data[i] = v2.data[i];
    }
}


MyVec::MyVec() : sz(0) {
    capacity = DEF_CAPACITY;
    data = new T[DEF_CAPACITY];
}
