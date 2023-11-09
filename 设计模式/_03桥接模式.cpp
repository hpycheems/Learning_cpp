#include <iostream>

/* �Ž�
*    ���ڰѳ�����ʵ�ֻ����ʹ�ö��߿��Զ����仯��
*	 �������͵����ģʽ���ڽṹ��ģʽ����ͨ���ṩ���󻯺�ʵ�ֻ�֮����Žӽṹ����ʵ�ֶ��ߵĽ��
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