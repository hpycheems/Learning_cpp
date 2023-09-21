#include <iostream>
using namespace std;
#include<string>
const double PI = 3.14;
//C++面向对象的三大特征：封装、继承、多态
/* 
  封装
	意义：
	将属性和行为作为一个整体，表现生活中的事物
	将属性和行为加以权限控制
	在设计类时，属性和行为写在一起，表现事物
	class 类名{访问权限：属性/行为};
	意义二：
	在类设计时，可以把属性和行为放在不同的权限下，加以控制
	访问权限有三种：
		1 public 公共		成员 在类内可访问，类外也可访问
		2 protected 保护		成员 类内可以访问，类外不可访问 子类也可访问父类保护内容
		3 private 私有		成员 类内可以访问，类外不可访问 子类也不可访问
*/
class Circle 
{
public://公共权限
	float m_r;
	double calculateZC() {
		return 2 * PI * m_r;
	}
};


class Student {
public:
	string name;
	int number;
	Student(string name, int number) :name(name), number(number) {}
	void showStudent() {
		cout << "学生姓名：" << name << endl;
		cout << "学生学号：" << number << endl;
	}
	void setName(string name) {
		this->name = name;
	}
	void setNumber(int number) {
		this->number = number;
	}
};

class Person {
public:
	string m_Name;
	void fun() {
		m_Name = "zs";
		m_Car = "bm";
		m_Password = 123;
	}
protected:
	string m_Car;

private:
	int m_Password;
};
//struct 和 class 的区别
// struct 默认权限是 public
// class 默认权限是 private
class C1 {
	int m_A;
};
struct S1 {
	int m_A;
};

//成员属性的私有化
// 可以自己控制读写权限
// 对于写可以检测数据的有效性
class Person1 {
private:
	string m_Name;
	int m_Age;
	string m_Lover;
public:
	void set_Name(string name) {
		m_Name = name;
	}
	string get_Name() {
		return m_Name;
	}
	void set_Age(int age) {
		if (age > 0 && age < 150) {
			m_Age = age;
		}
		else {
			m_Age = 0;
			cout << "年龄输入有误！" << endl;
		}
	}
	int get_Age() {
		return m_Age;
	}
	string set_Lover(string lover){
		m_Lover = lover;
	}
};

int main1() {
	//通过圆类 创建具体的圆（对象）
	Circle c1;
	c1.m_r = 2;
	cout << "圆的周长：" << c1.calculateZC() << endl;
	cout << "===============" << endl;
	Student s1("张三",1001);
	s1.showStudent();

	Person p1;
	p1.m_Name = "ls";
	//p1.m_Car = "tlj";
	//p1.m_Password = 321;

	C1 c3;
	//c1.m_A = 10;

	S1 c2;
	c2.m_A = 10;

	cout << "==============" << endl;
	Person1 person1;
	person1.set_Name("张三");
	person1.set_Age(200);

	cout << person1.get_Name() << endl;
	cout << person1.get_Age() << endl;

	//cout << person1.m_Lover << endl;

	system("pause");
	return 0;
}