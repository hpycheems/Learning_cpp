#include <iostream>
using namespace std;
//��̬��Ϊ���ࣺ
// ��̬��̬���������� �� ������������ھ�̬��̬�����ú�����
// ��̬��̬����������麯��ʵ������ʱ��̬
//����
// ��̬��̬�ĺ�����ַ��� - ����׶�ȷ��������ַ
// ��̬��̬�ĺ�����ַ��� - ���н׶�ȷ��������ַ

// �������ý��������������������֮�������ת����

//��̬��̬��������
// 1���м̳й�ϵ
// 2��������д������麯��

//����
// �����ָ������� ָ���������

//���� ͨ��������Ա������ʾ������֤
// vfptr v-virtual f-function prt-pointer �麯������ָ��
// vftable v-virtual f-function table �麯����
// ��������д������麯��
// �����е��麯�����ڲ����滻���������д������ַ

class Animal {
public :
	void speak() {
		cout << "���� ˵��" << endl;
	}
	virtual void Speak() {
		cout << "���� ˵��" << endl;
	}
};

class Cat :public Animal {
public :
	// ��д ������ֵ �������� �����б���ȫ��ͬ
	void speak() {
		this->Animal::speak();//Base::speck();
		cout << "è ˵��" << endl;
	}
	void Speak() {
		Animal::speak();
		cout << "è ˵��" << endl;
	}
};
class Dog :public Animal {
public:
	void Speak() {
		cout << "�� ˵��" << endl;
	}
};

void doSpeak(Animal &animal) {
	animal.Speak();
}

//��ַ��� �ڱ���׶�ȷ��������ַ
//�����ִ����è˵�������������ַ�Ͳ�����ǰ�󶨣���Ҫ�����н׶ΰ󶨣���ַ���
void test1_1() {
	Cat cat;
	doSpeak(cat);

	//Dog dog;
	//doSpeak(dog);
}

int main1() {
	test1_1();
	system("pause");
	return 0;
}