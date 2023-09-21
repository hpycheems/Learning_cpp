#include <iostream>
using namespace std;
#include <string>
//继承是面向对象三大特性之一
// 继承的好处：减少重复代码
// 语法： class 子类：继承方式 父类
// class A：public B
// A类（子类、派生类） B类（父类、基类）

class BasePage {
public:
	void header() {
		cout << "首页：公开课、登录、注册。。。。" << endl;
	}
	void footer() {
		cout << "帮助中心。。。" << endl;
	}

	void left() {
		cout << "Java、Php" << endl;
	}
};

class Java :public BasePage {

public:
	void content() {
		cout << "Java学习视频！" << endl;
	}

};
class CPP :public BasePage {

public:
	void content() {
		cout << "C++学习视频！" << endl;
	}

};
class PHP :public BasePage {

public:
	void content() {
		cout << "Php学习视频！" << endl;
	}

};

void test1_1() {
	cout << "===================JAVA===================" << endl;
	Java ja;
	ja.header();
	ja.footer();
	ja.left();
	ja.content();

	cout << "===================C++===================" << endl;
	CPP cpp;
	cpp.header();
	cpp.footer();
	cpp.left();
	cpp.content();

	cout << "===================PHP===================" << endl;
	PHP php;
	php.header();
	php.footer();
	php.left();
	php.content();

}


int main1() {

	test1_1();


	system("pause");
	return 0;
}