#include <iostream>
using namespace std;
#include <queue>

//Queue��һ���Ƚ��ȳ������ݽṹ������������
//�������������һ���������ݣ���һ���Ƴ�����
//ֻ�ж�ͷ�Ͷ�β�ܱ�������
//�������б�����Ϊ

//��� push ��β
//���� pop ��ͷ

/*
���캯����
queue<T> que;
queue(const queue &que);
��ֵ������
queue& operator=(const queue & que);
���ݴ�ȡ��
push(elem) �Ӷ�β���
pop() �Ӷ�ͷɾ��
back()���һ��
front()��һ��
��С������
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
	Person p1("����",30);
	Person p2("����", 23);
	Person p3("����", 38);
	Person p4("���", 40);

	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);

	cout << q.size() << endl;

	while (!q.empty()) {
		cout << "��ͷ����" << q.front().m_Name << " " << q.front().m_Age << endl;
		cout << "��β����" << q.back().m_Name << " " << q.back().m_Age << endl;
		q.pop();
	}
	cout << q.size() << endl;
}

int main() {
	test2_1();
	system("pause");
	return 0;	
}
