
#include <cstdlib>
#include <string>
#include <iostream>

class Person{
public:
	Person() {
		name = "";
		age = 0;
	}
	Person(std::string & name, unsigned int age) {
		this->name = name;
		this->age = age;
	}
	std::string getName() {
		return name;
	}

	unsigned int getAge() {
		return age;
	}

private:
	std::string name;
	unsigned int age;
};


Person * makePerson(std::string name, unsigned int age) {
	Person createdPerson(name, age);
	return &createdPerson;
}


//
int & badFunc() {
	//create a locally scoped variable
	int anewint = 5;
	//show it's address
	std::cout << "location of anewint " << &anewint << std::endl;
	//return the variable by reference
	return anewint;
}

//How not to allocate memory for an array
int * badArrayUse() {
	int myarray[10];
	//int * mymyarray = new int[10];
	for (size_t i = 0; i < 10; i++) {
		myarray[i] = 3;
		std::cout << "Setting the memory address " << &myarray[i] << " with value " << myarray[i]  << std::endl;
		
	}
	return myarray;
}

int goodFunc() {
	int anotherInt = 10;
	//For some reason this function takes up a fair share of stack
	int stackRoom[1000];
	for (size_t i = 0; i < 1000; i++) {
		stackRoom[i] = 8;
	}
	return anotherInt;
}


int main() {

	Person * myPerson = makePerson("Mike", 21);
	//Already doesn't work
	//std::cout << myPerson->getName() << std::endl;
	std::cout << "age:" << myPerson->getAge()  << std::endl;

	int * myArray = badArrayUse();
	std::cout << std::endl;
	for (size_t i = 0; i < 10; i++) {
		std::cout << "Reading the memory address " << &myArray[i] << " has value of " << myArray[i] << std::endl;
	}


	int & badInt = badFunc();
	std::cout << "Value of badInt " << badInt << std::endl;
	std::cout << "Location of badInt " << &badInt << std::endl;
	
	int myNewInt = goodFunc();
	std::cout << "Value of myNewInt " << badInt << std::endl;

	//What's in badInt now?
	std::cout << "Value of badInt " << badInt << std::endl;


	//Lets look at Mikes age again

	std::cout << "age:" << myPerson->getAge() << std::endl;

	return EXIT_SUCCESS;

}
