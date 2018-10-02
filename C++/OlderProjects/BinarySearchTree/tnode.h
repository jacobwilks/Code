#include<iostream>
using namespace std;

#ifndef TNODE_H
#define TNODE_H

template <typename T>
class Tnode{
    public:
    T value;
    Tnode<T> *left;
    Tnode<T> *right;
    Tnode(): left(NULL), right(NULL){};
    Tnode(T val): value(val), left(NULL), right(NULL){};
    Tnode(T val, Tnode<T> *l, Tnode<T> *r): value(val), left(l), right(r){};
    
};

#endif
