/*
*	Steven Tang
*	CSE 460 Homework 2A
*	
*	Create program that creates a chain of 10 processes and prints out
*	process ids and relationships. process 1 is parent of process 2,
*	process 2 is parent of process 3... etc 
*
*	Child = 0 
*	Parent = Anything but 0
*/

#include <iostream>
#include <unistd.h>
using namespace std;

int main()
{
	cout << endl;
	int pid = fork();
	for(int i=0; i < 10; i++) {
		if(pid == 0) {
	    	cout << "This is a child with ID: " << getpid()
	        	<< ". My parent ID is: " << getppid() << endl;
			pid = fork(); 
		} else
			wait(0);
	}
}
