#include <iostream>
using namespace std;
#include <string>
//���μ̳и��
// ����������̳�ͬһ������
// ����һ����ͬʱ�̳�����������
// ���ּ̳б���Ϊ���μ̳У�����ʯ�̳�

// ������̳���������μ̳е�����


// vbptr v- virtual b-base prt - pointer �����ָ�� ָ�� vbtable��������

// ���μ̳д�������Ҫ����������̳�������ͬ�����ݣ�����������Դ�˷��Լ���������
// ������̳п��Խ�����μ̳�����
class Animal{
public :
	int m_Age;
};

class Sheep:virtual public Animal {

};
class Tuo : virtual public Animal{

};

class SheepTuo : public Sheep, public Tuo {

};

void test8_1() {

	SheepTuo st;
	st.Sheep::m_Age = 18;
	st.Tuo::m_Age = 28;

	cout << "st.Sheep::m_Age =" << st.Sheep::m_Age << endl;
	cout << "st.Sheep::m_Age =" << st.Tuo::m_Age << endl;
	cout << "st.m_Age =" << st.m_Age << endl;
}

int main8() {
	test8_1();
	system("pause");
	return 0;
}