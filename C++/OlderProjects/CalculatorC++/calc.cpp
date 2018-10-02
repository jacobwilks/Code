//calc.cpp
//Jacob Wilks
//jwilks

#include <stdio.h>
#include <cmath>
#include <string>
#include <iostream>
#include "node.h"
#include <cstdlib>
#include "stack.h"
#include "list.cpp"

using namespace std;

//isoperator made to check if the input is an operator

bool isoperator(char input)
{
  if(input  == '*' || input  == '-' || input == '+' || input == '/' || input  == '^')
  {
    return true;
  }
  return false;
}


int main()
{
  Stack <double> astack;
  double result;

   while( cin.peek() != EOF){


  //if its a digit it or period it will push number onto the stack
    if (isdigit(cin.peek())|| cin.peek() == '.')
    {
      cin>>result;
      astack.push(result);
    }//if
       

    //if its a space it will ignore
    else if (isspace(cin.peek()))
    {
      cin.ignore();
    }

    //isoperator to check if input is a operator
    //if it is it will take the values and pop them off and based on the operator perform the correct function
    else if (isoperator(cin.peek()))
    {
      char op;
      cin>>op;

      if(astack.empty())
      {
        cerr<<"Error: Invalid expression."<<endl;
        return 1;
      }
      double rhs = astack.top();
      astack.pop();

      if (astack.empty())
      {
        cerr<<"Error: Invalid expression."<<endl;
        return 1;
      }
      double lhs = astack.top();
      astack.pop();
      

        if (op == '*')
          result = lhs * rhs;
        else if (op == '/')
          result = lhs / rhs;
        else if (op == '-')
          result = lhs - rhs;
        else if (op == '+')
          result = lhs + rhs;
        else if (op == '^')
        {
         if (floor(rhs) == rhs)
          {
          result = pow(lhs,rhs);
          }
         else
         {
           cerr<<"Error: Invalid expression."<<endl;
           return 1;
         }
        
        }//else if
        astack.push(result); 
      }
    else
    {
      cerr<<"Error: Invalid expression.";
      return 1;
    }//error code else
  
  }//while

   double answer;
   if (astack.empty())
   {
     cerr<<"Error: Invalid expression."<<endl;
     return 1;
   }
   answer = astack.top();
   astack.pop();

   if(astack.empty())
   {
     cout<<answer<<endl;
   }
   else
   {
     cerr<<"Error: Invalid expression."<<endl;
     return 1;
   }

  return 0;

}//main



