#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

class Manager :public WorKer {
public:
	Manager(int id, string name, int dID);

	virtual void showInfo();
	virtual string getDeptName();
};