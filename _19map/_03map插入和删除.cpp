#include <iostream>
using namespace std;
#include <map>

/*
insert(elem) �������в���Ԫ��
clear���� �������Ԫ��
erase��pos�� ���pos��������ָ���Ԫ�أ�������һ��Ԫ�صĵ�����
erase(beg,end) ��������е�����Ԫ�أ�������һ��Ԫ�صĵ�����
erase(key) ɾ��������ֵΪkey��Ԫ��
*/
void printMap2(map<int, int>& m) {
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << " Key = " << it->first << " Value = " << it->second << endl;;
	}
	cout << endl;
}
void test3_1() {
	map<int, int> m;
	//����

	//��ʽһ
	m.insert(pair<int, int>(1, 10));
	//��ʽ��
	m.insert(make_pair(2, 20));
	//��ʽ��
	m.insert(map<int, int>::value_type(3, 30));
	//��ʽ�� ���Ƽ�ʹ�������� ������������ �����key�����ڣ�����Զ������key����ʼ��value
	m[4] = 40;
	printMap2(m);

	//ɾ��
	m.erase(m.begin());
	printMap2(m);

	m.erase(3);
	printMap2(m);

	//���
	//m.erase(m.begin(), m.end());
	m.clear();
	printMap2(m);
}

int main3() {
	test3_1();

	system("pause");
	return 0;
}