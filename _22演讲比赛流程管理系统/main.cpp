#include <iostream>
using namespace std;

#include "SpeechManager.h"

int main() {

	srand((unsigned int)time(NULL));
	SpeechManager sm;
	int chooce = -1;

	//for (map<int,Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
	//{
	//	cout << "ѡ�ֱ�ţ�" << it->first << 
	//		"ѡ�����ƣ�" << it->second.m_Name << 
	//		"ѡ�ַ�����" << it->second.m_Score[0] << endl;
	//}

	while (true) {
		sm.show_Menu();
		cout << "����������ѡ��:" << endl;
		cin >> chooce;
		switch (chooce)
		{
		case 0:
			sm.exitSystem();
			break;
		case 1:
			sm.startSpeech();
			break;
		case 2:
			sm.showRecord();
			break;
		case 3:
			sm.clearRecord();
			break;
		default:
			system("cls");
			break;
		}
	}
	
	system("pause");
	return 0;
}