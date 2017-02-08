//pipe3.cpp
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
  int nbytes;
  int fd[2];		//file descriptors for pipe
  const char s[] = "CSUSB";
  char buffer[BUFSIZ+1];

  memset ( buffer, 0, sizeof(buffer) );	//clear buffer

  if ( pipe( fd ) == 0 ) {	//create a pipe
    nbytes = write( fd[1], s, strlen( s ) );	//send data to pipe
    cout << "Sent " << nbytes << " bytes to pipe." << endl;
    nbytes = read ( fd[0], buffer, BUFSIZ );	//read data from pipe
    cout << "Read " << nbytes << " from pipe: " << buffer << endl;
    return 0;
  }
  return 1;
}
