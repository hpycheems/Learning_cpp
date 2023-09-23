#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

class Boss:public WorKer{
public:
	Boss(int id, string name, int dID);
	virtual void showInfo();
	virtual string getDeptName();
};