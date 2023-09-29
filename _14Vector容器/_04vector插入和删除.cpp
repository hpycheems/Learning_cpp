#include <iostream>
using namespace std;
#include <vector>

/*
push_back(ele); 尾插
pop_back(); 尾删
insert(const_iteractor pos, ele);
insert(const_iteractor pos, int count, ele);
erase(const_iterator pos);  删除迭代器指向的数据
erase(const_iterator pos, const_iteractor end);
cles();
*/

void printVector4(vector<int> &v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test4_1() {
	vector<int> v1;
	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i);
	}
	//尾插
	v1.push_back(10);
	printVector4(v1);
	v1.pop_back();
	printVector4(v1);

	//inser插入
	v1.insert(v1.begin(), 100);
	printVector4(v1);
	v1.insert(v1.begin(), 2, 1000);
	printVector4(v1);

	//删除
	v1.erase(v1.begin());
	printVector4(v1);

	//清空
	v1.clear();
	printVector4(v1);

	v1.erase(v1.begin(), v1.end());
	printVector4(v1);

}

int main4() {

	test4_1();

	system("pause");
	return 0;
}