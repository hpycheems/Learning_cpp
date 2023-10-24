#include <iostream>
using namespace std;

//注意事项：
// 自动推导，必须推导出一致的数据类型，才可使用
template<class T>//typemane 可以替换成class 效果都一样
void Swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}
void test2_1() {
	int a = 10;
	int b = 20;
	char c = 'a';

	//Swap(a, b);//正确调用
	// Swap(a, c);//错误
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

}
// 模板必须要确定出T的数据类型，才可使用
template<class T>
void func() {
	cout << "func函数调用" << endl;
}
void test2_2() {
	func<char>();//必须指定模板类型
}


int main2() {

	//test2_1();
	test2_2();
	system("pause");
	return 0;
}