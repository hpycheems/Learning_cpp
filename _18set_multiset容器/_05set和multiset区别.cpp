#include <iostream>
using namespace std;
#include <set>

//����
// set�����Բ����ظ����ݣ���multiset����
// set�������ݵ�ͬʱ�᷵�ز���������ʾ�����Ƿ�ɹ�
// multiset���������ݣ���˿��Բ����ظ�����


void test5_1() {
	set<int> s;
	//���ض��� 
	pair<set<int>::iterator, bool> res = s.insert(10);

	if (res.second) {
		cout << "��һ�β���ɹ�" << endl;
	}
	else {
		cout << "��һ�β��벻�ɹ�" << endl;
	}

	res = s.insert(10);
	if (res.second) {
		cout << "�ڶ��β���ɹ�" << endl;
	}
	else {
		cout << "�ڶ��β��벻�ɹ�" << endl;
	}

	multiset<int> ms;
	//��������ظ�Ԫ��
	ms.insert(10);
	//���ص����� ָ����������
	multiset<int> :: iterator res1 = ms.insert(10);
	cout << *res1 << endl;

	for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++)
	{
		cout << *it << " ";
	}cout << endl;
}

int main5() {
	test5_1();
	system("pause");
	return 0;
}