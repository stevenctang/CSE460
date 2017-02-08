//test_alarm.cpp
#include <signal.h>
#include <unistd.h>
#include <iostream>

using namespace std;

//simulates an alarm clock
void ding ( int sig )
{
  	cout << "Alarm has gone off " << endl;
}

//tell child process to wait for 5 seconds before sending
//a SIGALRM signal to its parent.

int main()
{
  	int pid;

  	cout << "Alarm testing!" << endl;

  	if ( ( pid = fork() ) == 0 ) {	//child
    	sleep ( 5 );
    	/*
		Get parent process id, send SIGALARM signal to it. 
     	*/
    	kill ( getppid(), SIGALRM );	
    	return 1; 
  	}

  	//parent process arranges to catch SIGALRM with a call
  	//to signal and then waits for the inevitable.
  
  	cout << "Waiting for alarm to go off!" << endl;
  	(void) signal ( SIGALRM, ding );
 
  	pause();			//process suspended, waiting for signals to wake up
  	cout << "Done!" << endl;

  	return 1;
}
