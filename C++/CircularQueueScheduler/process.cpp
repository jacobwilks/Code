/**
 * @file process.cpp
 *
 * @brief
 *    Function definitions for a class to represent an executing process.
 *
 * @author Jacob Wilks
 * @date 2/10/18
 */

#include <string>
#include <iostream>
#include "process.h"

using std::string;
using std::cout;
using std::endl;

/**
 * @brief   Process constructor.
 */
Process::Process()
{
//anything go in here??
}

/**
 * @brief   Process constructor.
 */
Process::Process(int pid, string execute, int arrive, int burst, int used)
{
  this->pid = pid;
  this->executable=execute;
  this->arrivalTime=arrive;
  this->burstTime=burst;
  this->timeUsed=used;
}

/**
 * @brief   Process destructor.
 */
Process::~Process()
{
  //
}

/**
 * @brief   Increments the time used by this Process so far.
 */
void Process::incTimeUsed()
{
  if (done()){
    timeUsed++;
 }
}

/**
 * @brief   Checks whether Process has completed.
 * @return  true if the Process needs more time, false if it has completed.
 */
bool Process::done()
{
  if (burstTime == timeUsed){ //process is done
    return false;
   }
  else{ // process not done
    return true;
    }//else
}

/**
 * @brief   Prints information on completed Process to stdout.
 * @param   now current CPU clock
 */
void Process::printCompleted(int now)
{
  cout<< pid << ", " << executable << "," << " arrival="<<
  arrivalTime<< "," << " burst=" <<burstTime << ","<< " wait=" <<
   (now-timeUsed-arrivalTime) << ","
  << " elapsed=" << now-arrivalTime << "\n";
}
