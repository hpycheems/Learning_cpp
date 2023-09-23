#include "workManager.h"

workManager::workManager()
{

	m_FileIsEmpty = false;
	//1���ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ�������" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	ifs.get();
	//2 �ļ����ڲ���Ϊ��
	if (ifs.eof()) {
		cout << "�ļ�Ϊ��" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	int num = get_EmpNum();
	this->m_EmpNum = num;
	//cout << "Ա������Ϊ " << m_EmpNum << "��" << endl;

	m_EmpArray = new WorKer * [m_EmpNum];
	this->init_Emp();

	//for (int i = 0; i < m_EmpNum; i++)
	//{
	//	cout << "Ա����ID: " << m_EmpArray[i]->m_Id
	//		<< "\t Ա��������: " << m_EmpArray[i]->m_Name
	//		<< "\t Ա���ĸ�λ���: " << m_EmpArray[i]->m_DeptId<< endl;
	//}
	
}

workManager::~workManager()
{
	if (m_EmpArray != NULL) {
		delete[] m_EmpArray;
		m_EmpArray = NULL;
	}
}

void workManager::Show_Menu()
{
	cout << "==================================" << endl;
	cout << "======= ��ӭʹ��ְ������ϵͳ =====" << endl;
	cout << "========  0.�˳��������  ========" << endl;
	cout << "========  1.����ְ����Ϣ  ========" << endl;
	cout << "========  2.��ʾְ����Ϣ  ========" << endl;
	cout << "========  3.ɾ����ְְ��  ========" << endl;
	cout << "========  4.�޸�ְ����Ϣ  ========" << endl;
	cout << "========  5.����ְ����Ϣ  ========" << endl;
	cout << "========  6.�����������  ========" << endl;
	cout << "========  7.��������ĵ�  ========" << endl;
	cout << "==================================" << endl;
}

void workManager::ExitSystem()
{
	cout << "��ӭ�ٴ�ʹ�ã�" << endl;
	system("pause");
	exit(0);
}

void workManager::AddWorker()
{
	cout << "������Ҫ���ӵ�ְ��������" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0) {
		//�����¿ռ��С
		int newSize = this->m_EmpNum + addNum;
		//�����¿ռ�
		WorKer** newSpace = new WorKer * [newSize];
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int did;

			cout << "������� " << i + 1 << "λ��Ա���ı��:" << endl;
			cin >> id;
			cout << "������� " << i + 1 << "λ��Ա��������:" << endl;
			cin >> name;
			cout << "��ѡ�� " << i + 1 << "λ��Ա���ĸ�λ" << endl;
			cout << "1����ͨԱ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> did;
			WorKer* worker = NULL;
			switch (did) {
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Employee(id, name, 2);
				break;
			case 3:
				worker = new Employee(id, name, 3);
				break;
			}
			newSpace[this->m_EmpNum + i] = worker;
		}

		delete[] m_EmpArray;
		m_EmpArray = newSpace;
		this->m_EmpNum = newSize;

		m_FileIsEmpty = false;

		cout << "�ɹ������ " << addNum << " ��Ա��" << endl;
		save();
	}
	else {
		cout << "����ȷ�����룡" << endl;
	}

	system("pause");
	system("cls");
}

void workManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
}

int workManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int did;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> did) {
		num++;
	}

	ifs.close();

	return num;
}

void workManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {
		WorKer* worker = NULL;
		if (dId == 1) {
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2) {
			worker = new Manager(id, name, dId);
		}
		else if (dId == 3) {
			worker = new Boss(id, name, dId);
		}

		this->m_EmpArray[index++] = worker;
	}

	ifs.close();
}

void workManager::ShowEmp()
{
	if (m_FileIsEmpty) {
		cout << "�ļ�Ϊ�� ���� �ļ�������" << endl;
	}
	else {
		for (int i = 0; i < m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showInfo();
		}
	}

	system("pause");
	system("cls");
}

int workManager::isExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id) {
			index = i;
			return index;
		}
	}
	return index;
}

