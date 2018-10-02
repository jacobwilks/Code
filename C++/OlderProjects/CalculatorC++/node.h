#include<iostream>
using namespace std;

#ifndef NODE_H
#define NODE_H

template <typename T> class Node{
    public:
    T value;
    Node *next;
    Node(T v, Node* n): value(v), next(n) {};
    Node(): next(NULL) {};
};

#endif
