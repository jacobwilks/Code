#ifndef VIDEO_H
#define VIDEO_H



#include <string>
#include <iostream>
using namespace std;

class Video
{
  public:
    Video(string,string,string,float,int);
    ~Video (){}
    bool longer(Video *other){return length > other->length;}
    bool name(Video *other){return title > other -> title;}
    bool rated(Video *other){return rating < other-> rating;}
    void print();


  private:
    string title;
    string url;
    string comment;
    float length;
    int rating;

};//class

#endif
