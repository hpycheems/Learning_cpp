#include <iostream>
using namespace std;
#include <set>

//��飺 ����Ԫ�ض����ڲ���ʱ�Զ�������
//���ʣ�set/multiset���ڹ���ʽ�������ײ�ṹ���ö�����ʵ��

//set��multiset����
// set���������������ظ���Ԫ��
// multiset�������������ظ���Ԫ��

//���캯��

void printSet1(const set<int>& s) {
	for (set<int>::const_iterator it = s.begin(); it !=s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test1_1() {

	set<int> s;
	s.insert(10);
	s.insert(40);
	s.insert(30);
	s.insert(20);
	s.insert(30);

	printSet1(s);

	set<int> s1(s);
	printSet1(s1);

	set<int> s3;
	s3 = s1;
	printSet1(s3);
}

int main1() {
	test1_1();
	system("pause");
	return 0;
}