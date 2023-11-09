#include <iostream>

class SubSystemA {
public:
	SubSystemA() {
		std::cout << "SunSystemA construct\n";
	}
	void operation() {
		std::cout << "SubSystem A methed\n";
	}
};
class SubSystemB {
public:
	SubSystemB() {
		std::cout << "SunSystemB construct\n";
	}
	
	void operation() {
		std::cout << "SubSystem B methed\n";
	}
};
class SubSystemC {
public:
	SubSystemC() {
		std::cout << "SunSystemC construct\n";
	}
	void operation() {
		std::cout << "SubSystem C methed\n";
	}
};

class Facade {
public:
	Facade() :_systemA(), _systemB(), _systemC(){}

	void operation1() {
		_systemA->operation();//这种调用是不用初始化对象的
		_systemC->operation();
	}
	void operation2() {
		_systemB->operation();
	}
private:
	SubSystemA* _systemA;
	SubSystemB* _systemB;
	SubSystemC* _systemC;
};

int main() {
	Facade* facade = new Facade();

	facade->operation1();
	facade->operation2();
	delete facade;
}