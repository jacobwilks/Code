#include<iostream>
#include<string>
#include<type_traits>
using namespace std;

#include "list.h"

template <typename T>
List<T>::~List(){
    Node<T> *ptr = head;
    while(ptr != NULL){
        Node<T> *temp = ptr;
        ptr = ptr->next;
        delete temp;
    }//
}

template <typename T>
void List<T>::insert_front(T val){
    head = new Node<T>(val, head);
}//insert_front

template <typename T>
bool List<T>::remove_front(){
    if(!empty()){
        Node<T> *ptr = head;
        head = head->next;
//        if( is_pointer< decltype(ptr->value) >::value )
        delete ptr;
        ptr = NULL;
        return true;
    }//if
    else
        return false;
}//remove_front

template <typename T>
void List<T>::print(){
    if(!empty()){
        Node<T> *ptr = head;
        while(ptr != NULL){
            cout << ptr->value << endl;
            ptr = ptr->next;
        }//while
    }
}//print
