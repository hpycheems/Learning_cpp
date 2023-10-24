#pragma once
#include <vector>
#include <set>
#include "A.h"
//class A;

class B;

#include "C.h"
//class C;

class D;
class E;

class Good :public A{
public:
	Good();
	~Good();
	E func();
	E& func_1();
	E func(E);
	void func(E&);
private:
	B& m_b;
	C m_c;
	std::vector<D> m_d;
	std::set<D> m_DD;
};