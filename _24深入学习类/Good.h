#pragma once
#include <vector>
using namespace std;

//class A;//������Ҫ�������ǵ�ͷ�ļ�
#include "A.h"

//class B;
#include "B.h"

//class C;
#include "C.h"

//class D;
#include "D.h"
class E;
class Good :public A,private B//������̳в���������
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
	D m_dObject;//������ʹ�ò�����������
};

