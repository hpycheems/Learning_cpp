#include <iostream>
#include <string>
#include <ctime>

using namespace std;

// 坑 在别的cpp文件中如果也声明了 strcut 当没有清除内存时访问失败
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
		cout << "老师姓名： " << tArray[i].tName << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << "\t学生姓名: "<<tArray[i].sArray[j].sName 
				<< " 成绩："<< tArray[i].sArray[j].score << endl;
		}
	}
}

int main18() {
	
	srand((unsigned int)time(NULL));

	//三位老师
	//teacherr teachers[3];
	//int len = sizeof(teachers) / sizeof(teachers[0]);

	//InitTeacher(teachers, len);
	//printInfo(teachers, len);

	Hero heroArray[5] = {
		{"刘备",23,"男"},
		{"关羽",22,"男"},
		{"张飞",20,"男"},
		{"赵云",21,"男"},
		{"貂蝉",18,"女"}
	};
	int len = sizeof(heroArray) / sizeof(heroArray[0]);
	cout << "排序前：" << endl;
	for (int i = 0; i < len; i++)
	{
		cout << "姓名：" << heroArray[i].name
			 << " 年龄：" << heroArray[i].age
			 << " 性别: " << heroArray[i].sex << endl;
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
	cout << "排序后：" << endl;
	for (int i = 0; i < len; i++)
	{
		cout << "姓名：" << heroArray[i].name
			<< " 年龄：" << heroArray[i].age
			<< " 性别: " << heroArray[i].sex << endl;
	}

	system("pause");
	return 0;
}