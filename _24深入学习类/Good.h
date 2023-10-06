#pragma once
#include <vector>
using namespace std;

//class A;//所以需要包含他们的头文件
#include "A.h"

//class B;
#include "B.h"

//class C;
#include "C.h"

//class D;
#include "D.h"
class E;
class Good :public A,private B//不允许继承不完整的类
{
public:
	Good();
	~Good();
	Good(const C&);
	C action(int,int);
	C& getC(int);
	E caculate(int);
private:
	vector<C> m_cGroup;
	D m_dObject;//不允许使用不完整的类型
};

