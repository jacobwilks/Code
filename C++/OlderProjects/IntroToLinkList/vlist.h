//vlist.h
//wilks,jacob
//jwilks

#ifndef VLIST_H
#define VLIST_H

#include<iostream>
#include<string>
using namespace std;

#include "video.h"
#include "node.h"

class Vlist
{
  public:
    Vlist(): m_head(NULL), num_vid(0){};
    ~Vlist();
    void insert(string title, string url, string comment, float length, int rating);
    void print();
    void remove(string);
    bool checkTitle(string title);
    void lookup(string title);
  private:
    Node *m_head;
    int num_vid;
};

#endif

