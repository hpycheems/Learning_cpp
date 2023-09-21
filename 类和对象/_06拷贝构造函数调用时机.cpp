#include <iostream>
using namespace std;
#include<string>

//拷贝构造函数调用时机
class MyClass {
public:
	MyClass() {
		cout << "MyClass 默认构造函数！" << endl;
	}
	MyClass(int age) {
		cout << "MyClass 有参构造函数！" << endl;
		m_Age = age;
	}
	MyClass(const MyClass& m) {
		cout << "MyClass 拷贝构造函数！" << endl;
		m_Age = m.m_Age;
	}
	~MyClass() {
		cout << "MyClass 析构构造函数！" << endl;
	}

private:
	int m_Age;
};
// 使用一个已经创建完毕的对象来初始化一个新对象
void func1() {
	MyClass m1(20);
	MyClass m2(m1);
}
 
// 值传递的方式给函数传值
void func2(MyClass m) {

}

MyClass doWork() {
	MyClass m;
	cout << (int)&m << endl;
	return m;
}

// 以值方式返回局部对象
void func3() {
	MyClass m = doWork();//编译器自动优化 这种情况下不会触发拷贝构造函数
	//m = doWork();
	cout << (int)&m << endl;
}

int main6() {

	//func1();

	//MyClass m(30);
	//func2(m);

	func3();

	system("pause");
	return 0;
}