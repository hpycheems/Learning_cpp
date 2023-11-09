#include <iostream>

/* ������ģʽ
*	��Ϊ���������ݵĽӿ�֮����������������͵����ģʽ���ڽṹ��ģʽ������������������ӿڵĹ��ܡ�
*/

#pragma region Class
class Target {//Ŀ��ӿ�
public:
	virtual ~Target() {}
	virtual void request() = 0;
};

class Addeptee {//����ӿ�
public:
	~Addeptee() {}

	void specificRequest() {
		std::cout << "specific Request\n";
	}
};

class Addepter1 :public Target, public Addeptee {//������
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