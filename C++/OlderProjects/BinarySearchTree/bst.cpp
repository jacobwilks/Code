#include<iostream>
#include<vector>
#include <queue>
using namespace std;

#include "bst.h"

template <typename T>
BST<T>::~BST(){
    if(root != NULL){
        clear(root);
    }//
}//destructor

template <typename T>
void BST<T>::clear(Tnode<T> *r){
    if(r != NULL){
        clear(r->left);
        clear(r->right);
        delete r;
    }
}//clear

template <typename T>
bool BST<T>::insert(T val){
    return insert(val, root);
}//insert

template <typename T>
bool BST<T>::insert(T val, Tnode<T> * &r){
    if(r == NULL){//tree is emtpy
        r = new Tnode<T>(val);
        return true;
        }
    else{
        if(val == r->value)
            return false;
        else if(val < r->value){
            if(r->left == NULL){
                r->left = new Tnode<T>(val);
                return true;
            }
            else
                return insert(val, r->left);
        }//else val is less than current
        else{//val > r->value
            if(r->right == NULL){
                r->right = new Tnode<T>(val);
                return true;
            }
            else
                return insert(val, r->right);
        }//else val is greater than current
    }//else
}//insert recursive

template <typename T>
void BST<T>::inorder(bool check){
    inorder(root,check);
}//inorder

template <typename T>
void BST<T>::inorder(Tnode<T> *r, bool check){
    if(r == NULL){
        return;
    }
    inorder(r->left,check);
    if (check == false){  
    check = true;
    cout<< r->value;
    }
    else{
      cout<<", "<<r->value;
}
    inorder(r->right,check);
}//inorder recursive

/*
template <typename T>
void BST<T>::inorder(vector<T> &v){
    inorder(v, root);

}//collect values

template <typename T>
void BST<T>::inorder(vector<T> &v, Tnode<T> *r){
    if(r == NULL)
        return ;
    inorder(v, r->left);
    v.push_back(r->value);
    inorder(v, r->right);
}//recursively collect values
*/

template<typename T>
bool BST<T>::find(T val){
   return find(val,root);
}

template<typename T>
bool BST<T>::find(T val, Tnode<T> *r){
if ( r == NULL){
  return false;
  }
if (r->value == val){
  return true;
}
else if (r->value > val){
  return find(val, r->left);
  }
else if (r->value < val){
  return find(val, r->right);
  }
}

template<typename T>
bool BST<T>::balanced(){
int balance;
balance = balanced(root);
if (balance == -1)
  return false;
else
  return true;
}

template<typename T>
int BST<T>::balanced(Tnode<T> *r){
  if (r == NULL)
    return 0;
  if (r->left == NULL && r->right == NULL)
    return 0;
  int lhs, rhs, h;
  lhs = balanced(r->left);
  rhs = balanced(r->right);
  if(lhs == -1 || rhs == -1)
    return -1;
  if (abs(lhs - rhs) > 1)
    return -1;
  h = max(lhs,rhs) + 1;
  return h;
}

template<typename T>
int BST<T>::size(){
return size(root);
}

template<typename T>
int BST<T>::size(Tnode<T> *r){
  if (r == NULL)
    return 0;
  if (r->left == NULL && r->right == NULL)
    return 1;
  int lhs=0;
  int rhs=0;
  if (r->left != NULL)
    lhs = size(r->left);
  if (r->right != NULL)
    rhs = size(r->right);
  return (lhs+rhs+1);
}


template <typename T>
void BST<T>::rebalance(vector<T> &v, int start, int end){
  if (start == end)
    this->insert(v[start]);
  else if(start < end){
    int mid = (start + end) / 2;
    this->insert(v[mid]);
    rebalance(v, mid+1, end);
    rebalance(v, start, mid-1);
  }//else if
}//rebalance



template <typename T>
void BST<T>::rebalance(){
  vector<T> v;
  inorder(v,root);
  clear(root);
  root = NULL;
  rebalance(v,0,v.size() -1);
}//rebalance

template <typename T>
void BST<T>::breadthtest(Tnode<T> *r, vector<T> &v){
  queue< Tnode<T>* > q;

  if(root != NULL)
    q.push(root);
  else
    return;

  while(!q.empty()){
    Tnode<T> *temp = q.front();
    q.pop();

  if (temp != NULL){
    v.push_back(temp->value);
    q.push(temp->left);
    q.push(temp->right);
  }
  }
}//breadthtest

template <typename T>
void BST<T>::breadth(){
  vector<T> v;
  breadthtest(root,v);

  if (v.size() == 0){
    cout<<"{}"<<endl;
    return;
  }

  int size = v.size() -1;
  cout<<"{";
  for(int i=0; i<size; i++){
    cout << v[i]<<", ";
  }
  cout << v[size]<<"}"<<endl;
}
