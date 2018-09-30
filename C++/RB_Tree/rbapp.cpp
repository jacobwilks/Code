/**
 * @file rbapp.cpp

 * @brief Implementation of a Red Black Tree. This purely handles
          proccesing the users request. Implements a loop that will continue to
          process input until EoF
 *
 *
 * @author Jacob Wilks
 * @date 4/20/18
 **/

#include <iostream>
#include <iomanip>
#include "rbapp.h"
#include "rbtree.h"
using std::cout;
using std::setw;
using std::endl;
using std::cin;
using std::string;

/**
 * @brief   Main Loop that continues to process commands until file is done
 * @return  Nothing.
 *
 * Until the file reaches an EoF mark it will continue to process commands.
 */

int main(){
  RBapp rbt;
  rbt.mainLoop();
  return 0;
}

void RBapp::mainLoop(){
  while (!cin.eof()){
    string input;
    getline(cin,input);
    string command = input.substr(0,input.find(' '));
    if (command != "quit"){
      processCommand(input);
    }
    else{
      break;
    }
  }
}

/**
 * @brief   RBapp Constructor - Empty
 * @return  Nothing.
 *
 */
//RBapp::RBapp(){
//}
/**
 * @brief  Pulls command from full input string and processes accordingly.
 * @param  input - The full line of input from user. command,key,satellite data
 * @return  false when quit is called
 *
 * takes the full input string and parses out the command from it. Then it
 * checks what the command is and calls the appropriate function. the string of
 * input is passed in to processinsert,processfind,and processdelete where it
 * will be parsed later on.
 */
bool RBapp::processCommand(string& input){
  string command = input.substr(0,input.find(' '));
  if (command == "insert"){
    processInsert(input);
  }
  else if (command == "find"){
    processFind(input);
  }
  else if (command == "delete"){
    processDelete(input);
  }
  else if (command == "print"){
    processPrint();
  }
  else if (command == "quit"){
    return false;
  }
  return true;
}

/**
 * @brief  Finds a given node in a tree and prints if found ( and duplicates)
 * @param  input - The full line of input from user. command,key,satellite data
 * @return  Nothing.

* A Vector of string pointers is created to hold the values of all matched
* nodes to the key that we are searching for. Input is stored into temp and
* temp is modified and parsed down into the findKey variable which just holds
* the value of the key that we want to delete. We call rbFind which returns a
* vector of string pointers telling us which values matched. Then we iterate
* through those values displaying the key and sattelite data of matching Nodes
*/
void RBapp::processFind(string& input){
  vector<const string*> matchingNodes;
  vector<const string*>::iterator it;
  string temp = input;
  temp.erase(0,temp.find(' ')+1);
  string findKey = temp.substr(0,temp.find(' '));
  matchingNodes = myRBT.rbFind(findKey);
  for (it=matchingNodes.begin(); it!=matchingNodes.end(); it++){
    cout<<findKey<< " "<< **it << endl;
  }
}

/**
 * @brief  Takes input string and parses key and satellite data then inserts it
 * @param  input - The full line of input from user. command,key,satellite data
 * @return  Nothing.

 * The input string is saved into the temp string variable where information
 * before first space is deleted and information before the second space saved
 * as a key, then information before second space is deleted and the remaining
 * information is saved as the satellite data.

 Refrences Used:
//http://www.cplusplus.com/reference/string/string/erase/
//http://www.cplusplus.com/reference/string/string/find/
*/
void RBapp::processInsert(string& input){
  string temp = input;
  temp.erase(0,temp.find(' ')+1);
  string insertKey = temp.substr(0,temp.find(' '));
  temp.erase(0,temp.find(' ')+1);
  string insertData = temp.substr(0);
  myRBT.rbInsert(insertKey,insertData);
}

/**
 * @brief  Takes input string and parses key and satellite data then deletes it
 * @param  input - The full line of input from user. command,key,satellite data
 * @return  Nothing.

 * The input string is saved into the temp string variable where information
 * before first space is deleted and information before the second space saved
 * as a key, then information before second space is deleted and the remaining
 * information is saved as the satellite data.
 * Functions almost identically to processInsert

 Refrences Used:
//http://www.cplusplus.com/reference/string/string/erase/
//http://www.cplusplus.com/reference/string/string/find/
*/
void RBapp::processDelete(string& input){
  string temp = input;
  temp.erase(0,temp.find(' ')+1);
  string deleteKey = temp.substr(0,temp.find(' '));
  temp.erase(0,temp.find(' ')+1);
  string deleteData = temp.substr(0,temp.find(' ')); //
  myRBT.rbDelete(deleteKey,deleteData);
}

/**
 * @brief  Prints RedBlack Tree
 * @return  Nothing.

 * Calls rbPrintTree function on myRBT
*/
void RBapp::processPrint(){
  myRBT.rbPrintTree();
}
