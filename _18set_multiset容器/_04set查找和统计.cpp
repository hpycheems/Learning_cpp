#include <iostream>
using namespace std;
#include <set>

/*
find(key) ����key�Ƿ���ڣ������ڷ��ظü���Ԫ�صĵ��������������ڣ�����set.end()
count(key) ͳ��key��Ԫ�ظ���
*/

//����
void test4_1() {
	set<int> s;
	s.insert(10);
	s.insert(20);
	s.insert(30);
	s.insert(40);

	set<int>::iterator pos = s.find(30);
	if (pos != s.end()) {

		cout << "���ҵ�Ԫ��" << *pos << endl;
	}
	else {
		cout << "δ���ҵ�Ԫ��" << endl;
	}
}
//ͳ��
void test4_2() {
	set<int> s;
	s.insert(10);
	s.insert(20);
	s.insert(30);
	s.insert(40);

	int count = s.count(30); //setͳ�� ����ֵΪ 0 ��1
	cout << count << endl;
}

int main4() {
	test4_2();

	system("pause");
	return 0;
}