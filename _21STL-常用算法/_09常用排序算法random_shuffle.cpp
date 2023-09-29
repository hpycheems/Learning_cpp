#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>

/*
random_shuffle: 洗牌 指定范围内的元素随机调整次序
原型：
	random_shuffle(iterator beg, iterator end);
*/
void printFunc1(int val) {
	cout << val << " ";
}
void test9_1() {

	srand((unsigned int)time(NULL));

	vector<int >v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	random_shuffle(v.begin(), v.end());

	for_each(v.begin(), v.end(), printFunc1);
	cout << endl;
}

int main9() {
	test9_1();
	system("pause");
	return 0;
}