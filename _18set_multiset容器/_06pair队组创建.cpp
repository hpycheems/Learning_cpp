#include <iostream>
using namespace std;
#include <set>

/* 
pair
�ɶԳ��ֵ����ݣ����ö�����Է�����������

*/

void test6_1() {
	//��ʽһ ��������
	pair<string, int> p("Tom", 20);
	cout << "����:" << p.first << "����:" << p.second << endl;

	//��ʽ�� ��������
	pair<string, int> p2 = make_pair("Jerry", 30);
	cout << "����:" << p2.first << "����:" << p2.second << endl;

}

int main6() {
	test6_1();
	system("pause");
	return 0;
}