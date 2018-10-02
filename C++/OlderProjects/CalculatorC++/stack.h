#include<iostream>
using namespace std;
#include "list.h"

#ifndef STACK_H
#define STACK_H

template <typename T> class Stack{
    private:
    List<T> alist;
    public:
    void push(T val){ alist.insert_front(val); };
    void pop(){ if(!empty()) alist.remove_front(); };
    bool empty(){ return alist.empty(); };
    T top(){ return alist.front(); };
};
#endif
