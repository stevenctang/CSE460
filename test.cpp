#include <iostream>
#include <stdio.h>
#include <unistd.h>
using namespace std;

int main(){
	for (int i =0; i < 3; i++){
		fork();
		cout << i << endl;
	}	
return 0;
}
