#include <iostream>
using namespace std;
// ��̬ʹ�õ�ʱ����������������Կ��ٵ��ѣ���ô����ָ�����ͷ�ʱ�޷����õ��������������

// ����ָ��������ʱ�� �����������������������������������ж������ԣ������ڴ�й¶

// �����ʽ���������е�����������Ϊ��������������

// ǰ�᣺ ����ָ��ָ���������

//�������ʹ�����������
// ���Խ������ָ���ͷ��������
// ����Ҫ�о���ĺ���ʵ��

//�������ʹ�����������
// ����Ǵ����������������ڳ����࣬�޷�ʵ��������
// 
// �������� ��Ҫ����Ҳ��Ҫʵ��

class Animal1
{
public :
	Animal1() {
		cout << " Animal �Ĺ������" << endl;
	}

	//������
	//virtual ~Animal1() {
	//	cout << " Animal ����������" << endl;
	//}
	
	//��������
	virtual ~Animal1() = 0;

	// ���麯��
	virtual void speak() = 0;

};
// �������� ��Ҫ���� Ҳ��Ҫʵ��
Animal1::~Animal1() {
	cout << " Animal �Ĵ�����������" << endl;
}


class Cat1 :public Animal1{
public:
	Cat1(string name) {
		m_Name = new string(name);
		cout << "Cat ���캯������ " << endl;
	}
	void speak() {
		cout << *m_Name << "è��˵��" << endl;
	}

	~Cat1() {
		if (m_Name != NULL) {
			delete m_Name;
			m_Name = NULL;
		}
		cout << "Cat ����������" << endl;
	}

	string* m_Name;
};

void test5_1() {
	Animal1* c = new Cat1("Tom");

	c->speak();
	delete c;
}


int main5() {

	test5_1();

	system("pause");
	return 0;
}