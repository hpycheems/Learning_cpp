#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

class Employee:public WorKer{
public:

	Employee(int id, string name, int dID);
	void showInfo();
	string getDeptName();
};
