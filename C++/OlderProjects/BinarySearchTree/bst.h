#include<iostream>
using namespace std;

#ifndef BST_H
#define BST_H
#include "tnode.h"

template <typename T>
class BST{
    private:
    Tnode<T> *root;
    bool find(T val, Tnode<T> *r);
    int balanced(Tnode<T> *r);
    int size(Tnode<T> *r);
    void inorder(Tnode<T> *r, bool check);//recursive
    void inorder(vector<T> &v, Tnode<T> *r);//recursive
    bool insert(T val, Tnode<T> * &r);
    void clear(Tnode<T> *r);
    void breadthtest(Tnode<T> *r, vector<T> &v);
    void rebalance(vector<T> &v, int start, int end);

    public:

    BST(): root(NULL){}
    ~BST();//destructor
    bool insert(T val);
    void breadth();
    void rebalance();
    bool find(T val);
    int size();
    bool balanced();
    void inorder(bool check);//prints inorder
    void inorder(vector<T> &v);//collects values into vector
};
#endif
