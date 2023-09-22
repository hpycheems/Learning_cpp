#include <iostream>
using namespace std;

class AbstrctDrinking {
public :
	virtual void Boil() = 0;

	virtual void Brew() = 0;
	
	virtual void PourInCup() = 0;

	virtual void PutSomthing() = 0;

	void makeDrink() {
		Boil();
		Brew();
		PourInCup();
		PutSomthing();
	}
};

class Coffe :public AbstrctDrinking {
public:
	void Boil() {
		cout << "�� �׿�ˮ" << endl;
	}

	void Brew() {
		cout << "���� ����" << endl;
	}

	void PourInCup() {
		cout << "���� ����" << endl;
	}

	void PutSomthing() {
		cout << "����ţ�̺���" << endl;
	}
};

class Tea :public AbstrctDrinking {
public:
	void Boil() {
		cout << "�� ��Ȫˮ" << endl;
	}

	void Brew() {
		cout << "���� ��Ҷ" << endl;
	}

	void PourInCup() {
		cout << "���� ����" << endl;
	}

	void PutSomthing() {
		cout << "�������" << endl;
	}
};

void doWork(AbstrctDrinking * abs) {
	abs->makeDrink();
	delete abs;
}

void test4_1() {
	doWork(new Coffe);

	cout << "_________" << endl;

	doWork(new Tea);
}

int main4() {

	test4_1();

	system("pause");
	return 0;
}