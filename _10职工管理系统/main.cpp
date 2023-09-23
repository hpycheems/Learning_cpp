#include <iostream>
using namespace std;
#include <string>

#include "workManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

int main() {

	//管理系统对象
	workManager wm;
	//用户选择
	int chioce = -1;
	//程序循环
	while (true) {
		wm.Show_Menu();
		cout << "请输入您的选择:" << endl;
		cin >> chioce;
		switch (chioce)
		{
		case 0:
			wm.ExitSystem();
			break;
		case 1:
			wm.AddWorker();
			break;
		case 2:
			wm.ShowEmp();
			break;
		case 3:
			wm.Del_Emp();
			break;
		case 4:
			wm.Mod_Emp();
			break;
		case 5:
			wm.Find_Emp();
			break;
		case 6:
			wm.Sort_Emp();
			break;
		case 7:
			wm.Clear_File();
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}