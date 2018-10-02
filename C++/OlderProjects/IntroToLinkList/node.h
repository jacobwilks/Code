//node.h
//wilks,jacob
//jwilks

#include<iostream>

using namespace std;

#ifndef NODE_H
#define NODE_H


class Node
    {
      public:
        Node(): value(NULL), next(NULL){};
        Node (Video* vid, Node* ptr): value(vid),next(ptr){};
        Video* get_value(){return value;};
        Node* get_next(){return next;};
        void set_next(Node *ptr){next = ptr;};
      private:
        Video* value;
        Node* next;
    };
#endif
