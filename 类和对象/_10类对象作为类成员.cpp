#include <iostream>
using namespace std;
#include<string>
//�������Ϊ���Ա

class Phone {
public :
	string m_PName;
	Phone(string pName):m_PName(pName){
		cout << "Phone �Ĺ��캯��" << endl;
	}
};
class Person_3 {
public:
	string m_Name;
	Phone m_Phone;
	// m_Phone(pName) �൱�� Phone m_Phone = pName ��ʽת����
	Person_3(string name,string pName):m_Name(name),m_Phone(pName){
		cout << "Person_3 �Ĺ��캯��" << endl;
	}
};
// �������������Ϊ�����Ա������ʱ���ȹ���������ٹ�������
// ����˳���෴
void test_3() {
	Person_3 p("����", "IOS");
}

int main10() {
	test_3();
	system("pause");
	return 0;
}