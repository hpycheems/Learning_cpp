#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

/*
���
	�㷨��Ҫ����ͷ�ļ�<algorithm> <functional> <numeric>���
	<algorithm>������STLͷ�ļ�������һ������Χ�漰 �Ƚϡ����������ҡ��������������ơ��޸ĵȵ�
	<numeric> �����С��ֻ��������������������м���ѧ��ģ�庯��
	<functional>������һЩģ���࣬����������������
*/

/*
���ñ����㷨��
	for_each(begin,end, func) //��������
	transform��bef1,end1,beg2,_func�� ������������һ��������

	beg1 Դ������ʼ������
	end1 Դ��������������
	beg2 Ŀ��������ʼ������
	_func �������ߺ�������

*/

//��ͨ����
void print1(int val) {
	cout << val << " ";
}
//�º���
class print2 {
public:
	void operator()(int val) {
		cout << val << " ";
	}
};

void test1_1() {
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	for_each(v.begin(), v.end(), print1);
	cout << endl;

	for_each(v.begin(), v.end(), print2());
	cout << endl;
}


class Transfomr {

public:
	int operator()(int val) {
		return val + 1000;
	}
};

//Transform
void test1_2() {

	vector<int> v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int> vTarget;
	vTarget.resize(v.size()); //����Ԥ������������С

	//�����ڰ��˵�ʱ������� ����һЩ����
	transform(v.begin(), v.end(), vTarget.begin(), Transfomr());

	for_each(vTarget.begin(), vTarget.end(), print1);
	cout << endl;
}

int main1() {

	//test1_1();
	test1_2();

	auto number = Transfomr()(10);

	system("pause");
	return 0;
}