#include <iostream>
using namespace std;

#include <string>
#define MAX 10

struct Person {
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;
};

struct Addressbooks {
	Person personArray[MAX];
	int m_Size;
};

int existPerson(Addressbooks* abs, string name) {

	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name) {
			return i;
		}
	}
	return -1;
}
void modify(Person* p) {
	string name;
	cout << "请输入姓名：" << endl;
	cin >> name;

	p->m_Name = name;

	cout << "请输入性别：" << endl;
	cout << "  1 --- 男" << endl;
	cout << "  2 --- 女" << endl;
	int sex = 0;
	while (true)
	{
		cin >> sex;
		if (sex == 1 || sex == 2) {
			p->m_Sex = sex;
			break;
		}
		cout << "输入有误，请重新输入！" << endl;
	}

	int age = 0;
	cout << "请输入年龄：" << endl;
	cin >> age;
	p->m_Age = age;

	cout << "请输入电话:" << endl;
	string phone;
	cin >> phone;
	p->m_Phone = phone;

	cout << "请输入地址：" << endl;
	string addr;
	cin >> addr;
	p->m_Addr = addr;

	cout << "修改成功！" << endl;
}

void showMenu() {
	cout << "*************************" << endl;
	cout << "***** 1、添加联系人 *****" << endl;
	cout << "***** 2、显示联系人 *****" << endl;
	cout << "***** 3、删除联系人 *****" << endl;
	cout << "***** 4、查找联系人 *****" << endl;
	cout << "***** 5、修改联系人 *****" << endl;
	cout << "***** 6、清空联系人 *****" << endl;
	cout << "***** 0、退出系统   *****" << endl;
	cout << "*************************" << endl;
}
void quitSystem() {
	cout << "系统退出" << endl;
	system("pause");
}
void addPerson(Addressbooks *abs) {
	if (abs->m_Size == MAX)
	{
		cout << "满人了！" << endl;
		return;
	}
	else {
		modify(&abs->personArray[abs->m_Size]);
		abs->m_Size++;

		system("pause");
		system("cls");
	}
}
void showPerson(const Addressbooks* abs) {
	if (abs->m_Size <= 0) {
		cout << "空通讯录！" << endl;
	}
	else {

		for (int i = 0; i < abs->m_Size; i++)
		{
			Person person = abs->personArray[i];
			cout << "姓名:	" << person.m_Name << "\t"
				 << "性别:	" << ((person.m_Sex == 1) ? "男" : "女") << "\t"
				 << "年龄:	"<< person.m_Age   << "\t"
				 << "电话:	"<< person.m_Phone << "\t"
				 << "住址:	" << person.m_Addr << endl;
		}
	}

	system("pause");
	system("cls");
}
void deletePerrson(Addressbooks* abs) {
	cout << "输入删除联系人：" << endl;

	string name;
	cin >> name;

	int index =  existPerson(abs, name);
	if (index == -1) {
		cout << "查无此人！" << endl;
	}
	else {

		for (int i = index; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		cout << "删除成功" << endl;
		abs->m_Size--;
	}

	system("pause");
	system("cls");
}
void findPerson(Addressbooks* abs) {
	cout << "查找联系人的姓名：" << endl;
	string name;
	cin >> name;
	int index = existPerson(abs, name);
	if (index == -1) {
		cout << "查无此人！" << endl;
	}
	else {
		Person person = abs->personArray[index];
		cout << "姓名:	" << person.m_Name << "\t"
			<< "性别:	" << ((person.m_Sex == 1) ? "男" : "女") << "\t"
			<< "年龄:	" << person.m_Age << "\t"
			<< "电话:	" << person.m_Phone << "\t"
			<< "住址:	" << person.m_Addr << endl;
	}

	system("pause");
	system("cls");
}
void modifyPerons(Addressbooks* abs) {
	cout << "输入要修改的联系人：" << endl;
	string name;
	cin >> name;
	int index = existPerson(abs, name);
	if (index == -1) {
		cout << "查无此人！" << endl;
	}
	else {
		modify(&abs->personArray[index]);
	}

	system("pause");
	system("cls");
}
void cleanPerson(Addressbooks* abs) {
	cout << "是否真的清空!" << endl;
	cout << "1 -- 确定" << endl;
	cout << "2 -- 取消" << endl;

	int select = 0;
	cin >> select;
	if (select == 1) {
		abs->m_Size = 0;
		cout << "通讯录已经清空！" << endl;
	}
	else {
		cout << "取消清空" << endl;
	}
	
	system("pause");
	system("cls");
}


int main() {

	Addressbooks abs;
	abs.m_Size = 0;

	int select = 0;

	while (true) {
		showMenu();
		cin >> select;
		switch (select) {
			case 0:
				quitSystem();
				return 0;

				break;
			case 1:
				addPerson(&abs);

				break;
			case 2:
				showPerson(&abs);

				break;
			case 3: 
				deletePerrson(&abs);			

				break;
			case 4:
				findPerson(&abs);

				break;
			case 5:
				modifyPerons(&abs);

				break;
			case 6:
				cleanPerson(&abs);

				break;
		}
	}

	system("pause");
	return 0;
}