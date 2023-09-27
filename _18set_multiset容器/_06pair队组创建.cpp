#include <iostream>
using namespace std;
#include <set>

/* 
pair
成对出现的数据，利用队组可以返回两个数据

*/

void test6_1() {
	//方式一 创建对组
	pair<string, int> p("Tom", 20);
	cout << "姓名:" << p.first << "年龄:" << p.second << endl;

	//方式二 创建队组
	pair<string, int> p2 = make_pair("Jerry", 30);
	cout << "姓名:" << p2.first << "年龄:" << p2.second << endl;

}

int main6() {
	test6_1();
	system("pause");
	return 0;
}