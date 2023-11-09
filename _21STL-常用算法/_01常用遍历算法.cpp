#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

/*
概念：
	算法主要是由头文件<algorithm> <functional> <numeric>组成
	<algorithm>是所有STL头文件中最大的一个，范围涉及 比较、交换、查找、遍历操作、复制、修改等等
	<numeric> 体积很小，只包括几个在序列上面进行简单数学的模板函数
	<functional>定义了一些模板类，用以声明函数对象
*/

/*
常用遍历算法：
	for_each(begin,end, func) //遍历容器
	transform（bef1,end1,beg2,_func） 搬运容器到另一个容器中

	beg1 源容器开始迭代器
	end1 源容器结束迭代器
	beg2 目标容器开始迭代器
	_func 函数或者函数对象

*/

//普通函数
void print1(int val) {
	cout << val << " ";
}
//仿函数
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
	vTarget.resize(v.size()); //必须预先设置容器大小

	//允许在搬运的时候对数据 进行一些操作
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