#include <iostream>
using namespace std;

class Base {
public:
	Base() { cout << "this is base class Construct" << endl;  }
	virtual void fun() = 0;
};

class Sun :public Base {
public:
	void fun(){
		cout << "this is sun calss " << endl;
	}
	Sun() {
		cout << "this is sun class Construct";
	}
};

int main(){


	Sun* s = new Sun;

	system("pause");
	return 0;
}