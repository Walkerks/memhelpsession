
#include <cstdlib>
#include <iostream>

int * createArray(const size_t size) {
	return new int[size];
}

int main() {

	const int arraySize = 10;
	//create an array of size 10
	int * myArray = createArray(arraySize);
	//located on the stack
	std::cout << "location of arraySize " << &arraySize << std::endl;
	//located on the stack
	std::cout << "location of myArrayPointer " << &myArray << std::endl;
	//located on the heap!
	std::cout << "location of the array myArray points to " << &(myArray[0]) << std::endl;
	

	delete[] myArray;
	myArray = nullptr;

	return EXIT_SUCCESS;

}