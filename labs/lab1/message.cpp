#include <iostream>
#include "function.h"

using namespace std;

void displayMessage(){
    string message;
    getline(cin,message);
    cout << "\n" << message;
}