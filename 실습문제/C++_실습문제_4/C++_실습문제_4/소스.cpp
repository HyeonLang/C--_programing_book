#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Person {
	string name;
public:
	Person() {};
	Person(string name) { this->name = name; }
	string getName() { return name; }
};

class Family {
	Person* p;
	int size;
	string familyName;
public:
	Family(string name, int size);
	void setName(int n, string name);
	void show();
	~Family();
};

Family::Family(string name, int size) {
	this->familyName = name;
	this->size = size;
	this->p = new Person[size];
}

void Family::setName(int n, string name) {
	Person* ip = new Person(name);
	this->p[n] = *ip;
}

void Family::show() {
	cout << this->familyName << "은 다음과 같이 " << this->size << "명 입니다." << endl;
	for (int i = 0; i < size; i++) {
		cout << p[i].getName() << "   ";
	}
	cout << endl;
}

Family::~Family() {}

int main() {
	Family* simpson = new Family("Simpson", 3);
	simpson->setName(0, "Mr. Simpson");
	simpson->setName(1, "Mrs. Simpson");
	simpson->setName(2, "Bart Simpson");
	simpson->show();
	delete simpson;
}