#include <iostream>
#include <string>
#include <ctime>

using namespace std;

// �� �ڱ��cpp�ļ������Ҳ������ strcut ��û������ڴ�ʱ����ʧ��
struct student {
	int score = 0;
	string sName = "\0";
};

struct teacherr {
	string tName = "\0";
	student sArray[5];
};

struct Hero {
	string name;
	int age;
	string sex;
};

void InitTeacher(teacherr tArray[], int len) {
	string nameSeed = "ABCDE";
	for (int i = 0; i < len; i++)
	{
		tArray[i].tName = "Teacher_";
		tArray[i].tName += nameSeed[i];
		for (int j = 0; j < 5; j++)
		{
			int ranmod = rand() % 61 + 40;
			tArray[i].sArray[j].score = ranmod;
			tArray[i].sArray[j].sName = "student_";
			tArray[i].sArray[j].sName += nameSeed[j];
		}
	}
}
void printInfo(teacherr tArray[], int len) {
	for (int i = 0; i < len; i++)
	{
		cout << "��ʦ������ " << tArray[i].tName << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << "\tѧ������: "<<tArray[i].sArray[j].sName 
				<< " �ɼ���"<< tArray[i].sArray[j].score << endl;
		}
	}
}

int main18() {
	
	srand((unsigned int)time(NULL));

	//��λ��ʦ
	//teacherr teachers[3];
	//int len = sizeof(teachers) / sizeof(teachers[0]);

	//InitTeacher(teachers, len);
	//printInfo(teachers, len);

	Hero heroArray[5] = {
		{"����",23,"��"},
		{"����",22,"��"},
		{"�ŷ�",20,"��"},
		{"����",21,"��"},
		{"����",18,"Ů"}
	};
	int len = sizeof(heroArray) / sizeof(heroArray[0]);
	cout << "����ǰ��" << endl;
	for (int i = 0; i < len; i++)
	{
		cout << "������" << heroArray[i].name
			 << " ���䣺" << heroArray[i].age
			 << " �Ա�: " << heroArray[i].sex << endl;
	}

	bool hasChange = false;
	for (int i = 0; i < len; i++)
	{
		hasChange = false;
		for (int j = len - 2; j >= 0; j--)
		{
			if (heroArray[j].age > heroArray[j + 1].age) {
				Hero temp = heroArray[j];
				heroArray[j] = heroArray[j + 1];
				heroArray[j + 1] = temp;
				hasChange = true;
			}
		}
		if (!hasChange)
			break;
	}
	cout << "�����" << endl;
	for (int i = 0; i < len; i++)
	{
		cout << "������" << heroArray[i].name
			<< " ���䣺" << heroArray[i].age
			<< " �Ա�: " << heroArray[i].sex << endl;
	}

	system("pause");
	return 0;
}