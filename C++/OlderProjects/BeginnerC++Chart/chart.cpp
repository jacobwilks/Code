//chart.cpp
//Wilks, Jacob
//jwilks

#include <iostream>
#include <vector>

using namespace std;

int main()
{
  // Size is amount of ints used
  const int MAX = 100;
  int size=0;
  int values[MAX];
  int largest=0;

  for (int i=0; i<MAX; i++)
  {
    cin>>values[i];
    if(values[i]==0)
    {
      break;
    }
    size++;

  }

  for (int n=0; n<size; n++)
  {
    if(values[n] > largest)
    {
      largest = values[n];
    }
  }
  for (int row=largest; row> 0; row--)
  {
    for (int col=0; col<size; col++)
    {
      if (values[col]>= row)
      {
        cout<<"*";
      }
      else
      {
        cout<<" ";
      }
    }
    cout <<endl;

  }
  return 0;

}