void workManager::Del_Emp()
{
	if (m_FileIsEmpty) {
		cout<< "�ļ�Ϊ�� ���� �ļ�������" << endl;
	}
	else {

		cout << "������Ҫɾ����Ա�����" << endl;

		int select = 0;
		cin >> select;

		int index =  isExist(select);

		if (index == -1) {
			cout << "���Ҳ������Ϊ " << select << "��Ա��" << endl;
		}
		else {
			for (int i = index; i < this->m_EmpNum; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			if (this->m_EmpNum <= 0) {
				m_FileIsEmpty = true;
			}
			save();

			cout << "ɾ���ɹ�" << endl;
		}
	}

	system("pause");
	system("cls");
}

void workManager::Mod_Emp()
{
	if (m_FileIsEmpty) {
		cout << "�ļ�Ϊ�� ���� �ļ�������" << endl;
	}
	else {
		cout << "������Ҫ�޸ĵ�ְ�����: " << endl;
		int input = 0;
		cin >> input;
		int index = isExist(input);

		if (index == -1) {
			cout << "���޴���" << endl;
		}
		else {
			cout << "���ҵ����Ϊ:" << input << "��Ա��" << endl;
			string name;
			int did;

			cout << "������Ա����������" << endl;
			cin >> name;
			cout << "������Ա���¸�λ " << endl;
			cout << "1����ͨԱ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> did;

			WorKer* worker = NULL;
			if (did == 1) {
				worker = new Employee(input, name, did);
			}
			else if (did == 2) {
				worker = new Manager(input, name, did);
			}
			else if (did == 3) {
				worker = new Boss(input, name, did);
			}
			else {
				cout << "�������룬Ĭ��Ϊ��ͨԱ��" << endl;
				worker = new Employee(input, name, did);
			}

			delete this->m_EmpArray[index];
			this->m_EmpArray[index] = worker;
			cout << "�޸ĳɹ�" << endl;
			save();
		}
	}

	system("pause");
	system("cls");
}

void workManager::Find_Emp()
{
	if (m_FileIsEmpty) {
		cout << "�ļ�Ϊ�� ���� �ļ�������" << endl;
	}
	else {
		cout << "��������ҷ�ʽ" << endl;
		cout << "1�����ձ�Ų���" << endl;
		cout << "2��������������" << endl;
		int select = 0;
		cin >> select;
		if (select == 1) {
			cout << "������Ҫ���ҵ�ְ�����:" << endl;
			int input = 0;
			cin >> input;
			int ref = isExist(input);
			if (ref == -1) {
				cout << "���޴���" << endl;
			}
			else {
				cout << "��ѯ�����Ϊ " << input << "��Ա����Ա����Ϣ����:" << endl;
				cout << "Ա�����: " << m_EmpArray[ref]->m_Id
					<< "\t Ա������: " << m_EmpArray[ref]->m_Name
					<< "\t Ա����λ: " << m_EmpArray[ref]->getDeptName() << endl;
			}
		}
		else if (select == 2) {
			cout << "������Ҫ���ҵ�ְ������:" << endl;
			string name = "";
			cin >> name;

			bool has = false;
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name) {
					cout << "���ҵ� " << this->m_EmpArray[i]->m_Name 
						<< "Ա�����Ϊ " << this->m_EmpArray[i]->m_Id 
						<< "����Ϣ���� :" << endl;

					cout << "ְ�����: " << this->m_EmpArray[i]->m_Id
						<< "\t  ְ������: " << this->m_EmpArray[i]->m_Name
						<< "\t  ��λ: " << this->m_EmpArray[i]->getDeptName() 
						<< endl;
					has = true;
				}
			}
			if (!has) {
				cout << "���޴���" << endl;
			}
		}
		else {
			cout << "��������" << endl;
		}
	}

	system("pause");
	system("cls");
}

void workManager::Sort_Emp()
{
	if (m_FileIsEmpty) {
		cout << "�ļ�Ϊ�� ���� �ļ�������" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "������Ҫʵ�ֵ�����ʽ" << endl;
		cout << "1.��������" << endl;
		cout << "2.��������" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < m_EmpNum; i++)
		{
			int maxOrMinIndex = i;
			for (int j = i; j < m_EmpNum; j++)
			{
				if (select == 1) {
					if (this->m_EmpArray[maxOrMinIndex]->m_Id > this->m_EmpArray[j]->m_Id)
						maxOrMinIndex = j;
				}
				else {
					if (this->m_EmpArray[maxOrMinIndex]->m_Id < this->m_EmpArray[j]->m_Id)
						maxOrMinIndex = j;
				}
			}
			if (maxOrMinIndex != i) {
				WorKer* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[maxOrMinIndex];
				this->m_EmpArray[maxOrMinIndex] = temp;
			}
		}
		cout << "����ɹ�" << endl;
		save();
		this->ShowEmp();
	}
}

void workManager::Clear_File()
{
	if (m_FileIsEmpty) {
		cout << "�ļ�Ϊ�� ���� �ļ�������" << endl;
	}
	else {
		cout << "ȷ�����?" << endl;
		cout << "1.���" << endl;
		cout << "2.����" << endl;
		int select = 0;
		cin >> select;

		if (select == 1) {

			ofstream ofs;
			ofs.open(FILENAME, ios::trunc);
			ofs.close();

			for (int i = 0; i < m_EmpNum; i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}

			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			m_EmpNum = 0;
			m_FileIsEmpty = true;

			cout << "��ճɹ�" << endl;
		}
	}

	system("pause");
	system("cls");
}
