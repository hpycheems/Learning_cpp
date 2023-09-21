#include <iostream>
using namespace std;
#include<string>
//1 构造函数的分类及调用
// 分类 
// 按照参数分类 有参 无参（默认构造） 
// 按照类型分类 普通构造函数 拷贝构造函数

class Pen {
public:
	int m_Age;
	//构造函数
	Pen() {
		cout << "Pen 的无参构造函数" << endl;
	}
	Pen(int a) {
		m_Age = a;
		cout << "Pen 的有参构造函数" << endl;
	}
	// 拷贝构造函数
	Pen(const Pen& p) {
		m_Age = p.m_Age;
		cout << "Pen 的拷贝造函数" << endl;
	}

	~Pen() {
		cout << "Pen 的析构函数" << endl;
	}
};
//调用
void test02() {
	//括号法 注意：调用默认构造不需要加（） 编译器会认为是一个函数声明，不会认为在创建对象
	//Pen p1; //默认构造函数调用
	//Pen p2(10);
	//Pen p3(p2);

	//显示法
	Pen p4;
	Pen p5 = Pen(10);
	Pen p6 = Pen(p5);
	Pen(20);// 匿名对象 特点：当前行执行结束后，系统会立即回收匿名对象
	//不要利用拷贝构造函数初始化匿名对象
	//Pen(p5);// 编译器认为 Pen（p5） === Pen p5;对象声明

	//隐式转换法
	//Pen p7 = 10; //Pen p7 = Pen(10);
	//Pen p8 = p5; //Pen p8 = Pen(p5);

}

int main5() {

	test02();

	system("pause");
	return 0;
}