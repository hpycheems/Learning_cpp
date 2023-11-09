#include <iostream>

/* 桥接
*    用于把抽象化与实现化解耦，使得二者可以独立变化。
*	 这种类型的设计模式属于结构型模式，它通过提供抽象化和实现化之间的桥接结构，来实现二者的解耦。
*/

class Implementor {
public:
	virtual ~Implementor() {}

	virtual void action() = 0;
};

class ConcreteImplementorA :public Implementor {
public:
	~ConcreteImplementorA() {}
	void action() {
		std::cout << "Concrete Implementor A\n";
	}
};

class ConcreteImplementorB :public Implementor {
public:
	~ConcreteImplementorB() {}

	void action() {
		std::cout << "Concrete Implemetor B\n";
	}
};

class AbstructAction {
public:
	virtual ~AbstructAction() {}

	virtual void operation() = 0;
};

class RefinedAbstructAction : public AbstructAction {
public:
	RefinedAbstructAction(Implementor* implementor) :_implementor(implementor){}
	~RefinedAbstructAction() {}

	void operation() {
		_implementor->action();
	}

private:
	Implementor* _implementor;
};

int main3() {

	Implementor* ia = new ConcreteImplementorA;
	Implementor* ib = new ConcreteImplementorB;

	AbstructAction* abstruct1 = new RefinedAbstructAction(ia);
	abstruct1->operation();

	AbstructAction* abstruct2 = new RefinedAbstructAction(ib);
	abstruct2->operation();

	delete ia;
	delete ib;

	delete abstruct1;
	delete abstruct2;

	return 0;
}