//video.cpp
//wilks,jacob
//jwilks


#include <iostream>
#include <string>

using namespace std;

#include "video.h"

//functions below

Video::Video(string temp_title, string temp_url, string temp_comment, float temp_length, int temp_rating)
{
  title = temp_title;
  url = temp_url;
  comment = temp_comment;
  length = temp_length;
  rating = temp_rating;
}//constructor


void Video::print()
{
    cout <<title<<", "<<url<<", "<<comment<<", "<<length<<", ";
    for (int n=0; n<rating; n++)
    {
      cout<<"*";
    }
    cout<<endl;

}//print
