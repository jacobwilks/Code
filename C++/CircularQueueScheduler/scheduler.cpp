/**
 * @file scheduler.cpp
 *
 * @brief
 *    Simulates scheduling processes to run on a CPU in round-robin order.
 *
 * @author Jacob Wilks
 * @date 2/10/18
 */

#include <iostream>
#include <string>
#include "scheduler.h"

using std::string;
using std::cin;

/**
 * @brief   Scheduler constructor.
 */
Scheduler::Scheduler()
{

}

/**
 * @brief   Scheduler constructor.
 */
Scheduler::Scheduler(int timeQuantum)
{
  int clock=0;
  int timeQuantumUsed=0;
  bool shuttingDown=false;
  this->clock=clock;
  this->timeQuantum=timeQuantum;
  this->timeQuantumUsed=timeQuantumUsed;
  this->shuttingDown=shuttingDown;
}

/**
 * @brief   Scheduler destructor.
 */
Scheduler::~Scheduler()
{
}


/**
 * @brief   Run scheduler until nothing left to run.
 */

void Scheduler::run()
{
  while(!shuttingDown){
    checkForNew();
  }
}



/*   THIS HOW I FIND INPUT. ADD THIS IN P=0 and p<0 as well instead of run
    if(checkForNew()){ //while there is new processes to start
      if(tick()){ //if ready queue is not empty
        ready.getCurrent()->incTimeUsed();
        if ( !(ready.getCurrent()->done())){ //if the process is done
          timeQuantumUsed = timeQuantum;
          ready.getCurrent()->printCompleted(clock);
        }
        if (timeQuantum == timeQuantumUsed){
          ready.getNext();   //moves to next process
          timeQuantumUsed=0; //reset this for newprocess
        }
      }//tick
    }//while(checkForNew)
  }//while(shuttingDown)
}//run()
*/

/*
 * @brief   Check for new processes to add to the ready queue.
 * @return  true if there may be more processes to start, false otherwise
 *
 * A pid < 0 means we are shutting down - no more processes will be
 * starting - execute all processes in the ready queue to completion and
 * then terminate the program.
 *
 * Read in new processes and add to ready queue until the pid is <= 0.
 * A pid = 0 indicates no more new processes to start at this time.
 *
 * A pid > 0 indicates a new process and is followed by process values:
 *
 *    pid path-to-executable burst-time
 */
bool Scheduler::checkForNew()
{
  int pid;
  string executable;
  int burstTime;
  int arrivalTime=0;
  cin>>pid;
  if (pid == 0 ){ //if there is no more processes in queue
      //we use this to keep progressing the queue while reading in zeros
      tick();
      arrivalTime++;

      ready.getCurrent()->incTimeUsed();
      if ((ready.getCurrent()->done() == false)){ //if the process is done
          timeQuantumUsed = timeQuantum;
          ready.getCurrent()->printCompleted(clock);
        }
      if (timeQuantum == timeQuantumUsed){
        ready.getNext();   //moves to next process
        timeQuantumUsed=0; //reset this for newprocess
      }
      return true; //no more processes
    }//if pid ==0
 else if (pid > 0) //normal reading of processes
   {
    cin>>executable;
    cin>>burstTime;
    int timeUsed=0;
    arrivalTime = clock;
    Process *process= new Process
    (pid,executable,arrivalTime,burstTime,timeUsed);
    ready.append(*process);
    return true;
    //memory leak here too..?????
    }
    else{ //p < 0 - While there is still processes in the queue we
      //continue to run them until tick returns false and causes shuttingdown
      //to end the program
    while(tick()){
      arrivalTime++;
      ready.getCurrent()->incTimeUsed();
      if ( (ready.getCurrent()->done() == false)){ //if the process is done
        timeQuantumUsed = timeQuantum; //ensures it hits next if statement
        ready.getCurrent()->printCompleted(clock);
        }
      if (timeQuantum == timeQuantumUsed){
        ready.getNext();   //moves to next process
        timeQuantumUsed=0; //reset this for the newprocess
      }
     }//while(tick) this will end when the queue is empty and completely done
      shuttingDown = true;
      return false;
    }//else p<0
}//checkForNew

/**
 * @brief   Advance one CPU clock tick.
 * @return  true if ready queue is not empty, false if empty
 */
bool Scheduler::tick()
{
  clock++;
  timeQuantumUsed++;
  if (ready.getCurrent() != nullptr){
    return true;
  }
  else
  {
    return false;
  }
}//tick
