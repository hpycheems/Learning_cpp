#include <iostream>
using namespace std;
#include <map>

/*
��飺 ��Ч�� ������
	map������Ԫ�ض���pair
	pair�е�һ��Ԫ��Ϊkey������ֵ�����������ã��ڶ���Ԫ��Ϊvalue��ʵֵ��
	����Ԫ�ض������Ԫ�صļ�ֵ�Զ�����
���ʣ�
	map\multimap���ڹ����������ײ�ṹ���ö�����ʵ��
�ŵ㣺
	���Ը���keyֵ�����ҵ�valueֵ
map��multimap����
	map���������������ظ�keyֵԪ��
	multimap�������������ظ�keyֵԪ��
*/

/*
map����͸�ֵ��
	
*/

void test1_1() {

	//Ĭ�Ϲ���
	map<int, int> m;

	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(4, 40));

	for (map<int,int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << " Value = " << (*it).second << endl;
	}
	cout << endl;

	//��������
	map<int, int> m2(m);
	for (map<int, int>::iterator it = m2.begin(); it != m2.end(); it++)
	{
		cout << "key = " << it->first << " Value = " << (*it).second << endl;
	}
	cout << endl;


	//��ֵ
	map<int, int> m3;
	m3 = m2;
	for (map<int, int>::iterator it = m3.begin(); it != m3.end(); it++)
	{
		cout << "key = " << it->first << " Value = " << (*it).second << endl;
	}
}

int main1() {

	test1_1();

	system("pause");
	return 0;
}