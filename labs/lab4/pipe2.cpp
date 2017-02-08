
//pipe2.cpp
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
  FILE *fpo;				//for writing to a pipe
 
  char buffer[BUFSIZ+1];		//BUFSIZ defined in <stdio.h>
  
  //Write buffer a message
  sprintf(buffer, "Arnod said, 'If I am elected, ..', and the fairy tale begins\n");  

  fpo = popen ( "od -c", "w" );	//pipe to command "od -c"
					//od -- output dump, see "man od"
  if ( fpo != NULL ) {
    //send data from buffer to pipe 
    fwrite(buffer, sizeof(char), strlen(buffer), fpo );  
    pclose ( fpo ); 			//close the pipe
    return 0; 
  }
  return 1;
}
