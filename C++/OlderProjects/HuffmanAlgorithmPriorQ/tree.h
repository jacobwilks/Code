//main.cpp
//Jacob Wilks
//jwilks
#include<iostream>
using namespace std;
#ifndef TREE_H
#define TREE_H
#include "node.h"

template <typename T>
class Tree{
    private:
        Node<T> *root;
        void preorder(Node<T> *r);
        Node<T>* copy(Node<T> *r);
        void clear(Node<T> *r);
    public:
        Tree(): root(NULL){};
        Tree(T ch, int fr);
        Tree( const Tree<T> &tr);
        ~Tree();
        int merge(Tree &rhs);
        void preorder_print(){ preorder(root);}
        void operator=(const Tree &rhs);
};
#endif
