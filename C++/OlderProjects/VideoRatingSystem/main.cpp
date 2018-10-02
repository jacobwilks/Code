#include <iostream>
#include <iomanip>
#include <string>

#include "video.h"
using namespace std;


int main()
{
  Video *videos[100];
  string choice;
  int num_vid=0;
  string title;
  int print_num;
  int menu=0;
  string url;
  string comment;
  float length;
  int rating;

//takes input and decides sorting method
  cin>>choice;
  
      if (choice == "length")
      {
        menu = 1;
      }
      else if(choice == "rating")
      {
        menu = 2;
      }
      else if (choice == "title")
      {
        menu=3;
      }
      else
      {
        menu=4;
      }
      cin.ignore();
     
     //gets input until there is no more titles, wil llimit it to 100
    while(getline(cin,title))
    {
      getline(cin,url);
      getline(cin,comment);
      cin>>length;
      cin>>rating;
      cin.ignore();
// makes a new object
      Video *temp_video_ptr = new Video(title,url,comment,length,rating);
      videos[num_vid]= temp_video_ptr;
      num_vid++;

      if (num_vid >100)
      {
        cerr<<"Too many videos, giving up."<<endl;
        return 1;
      }
    }



//these are to determine what sorting method to use
        if(menu == 1)
        {
          for(int last = num_vid -1; last > 0; last --)
          {
            for (int cur=0; cur<last; cur++)
            {
              if (videos[cur]->longer(videos[cur+1]))
              {
                swap(videos[cur], videos[cur+1]);
              }
            }
          }
        }

        else if(menu == 2)
        {
          for(int last = num_vid -1; last > 0; last --)
          {
            for (int cur=0; cur<last; cur++)
            {
              if (videos[cur]->rated(videos[cur+1]))
              {
                swap(videos[cur], videos[cur+1]);
              }
            }
          }
        }

        else if(menu ==3)
        {
          for(int last = num_vid -1; last > 0; last --)
          {
            for (int cur=0; cur<last; cur++)
            {
              if (videos[cur]->name(videos[cur+1]))
              {
                swap(videos[cur], videos[cur+1]);
              }
            }
          }
        }
        else if(menu==4)
        {
        cerr<<choice<<" is not a legal sorting method, giving up."<<endl;
        return 1;
        }


  //how many times ive printed output
  print_num = 0;
  while (print_num<num_vid)
  {
    videos[print_num]->print();
    print_num++;
  }
  //to delete object space in heap
  for(int j=0; j<num_vid; j++)
  {
    delete videos[j];
    videos[j]=0;
  }
  return 0;
}//main
