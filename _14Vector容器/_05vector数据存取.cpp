#include <iostream>
using namespace std;
#include <vector>


/*
at(int idx); 
operator[]; index��ָ������
fornt(); ��һ��Ԫ��
back(); ���һ��Ԫ��
*/

void test5_1() {
	vector<int> v1;
	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i);
	}
	cout << v1.at(0) << endl;

	cout << v1[1] << endl;

	cout << v1.front() << endl;

	cout << v1.back() << endl;


}

int main5() {
	test5_1();
	system("pause");
	return 0;
}