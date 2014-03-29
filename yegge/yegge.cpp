#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;

//Answers to Steve Yegge's 5 phone screen coding questions in C++

//Write a function to reverse a string
void rev(string & str){
	string str2(str);
	int i;
	const int len = str.length();
	for(i = 0; i < len; i++){
		str[i] = str2[len - 1 - i];
	}
}

long fib(long n){
	//compute the nth fibonacci number, iteratively
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	long a = 1;
	long b = 2;
	long tmp;
	long i;
	for (i = 3; i <= n; i++){
		tmp = b;
		b = a + b;
		a = tmp;
	}
	return b;
}

void tables(){
	//print out multiplication table up to 12*12
	int arr[12];
	int i, j;
	for(i = 0; i < 12; i++){
		for (j = 0; j < 12; j++){
			printf("%4d", (i+1)*(j+1));
		}
		printf("\n");
	}
}


int main(int argc, char** argv){
	string str = "my name is augie";
	rev(str);
	cout << "one:" << endl;
	cout << str << endl;
	cout << "fibonacci numbers: " << endl << fib(1) << endl << fib (2) << endl << fib(3) << endl << fib(4) << endl << fib(5) << endl << fib(6) << endl;
	tables();
}