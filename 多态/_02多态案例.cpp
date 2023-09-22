#include <iostream>
using namespace std;
//��̬���ŵ㣺
// ������֯�ṹ����
// �ɶ���ǿ
// ����ǰ�ںͺ��ڵ���չ�Լ�ά��

class AbstractCalculater {
public:
	virtual int getResult() {
		return 0;
	}

	int m_Num1;
	int m_Num2;
};

class AddCalculater :public AbstractCalculater {
public:
	int getResult() {
		return m_Num1 + m_Num2;
	}
};

class SubCalculater :public AbstractCalculater {
public:
	int getResult() {
		return m_Num1 - m_Num2;
	}
};

class MulCalculater :public AbstractCalculater {
public:
	int getResult() {
		return m_Num1 * m_Num2;
	}
};

void test2_1() {
	AbstractCalculater* abs;
	abs = new AddCalculater;
	abs->m_Num1 = 100;
	abs->m_Num2 = 100;

	cout << abs->m_Num1 << "+" << abs->m_Num2 << "=" << abs->getResult() << endl;

	delete abs;

	abs = new SubCalculater;
	abs->m_Num1 = 100;
	abs->m_Num2 = 100;

	cout << abs->m_Num1 << "-" << abs->m_Num2 << "=" << abs->getResult() << endl;
	delete abs;

	abs = new MulCalculater;
	abs->m_Num1 = 100;
	abs->m_Num2 = 100;

	cout << abs->m_Num1 << "*" << abs->m_Num2 << "=" << abs->getResult() << endl;

}

int main2() {

	test2_1();

	system("pause");
	return 0;
}