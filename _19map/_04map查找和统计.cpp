#include <iostream>
using namespace std;
#include <map>

/*
find(key) ����key�Ƿ���ڣ������ڣ����ظü���Ԫ�ص��������������ڣ�����map
count(key) ͳ��keyԪ�ظ���
*/

void test4_1() {

	map<int, int> m;
	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));

	//����
	map<int, int>::iterator pos = m.find(2);
	if (pos != m.end()) {
		cout << "���ҵ�Ԫ��:" << pos->second << endl;
	}
	else {
		cout << "δ�ܲ��ҵ�Ԫ��" << endl;
	}

	//ͳ��
	int num = m.count(2);
	cout << "key Ϊ2��Ԫ���У�" << num << endl;


}

int main4() {

	test4_1();
	system("pause");
	return 0;
}