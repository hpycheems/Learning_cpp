#include <iostream>
using namespace std;
#include <vector>

/*
empty();
capacity();
size();
resize(int num); ����Ԫ�صĴ�С
resize(int num, elem);
*/

void printVector3(vector<int> &v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
 	}
	cout << endl;
}

void test3_1() {
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	if (v1.empty()) {
		cout << "v1 Ϊ��" << endl;
	}
	else {
		cout << "v1 ��Ϊ��" << endl;
	}

	cout << "v1 ������" << v1.capacity() << endl;
	cout << "v1 �Ĵ�С" << v1.size() << endl;

	v1.resize(15,100);
	cout << "v1 ������" << v1.capacity() << endl;
	printVector3(v1);


}

int main3() {

	test3_1();

	system("pause");
	return 0;
}