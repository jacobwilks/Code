#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iterator>
#include <string.h>
#include <stdio.h>
using namespace std;
#include "bst.cpp"

int main(int argc, char* argv[]){

   BST<string> words;
   string command; //initial command
   string temp; // if i need to insert stuff

   while(cin>>command){

    if (command == "echo"){
      cin.ignore();
      getline(cin,temp);
        cout<<temp<<endl;
    }//echo

    else  if (command == "insert"){
      cin.ignore();
      getline(cin,temp);
    words.insert(temp);
    
    }//insert

    else if (command == "size"){
      int treesize;
      treesize = words.size();
      cout<<treesize<<endl;
    }//size

    else if (command == "find"){
      cin.ignore();
      getline(cin,temp);
      bool found = words.find(temp);
        if(found){
         cout << "<" << temp <<"> is in tree."<<endl;
      }
    else
      cout <<"<"<<temp <<"> is not in tree."<<endl;
    }//find


    else  if (command == "print"){
      bool check = false;
      cout<<"{";
      words.inorder(check);
      cout<<"}";
    }//print

    else  if (command == "breadth"){
      words.breadth();
    }//breadth

    else if (command == "distance"){

    }//distance

    else if (command == "balanced"){

      bool wbalance = words.balanced();

      if (wbalance == true)
        cout<<"Tree is balanced."<<endl;
      else
        cout<<"Tree is not balanced."<<endl;
    }//balanced

    else if (command == "rebalance"){

//      words.rebalance();
    }//rebalance

    else
    {
      cout<<"Illegal command "<<command<<endl;
    }





   }//while
   


}//main
