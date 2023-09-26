#include <iostream>
using namespace std;
#include <vector>

//vectorµÄ¸³Öµ²Ù×÷
/*
vector& operator=(const vector& v);
assign(beg,end);
assign(n,elem);
*/

void printVector1(vector<int> &v){
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test2_1() {
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	vector<int> v2 = v1;
	printVector1(v2);

	vector<int> v3;
	v3.assign(v2.begin(), v2.end());
	printVector1(v3);

	vector<int> v4;
	v4.assign(10, 100);
	printVector1(v4);
}

int main2() {

	test2_1();

	system("pause");
	return 0;
}