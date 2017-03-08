/*
  sdlthread_demo.cpp
  A very simple example demonstrating the usage of sdl threads.
  Compile:  g++ -o sdlthread_demo sdlthread_demo.cpp -lSDL -lpthread
  Execute:  ./sdlthread_demo
*/

#include <SDL/SDL.h>
#include <SDL/SDL_thread.h>
#include <stdio.h>

using namespace std;

//The thread
int runner ( void *data )
{
  char *tname = ( char * )data;

  printf("I am %s\n", tname );
  return 0;
}

int main ()
{
  SDL_Thread *id1, *id2, *id3;                //thread identifiers
  char *tnames[3] = { "Thread 1", "Thread 2", "Thread 3" }; //names of threads


  //create the threads
  id1 = SDL_CreateThread ( runner, tnames[0] );
  id2 = SDL_CreateThread ( runner, tnames[1] );
  id2 = SDL_CreateThread ( runner, tnames[2] );

  //wait for the threads to exit
  SDL_WaitThread ( id1, NULL );
  SDL_WaitThread ( id2, NULL );
  SDL_WaitThread ( id3, NULL );

  return 0;
}
