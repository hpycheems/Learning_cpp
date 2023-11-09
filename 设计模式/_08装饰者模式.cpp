#include <iostream>

class Component {
public:
	virtual ~Component() {}

	virtual void operation() = 0;
};

class ConcreteComponent :public Component {
public:
	virtual ~ConcreteComponent() {}
	void operation() {
		std::cout << "Concrete Component operation" << std::endl;
	}
};

class Decorator:public Component {
public:
	virtual ~Decorator() {}

	Decorator(Component* component) :_component{component}{}
	virtual void operation() {
		_component->operation();
	}
private:
	Component* _component;
};

class ConcreteDecoratorA :public Decorator {
public:
	virtual ~ConcreteDecoratorA() {}
	ConcreteDecoratorA(Component* component) :Decorator(component) {}
	void operation() {
		Decorator::operation();
		std::cout << "Decorator A \n";
	}
};

class ConcreteDecoratorB :public Decorator {
public:
	virtual ~ConcreteDecoratorB() {}
	ConcreteDecoratorB(Component* component) :Decorator(component) {}
	void operation() {
		Decorator::operation();
		std::cout << "Decorator B \n";
	}
};

int main8() {

	Component* cc = new ConcreteComponent;
	Decorator* db = new ConcreteDecoratorA(cc);
	Decorator* da = new ConcreteDecoratorB(db);

	da->operation();

	delete cc;
	delete db;
	delete da;

	return 0;
}