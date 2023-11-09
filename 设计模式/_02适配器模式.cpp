#include <iostream>

/* 适配器模式
*	作为两个不兼容的接口之间的桥梁。这种类型的设计模式属于结构型模式，它结合了两个独立接口的功能。
*/

#pragma region Class
class Target {//目标接口
public:
	virtual ~Target() {}
	virtual void request() = 0;
};

class Addeptee {//适配接口
public:
	~Addeptee() {}

	void specificRequest() {
		std::cout << "specific Request\n";
	}
};

class Addepter1 :public Target, public Addeptee {//适配器
public:
	virtual void request() {
		specificRequest();
	}
};
#pragma endregion

#pragma region Object
class Addepter2 : public Target {
public:
	Addepter2():_addeptee(){}

	~Addepter2() {
		delete _addeptee;
	}

	void request() {
		_addeptee->specificRequest();
	}

private:
	Addeptee* _addeptee;
};
#pragma endregion



int main2() {

	Target* t = new Addepter1();
	t->request();
	delete t;

	Target* t1 = new Addepter2();
	t1->request();
	delete t1;

	return 0;
}