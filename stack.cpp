
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


Person & makePerson(std::string name, unsigned int age) {
	Person createdPerson(name, age);
	return createdPerson;
}

int & badFunc() {
	int anewint = 5;
	std::cout << &anewint << std::endl;
	return anewint;
}

int goodFunc() {
	int anotherInt = 10;
	int stackRoom[1000];
	std::cout << &stackRoom << std::endl;
	for (size_t i = 0; i < 1000; i++) {
		stackRoom[i] = 8;
	}
	return anotherInt;
}


int main() {

	//Person myPerson;
	//myPerson = makePerson("Mike", 21);
	//std::cout << myPerson.getName() << std::endl;
	//std::cout << myPerson.getAge();

	int &age = badFunc();
	std::cout << &age << std::endl;
	std::cout << age << std::endl;
	
	int myNewInt = goodFunc();
	std::cout << myNewInt << std::endl;
	std::cout << age << std::endl;

	return EXIT_SUCCESS;

}