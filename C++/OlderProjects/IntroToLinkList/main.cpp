//main.cpp
//wilks,jacob
//jwilks

#include <iostream>
#include <iomanip>
#include <string>
#include "vlist.h"

using namespace std;


int main()
{
  //Variables
  Vlist vlist;
  string choice;
 int num_vid=0;
  string title;
  string url;
  string comment;
  float length;
  int rating;
  string temp_title;

  //Input and determining which function
  while(cin>>choice)
  {
    if (choice == "insert")
    {
      cin.ignore();
      getline(cin,title);
      getline(cin,url);
      getline(cin,comment);
      cin>>length;
      cin>>rating;
      cin.ignore();

      if (vlist.checkTitle(title) == false)
      {
      vlist.insert(title, url, comment, length, rating);
      num_vid++;
      }
      else
      {
        cerr<<"Could not insert video <" <<title<<">, already in list."<<endl;
      }
    }//Input If Statement

    else if(choice == "print")
    {
      vlist.print();
    }
    else if (choice == "length")
    {
      //use an incrementer to determine length by having it increment by 1 when insert runs
      cout<<num_vid<<endl;
    }
    else if (choice == "lookup")
    {
      cin.ignore();
      getline(cin,title);

      if (vlist.checkTitle(title) == true)
      {
      vlist.lookup(title);
      }
      else
      {
        cerr<<"Title <"<<title<<"> not in list."<<endl;
      }
    }
    else if (choice == "remove")
    {  
      cin.ignore();
      getline(cin,choice);
      temp_title = choice;
      if (vlist.checkTitle(choice) == true)
      {
      vlist.remove(temp_title);
      }
      else
      {
        cerr<<"Title <"<<temp_title<<"> not in list, could not delete."<<endl;
      }
    } 
    else
    {
      cerr<<"<"<<choice<<"> is not a legal command, giving up."<<endl;
      return 1;
    }

}//while

return 0;
}//main
