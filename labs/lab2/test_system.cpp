#include <stdlib.h>
#include <iostream>

using namespace std;

int main(){
	cout << "Running ps with system\n";
	system("ps -ax &");
	cout << "Done \n";
	return 0;
}
