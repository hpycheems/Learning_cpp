#include <iostream>
using namespace std;

#include "SpeechManager.h"

int main() {

	srand((unsigned int)time(NULL));
	SpeechManager sm;
	int chooce = -1;

	while (true) {
		sm.show_Menu();
		cout << "ÇëÊäÈëÄúµÄÑ¡Ôñ:" << endl;
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