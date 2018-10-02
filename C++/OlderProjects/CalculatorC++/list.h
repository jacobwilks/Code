#include<iostream>
#include<string>
using namespace std;

#include "node.h"

#ifndef LIST_H
#define LIST_H

template <typename T> class List{
    private:
    Node<T> *head;
    public:
    List(): head(NULL) {};
    ~List();
    bool empty(){ return (head == NULL); };
    void insert_front(T val);
    bool remove_front();
    T front(){ return head->value; };
    void print();
};
#endif
