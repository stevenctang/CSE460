/*
*	Steven Tang
*	CSE 460 Homework 2b
*	
*	Write a C-program that creates a fan of 10 processes. 
*	That is, process 1 is the parent of prcocesses 2, 3, 4, 5, 6 and so on.
*
*/
#include <iostream>
#include <unistd.h>
 
using namespace std;
 
int main()
{
 	int pid;
	int parent = getpid();

	cout << "\n\t\t\tParent id is: " << parent << endl;
	pid = fork();

  	for(int i=0; i < 10; ++i) {
		if(pid > 0) {
			pid = fork(); //We don't want parents, we want child so we fork
	  		if(pid == 0) {
	  		cout << "This is a child process: " << getpid() << ", and the parent ID is: " << getppid() << endl;
			}else
			wait(0);
		}
 	 }	
}
