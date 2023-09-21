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
	cout << "������������" << endl;
	cin >> name;

	p->m_Name = name;

	cout << "�������Ա�" << endl;
	cout << "  1 --- ��" << endl;
	cout << "  2 --- Ů" << endl;
	int sex = 0;
	while (true)
	{
		cin >> sex;
		if (sex == 1 || sex == 2) {
			p->m_Sex = sex;
			break;
		}
		cout << "�����������������룡" << endl;
	}

	int age = 0;
	cout << "���������䣺" << endl;
	cin >> age;
	p->m_Age = age;

	cout << "������绰:" << endl;
	string phone;
	cin >> phone;
	p->m_Phone = phone;

	cout << "�������ַ��" << endl;
	string addr;
	cin >> addr;
	p->m_Addr = addr;

	cout << "�޸ĳɹ���" << endl;
}

void showMenu() {
	cout << "*************************" << endl;
	cout << "***** 1�������ϵ�� *****" << endl;
	cout << "***** 2����ʾ��ϵ�� *****" << endl;
	cout << "***** 3��ɾ����ϵ�� *****" << endl;
	cout << "***** 4��������ϵ�� *****" << endl;
	cout << "***** 5���޸���ϵ�� *****" << endl;
	cout << "***** 6�������ϵ�� *****" << endl;
	cout << "***** 0���˳�ϵͳ   *****" << endl;
	cout << "*************************" << endl;
}
void quitSystem() {
	cout << "ϵͳ�˳�" << endl;
	system("pause");
}
void addPerson(Addressbooks *abs) {
	if (abs->m_Size == MAX)
	{
		cout << "�����ˣ�" << endl;
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
		cout << "��ͨѶ¼��" << endl;
	}
	else {

		for (int i = 0; i < abs->m_Size; i++)
		{
			Person person = abs->personArray[i];
			cout << "����:	" << person.m_Name << "\t"
				 << "�Ա�:	" << ((person.m_Sex == 1) ? "��" : "Ů") << "\t"
				 << "����:	"<< person.m_Age   << "\t"
				 << "�绰:	"<< person.m_Phone << "\t"
				 << "סַ:	" << person.m_Addr << endl;
		}
	}

	system("pause");
	system("cls");
}
void deletePerrson(Addressbooks* abs) {
	cout << "����ɾ����ϵ�ˣ�" << endl;

	string name;
	cin >> name;

	int index =  existPerson(abs, name);
	if (index == -1) {
		cout << "���޴��ˣ�" << endl;
	}
	else {

		for (int i = index; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		cout << "ɾ���ɹ�" << endl;
		abs->m_Size--;
	}

	system("pause");
	system("cls");
}
void findPerson(Addressbooks* abs) {
	cout << "������ϵ�˵�������" << endl;
	string name;
	cin >> name;
	int index = existPerson(abs, name);
	if (index == -1) {
		cout << "���޴��ˣ�" << endl;
	}
	else {
		Person person = abs->personArray[index];
		cout << "����:	" << person.m_Name << "\t"
			<< "�Ա�:	" << ((person.m_Sex == 1) ? "��" : "Ů") << "\t"
			<< "����:	" << person.m_Age << "\t"
			<< "�绰:	" << person.m_Phone << "\t"
			<< "סַ:	" << person.m_Addr << endl;
	}

	system("pause");
	system("cls");
}
void modifyPerons(Addressbooks* abs) {
	cout << "����Ҫ�޸ĵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int index = existPerson(abs, name);
	if (index == -1) {
		cout << "���޴��ˣ�" << endl;
	}
	else {
		modify(&abs->personArray[index]);
	}

	system("pause");
	system("cls");
}
void cleanPerson(Addressbooks* abs) {
	cout << "�Ƿ�������!" << endl;
	cout << "1 -- ȷ��" << endl;
	cout << "2 -- ȡ��" << endl;

	int select = 0;
	cin >> select;
	if (select == 1) {
		abs->m_Size = 0;
		cout << "ͨѶ¼�Ѿ���գ�" << endl;
	}
	else {
		cout << "ȡ�����" << endl;
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