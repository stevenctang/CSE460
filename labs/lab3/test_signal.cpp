//test_signal.cpp MODIFIED
#include <signal.h>
#include <unistd.h>
#include <iostream>

using namespace std;

void quit_sig (int sig) {
    exit(1);
}

void func ( int sig )
{
  cout << "Oops! -- I got a signal " << sig << endl;
}

int main()
{
    
    struct sigaction sa;
    sa.sa_handler = func;
    sigemptyset(&sa.sa_mask);
    sigaction (SIGINT, &sa, NULL);
    signal (SIGQUIT, quit_sig);
    while (1) {
    cout << "CSUSB CS 460 lab on signals" << endl;
    sleep ( 1 );
  }

}