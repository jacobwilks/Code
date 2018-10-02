//vlist.cpp
//wilks,jacob
//jwilks

#include <iostream>
#include <string>

using namespace std;

#include "vlist.h"


//deconstuctor to get rid of all memory made by member functions
Vlist::~Vlist()
{
  Node *ptr = m_head;
  while (ptr != NULL)
  {
    Node *anext = ptr;
    ptr = ptr->get_next();
    delete anext->get_value();
    delete anext;
  }
}


void Vlist::print()
{
  Node *ptr = m_head;
  while (ptr!= NULL)
  {
    (ptr->get_value())->print();
    ptr = ptr->get_next();
  }
}

//Search through list for a title
void Vlist::lookup(string title)
{
  Node *ptr = m_head;
  while(ptr !=NULL)
  {
    Video *ptr_to_vid = ptr->get_value();
    string current_name = ptr_to_vid->get_title();
    if (current_name == title)
    {
      ptr_to_vid->print();
      return;
    }
    ptr = ptr->get_next();
  }//while
}//lookup

//Removing video from list
void Vlist::remove(string title)
{
  //checks if first item is NULL
  if (m_head == NULL)
  {
    return;
  }

  Node *cur = m_head;
  Node *prev = NULL;
  if ((cur->get_value())->get_title() == title)
  {
    Node *temp = cur;
    m_head = cur->get_next();
    delete temp->get_value();
    delete temp;
    return;
  } 

  while( cur->get_next() != NULL)
  {
    prev= cur;
    cur=cur->get_next();

    if ((cur->get_value())->get_title() == title)
    {
      prev->set_next(cur->get_next());
      delete cur->get_value();
      delete cur;
      cur = NULL;
      return;
    }//if
  }//while
}//remove 

//inserts a new video and makes a node pointing to it. Places it alphabetically
void Vlist::insert(string title, string url, string comment, float length, int rating)
{
  if (m_head==NULL)
  {
    Video *vid_ptr = new Video(title,url,comment,length,rating);
    m_head = new Node(vid_ptr,NULL);
  }
  else
  {
    if ( (m_head->get_value())->get_title() > title)
    {
      m_head = new Node (new Video(title,url,comment,length,rating), m_head);
    }
    else
    {
      Node *before = m_head;
      while((before->get_next() != NULL) && (before->get_next())->get_value()->get_title() <= title)
      {
        before = before->get_next();
      }//while
      before->set_next( new Node (new Video(title,url,comment,length,rating), before->get_next()));
    }//inside else
  }//else
}//insert

//checks if the next title is already in the list
bool Vlist::checkTitle(string title)
{
  Node *ptr=m_head;
  while(ptr!= NULL)
  {
    if( (ptr->get_value())->get_title() == title)
    {
      return true;
    }
    ptr = ptr->get_next();
  }
  return false;
}



