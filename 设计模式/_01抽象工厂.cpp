#include <iostream>

class ProductA {
public :
	virtual ~ProductA() {}//ÐéÎö¹¹º¯Êý
	virtual const char* getName() = 0;//´¿Ðéº¯Êý
};

class ConcreteProductAX : public ProductA {
public:
	const char* getName() {
		return "A - X";
	}

	void Func() {
		std::cout << "ConcreteProductAX self Function \n";
	}
};
class ConcreteProductAY :public ProductA {
public:
	const char* getName() {
		return "A - Y";
	}
};

class ProductB {
public:
	virtual ~ProductB() {}
	virtual const char* getName() = 0;
};

class ConcreteProductBX : public ProductB {
public:
	const char* getName() {
		return "B - X";
	}
};

class ConcreteProductBY : public ProductB {
public:
	const char* getName() {
		return "B - Y";
	}
};

class AbstructFactory {
public:
	virtual ~AbstructFactory() {}

	virtual ProductA* createProductA() = 0;
	virtual ProductB* createProductB() = 0;
};

class ConcreteFactoryX : public AbstructFactory {
public:
	ProductA* createProductA() {
		return new ConcreteProductAX();
	}
	ProductB* createProductB() {
		return new ConcreteProductBX();
	}
};
class ConcreteFactoryY : public AbstructFactory {
public:
	ProductA* createProductA() {
		return new ConcreteProductAY();
	}
	ProductB* createProductB() {
		return new ConcreteProductBY();
	}
};


int main1() {
	
	AbstructFactory* facotryX = new ConcreteFactoryX;

	ConcreteProductAX* ax = (ConcreteProductAX*)(facotryX->createProductA());
	std::cout << ax->getName() << std::endl;
	ax->Func();

	return 0;
}