#include <iostream>
#include <string>

using namespace std;

//�ṹ�� �Զ������������
// 1.����ѧ����������
// 2.ͨ��ѧ���������ʹ�������ѧ��
struct student {
	//��Ա�б�
	string name;
	int age;
	float score;
}s3;//�����ṹ��ʱ�����ṹ�����

//Ƕ�׽ṹ��
struct teacherr {
	string name;
	int id;
	int age;
	student student;
};

void printStudent(student student);
void printStudent(student* student);
void printStudent(const student* student);// ��ʡ�ռ� ��ֹ�޸�
void printStudent1(const student student);
int main17() {
// �������� struct ����ʡ��
	//struct Student s1 
	student s1;
	s1.age = 10;
	s1.name = "����";
	s1.score = 100;

	cout << "����" << s1.name << endl;

	//struct Student s2 = {...}
	student s2 = { "����", 20, 90 };
	cout << "����" << s2.name << endl;

	// �����ṹ��ʱ�����ṹ�����
	s3.name = "����";
	cout << "����" << s3.name << endl;

//�ṹ������

	student students[2];
	students[0].name = "����";
	students[1].name = "����";
	cout << "����" << students[0].name << endl;
	cout << "����" << students[1].name << endl;


//�ṹ��ָ��
	//ͨ��ָ����ʽṹ���е�Ԫ��

	student* p = &s1;
	cout << " ָ����ʽṹ�壺" << (p->name) << endl;

	teacherr t;
	t.name = "����";
	t.id = 0;
	t.age = 39;
	t.student = s1;
	cout << t.name << " ��ѧ����" << t.student.name << endl;

//��Ϊ����
	//ֵ����
	printStudent(s1);
	//��ַ����
	printStudent(&s1);
	cout << s1.name << endl;

// const

	student p1 = { "����", 15, 100 };
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
	student->name = "����";
}
void printStudent1(const student student) {
	cout << student.name << endl;
}