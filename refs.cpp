/*
*	Taken from
*	https://www.programiz.com/cpp-programming/return-reference
*/
#include <iostream>
using namespace std;

// Global variable
int num;

// Function declaration
int& test();

int main()
{
	test() = 5;

	cout << num;

	return 0;
}

int& test()
{
	return num;
}