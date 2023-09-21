#include<iostream>
using namespace std;
#include<string>

//�Ӻ����������
class Person {
public :
	int m_A;
	int m_B;
	// ͨ����Ա�������� +��
	//Person operator+(const Person &p){
	//	Person temp;
	//	temp.m_A = m_A + p.m_A;
	//	temp.m_B = m_B + p.m_B;
	//	return temp;
	//}

	Person operator-(const Person& p) {
		Person temp;
		temp.m_A = m_A - p.m_A;
		temp.m_B = m_B - p.m_B;
		return temp;
	}

	void operator+=(const Person& p) {
		m_A += p.m_A;
		m_B += p.m_B;
	}
};

// ͨ��ȫ�ֺ������� +��
Person operator+(const Person& p1, const Person& p2) {
	Person temp;
	temp.m_A = p1.m_A + p2.m_A;
	temp.m_B = p1.m_B + p2.m_B;
	return temp;
}
//���������Ҳ���� ������������
Person operator+(const Person& p1, int num) {
	Person temp;
	temp.m_A = p1.m_A + num;
	temp.m_B = p1.m_B + num;
	return temp;
}

void test1_1() {
	Person p1,p2;
	p1.m_A = 10;
	p1.m_B = 20;

	p2.m_A = 30;
	p2.m_B = 40;

	//��Ա�������صı��ʵ��� Person p3 = p1.operator+(p2);
	//ȫ�ֺ������ر��ʵ��� Person p3 = operator+(p1,p2);
	Person p3 = p1 + p2;
	//���������Ҳ���� ������������
	Person p4 = p1 + 100;

	cout << "p_3��m_A = " << p3.m_A << endl;
	cout << "p_3��m_B = " << p3.m_B << endl;

	cout << "p_4��m_A = " << p4.m_A << endl;
	cout << "p_4��m_B = " << p4.m_B << endl;

	p1 += p2;
	cout << p1.m_A << endl;
	cout << p1.m_B << endl;
}
//�ܽ᣺�������õ��������͵ı��ʽ�������ǲ��ɷ����ı��
// ��Ҫ�������������
int main1() {
	test1_1();

	system("pause");
	return 0;
}