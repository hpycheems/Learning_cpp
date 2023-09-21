#include <iostream>
using namespace std;
#include <string>
//从父类继承过来的成员，哪些属于子类对象中？
// 父类中所有的非静态成员属性都会被子类继承下去
// 父类中私有成员属性 是被编译器给隐藏了， 因此访问不到，但是确实被继承下去了

// 利用开发人员命令提示工具(Developer Command Prompt for vs)查看对象模型
// 查看命令
// cl /d1 reportSingleClassLayout类名 文件名

class Base {
public :
	int m_A;
protected:
	int m_B;
private :
	int m_C;
};

class Sum :public Base {
	int m_D;
};

void test3_1() {

	cout << "size of =" << sizeof(Sum) << endl;
}

int main3() {
	test3_1();
	system("pause");
	return 0;
}