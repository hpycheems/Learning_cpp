#include "workManager.h"

workManager::workManager()
{

	m_FileIsEmpty = false;
	//1、文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	ifs.get();
	//2 文件存在并且为空
	if (ifs.eof()) {
		cout << "文件为空" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	int num = get_EmpNum();
	this->m_EmpNum = num;
	//cout << "员工人数为 " << m_EmpNum << "人" << endl;

	m_EmpArray = new WorKer * [m_EmpNum];
	this->init_Emp();

	//for (int i = 0; i < m_EmpNum; i++)
	//{
	//	cout << "员工的ID: " << m_EmpArray[i]->m_Id
	//		<< "\t 员工的姓名: " << m_EmpArray[i]->m_Name
	//		<< "\t 员工的岗位编号: " << m_EmpArray[i]->m_DeptId<< endl;
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
	cout << "======= 欢迎使用职工管理系统 =====" << endl;
	cout << "========  0.退出管理程序  ========" << endl;
	cout << "========  1.增加职工信息  ========" << endl;
	cout << "========  2.显示职工信息  ========" << endl;
	cout << "========  3.删除离职职工  ========" << endl;
	cout << "========  4.修改职工信息  ========" << endl;
	cout << "========  5.查找职工信息  ========" << endl;
	cout << "========  6.按照序号排序  ========" << endl;
	cout << "========  7.清空所有文档  ========" << endl;
	cout << "==================================" << endl;
}

void workManager::ExitSystem()
{
	cout << "欢迎再次使用！" << endl;
	system("pause");
	exit(0);
}

void workManager::AddWorker()
{
	cout << "请输入要增加的职工人数：" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0) {
		//计算新空间大小
		int newSize = this->m_EmpNum + addNum;
		//开辟新空间
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

			cout << "请输入第 " << i + 1 << "位新员工的编号:" << endl;
			cin >> id;
			cout << "请输入第 " << i + 1 << "位新员工的姓名:" << endl;
			cin >> name;
			cout << "请选择 " << i + 1 << "位新员工的岗位" << endl;
			cout << "1、普通员工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
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

		cout << "成功添加了 " << addNum << " 名员工" << endl;
		save();
	}
	else {
		cout << "不正确的输入！" << endl;
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
		cout << "文件为空 或者 文件不存在" << endl;
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
		cout<< "文件为空 或者 文件不存在" << endl;
	}
	else {

		cout << "请输入要删除的员工编号" << endl;

		int select = 0;
		cin >> select;

		int index =  isExist(select);

		if (index == -1) {
			cout << "查找不到编号为 " << select << "的员工" << endl;
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

			cout << "删除成功" << endl;
		}
	}

	system("pause");
	system("cls");
}

void workManager::Mod_Emp()
{
	if (m_FileIsEmpty) {
		cout << "文件为空 或者 文件不存在" << endl;
	}
	else {
		cout << "请输入要修改的职工编号: " << endl;
		int input = 0;
		cin >> input;
		int index = isExist(input);

		if (index == -1) {
			cout << "查无此人" << endl;
		}
		else {
			cout << "查找到编号为:" << input << "的员工" << endl;
			string name;
			int did;

			cout << "请输入员工新姓名：" << endl;
			cin >> name;
			cout << "请输入员工新岗位 " << endl;
			cout << "1、普通员工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
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
				cout << "错误输入，默认为普通员工" << endl;
				worker = new Employee(input, name, did);
			}

			delete this->m_EmpArray[index];
			this->m_EmpArray[index] = worker;
			cout << "修改成功" << endl;
			save();
		}
	}

	system("pause");
	system("cls");
}

void workManager::Find_Emp()
{
	if (m_FileIsEmpty) {
		cout << "文件为空 或者 文件不存在" << endl;
	}
	else {
		cout << "请输入查找方式" << endl;
		cout << "1、按照编号查找" << endl;
		cout << "2、按照姓名查找" << endl;
		int select = 0;
		cin >> select;
		if (select == 1) {
			cout << "请输入要查找的职工编号:" << endl;
			int input = 0;
			cin >> input;
			int ref = isExist(input);
			if (ref == -1) {
				cout << "查无此人" << endl;
			}
			else {
				cout << "查询到编号为 " << input << "的员工，员工信息如下:" << endl;
				cout << "员工编号: " << m_EmpArray[ref]->m_Id
					<< "\t 员工姓名: " << m_EmpArray[ref]->m_Name
					<< "\t 员工岗位: " << m_EmpArray[ref]->getDeptName() << endl;
			}
		}
		else if (select == 2) {
			cout << "请输入要查找的职工姓名:" << endl;
			string name = "";
			cin >> name;

			bool has = false;
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name) {
					cout << "查找到 " << this->m_EmpArray[i]->m_Name 
						<< "员工编号为 " << this->m_EmpArray[i]->m_Id 
						<< "的信息如下 :" << endl;

					cout << "职工编号: " << this->m_EmpArray[i]->m_Id
						<< "\t  职工姓名: " << this->m_EmpArray[i]->m_Name
						<< "\t  岗位: " << this->m_EmpArray[i]->getDeptName() 
						<< endl;
					has = true;
				}
			}
			if (!has) {
				cout << "查无此人" << endl;
			}
		}
		else {
			cout << "输入有误" << endl;
		}
	}

	system("pause");
	system("cls");
}

void workManager::Sort_Emp()
{
	if (m_FileIsEmpty) {
		cout << "文件为空 或者 文件不存在" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "请输入要实现的排序方式" << endl;
		cout << "1.降序排序" << endl;
		cout << "2.升序排序" << endl;
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
		cout << "排序成功" << endl;
		save();
		this->ShowEmp();
	}
}

void workManager::Clear_File()
{
	if (m_FileIsEmpty) {
		cout << "文件为空 或者 文件不存在" << endl;
	}
	else {
		cout << "确认清空?" << endl;
		cout << "1.清空" << endl;
		cout << "2.返回" << endl;
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

			cout << "清空成功" << endl;
		}
	}

	system("pause");
	system("cls");
}
