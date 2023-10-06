#include <iostream>
#include <string>

using namespace std;

//结构体 自定义的数据类型
// 1.创建学生数据类型
// 2.通过学生数据类型创建具体学生
struct student {
	//成员列表
	string name;
	int age;
	float score;
}s3;//创建结构体时创建结构体对象

//嵌套结构体
struct teacherr {
	string name;
	int id;
	int age;
	student student;
};

void printStudent(student student);
void printStudent(student* student);
void printStudent(const student* student);// 节省空间 防止修改
void printStudent1(const student student);
int main17() {
// 创建具体 struct 可以省略
	//struct Student s1 
	student s1;
	s1.age = 10;
	s1.name = "张三";
	s1.score = 100;

	cout << "姓名" << s1.name << endl;

	//struct Student s2 = {...}
	student s2 = { "李四", 20, 90 };
	cout << "姓名" << s2.name << endl;

	// 创建结构体时创建结构体对象
	s3.name = "王五";
	cout << "姓名" << s3.name << endl;

//结构体数组

	student students[2];
	students[0].name = "张三";
	students[1].name = "李四";
	cout << "姓名" << students[0].name << endl;
	cout << "姓名" << students[1].name << endl;


//结构体指针
	//通过指针访问结构体中的元素

	student* p = &s1;
	cout << " 指针访问结构体：" << (p->name) << endl;

	teacherr t;
	t.name = "老王";
	t.id = 0;
	t.age = 39;
	t.student = s1;
	cout << t.name << " 的学生：" << t.student.name << endl;

//作为参数
	//值传递
	printStudent(s1);
	//地址传递
	printStudent(&s1);
	cout << s1.name << endl;

// const

	student p1 = { "张三", 15, 100 };
	printStudent(p1);
	printStudent1(p1);


	system("pause");
	return 0;
}
void printStudent(student student) {
	cout << student.name << endl;
}
void printStudent(student* student) {
	cout << student->name << endl;
	student->name = "王五";
}
void printStudent1(const student student) {
	cout << student.name << endl;
}