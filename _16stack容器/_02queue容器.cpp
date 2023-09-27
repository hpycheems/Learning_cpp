#include <iostream>
using namespace std;
#include <queue>

//Queue是一种先进先出的数据结构，有两个出口
//队列容器允许从一端新增数据，另一端移除数据
//只有队头和队尾能被外界访问
//不允许有遍历行为

//入队 push 队尾
//出队 pop 对头

/*
构造函数：
queue<T> que;
queue(const queue &que);
赋值操作：
queue& operator=(const queue & que);
数据存取：
push(elem) 从队尾添加
pop() 从队头删除
back()最后一个
front()第一个
大小操作：
empty()
size()
*/

class Person {
public:

	Person(string name, int age) :m_Age(age),m_Name(name){}
	string m_Name;
	int m_Age;
};
void test2_1() {
	queue<Person> q;
	Person p1("卧龙",30);
	Person p2("赵云", 23);
	Person p3("关羽", 38);
	Person p4("凤雏", 40);

	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);

	cout << q.size() << endl;

	while (!q.empty()) {
		cout << "队头——" << q.front().m_Name << " " << q.front().m_Age << endl;
		cout << "队尾——" << q.back().m_Name << " " << q.back().m_Age << endl;
		q.pop();
	}
	cout << q.size() << endl;
}

int main() {
	test2_1();
	system("pause");
	return 0;	
}
