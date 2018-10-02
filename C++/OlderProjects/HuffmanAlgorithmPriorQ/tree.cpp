//main.cpp
//Jacob Wilks
//jwilks

#include<iostream>
#include<string>
using namespace std;
#include "tree.h"





//constructore that creates a single node tree
template <typename T>
Tree<T>::Tree(T val, int fr){
    root = new Node<T>(val, NULL, NULL, fr);
}//constructor

template <typename T>
Tree<T>::Tree(const Tree<T> &rhs){
  root = copy(rhs.root);
}

template <typename T>
Tree<T>::~Tree(){
  clear(root);
}


//Prints priorities (frequencies) in the tree
//change to preorder
template <typename T>
void Tree<T>::preorder(Node<T> *r){
    if(r != NULL)
    {
        cout << r << " ";
        preorder(r->prev); //left child
        preorder(r->next);//right child
    }//if
}//preorder

template <typename T>
int Tree<T>::merge(Tree &rhs){
    if(root != NULL && rhs.root != NULL){
        T val;//default constructor
        int pr;
        pr = root->priority + rhs.root->priority;
        //order of parameters in Node's constructor:
        //value, next(right), prev(left), priority
        root = new Node<T>(val, rhs.root, root, pr);
        rhs.root = NULL;
        return pr;
    }
    else{
        cerr << "ERROR: trees are empty." << endl;
        return -1;
        }
}

template <typename T>
Node<T>*Tree<T>::copy(Node<T> *r){
  if ( r != NULL){
  Node <T> *ptr = new Node<T>(r->value, NULL, NULL, r->priority);
  ptr->prev = copy(r->prev);
  ptr->next = copy(r->next);
  return ptr;
  }
  else{
    return NULL;
  }//else
}//copy

template <typename T>
void Tree<T>::operator=(const Tree<T> &rhs){
  if(root!= NULL){
    clear(root);
  root=copy(rhs.root);
}
}

template <typename T>
void Tree<T>::clear(Node<T> *r){
  if (r == NULL)
    return;
  clear(r->prev);
  clear(r->next);
  delete r;
}
