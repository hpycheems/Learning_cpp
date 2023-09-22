#include <iostream>
using namespace std;

class CPU {
public:
	virtual void Calculater() = 0;
};
class VideoCar {
public:
	virtual void Display() = 0;
};
class Memory {
public :
	virtual void Storage() = 0;
};

class InterFirmCPU :public CPU {
public:
	void Calculater() {
		cout << "Inter Firm CUP进行计算" << endl;
	}
};
class InterFirmVideoCar :public VideoCar {
public:
	void Display() {
		cout << "Inter Firm VideoCar进行显示" << endl;
	}
};
class InterFirmMemory :public Memory {
public:
	void Storage() {
		cout << "Inter Firm Memory进行存储" << endl;
	}
};

class LenovoFirmCPU :public CPU {
public:
	void Calculater() {
		cout << "Lenovo Firm CUP进行计算" << endl;
	}
};
class LenovoFirmVideoCar :public VideoCar {
public:
	void Display() {
		cout << "Lenovo Firm VideoCar进行显示" << endl;
	}
};
class LenovoFirmMemory :public Memory {
public:
	void Storage() {
		cout << "Lenovo Firm Memory进行存储" << endl;
	}
};


class Computer {
public :
	Computer(CPU* cpu, VideoCar* vc, Memory* m) {
		m_CPU = cpu;
		m_VC = vc;
		m_M = m;
	}
	void DoWork(){
		m_CPU->Calculater();
		m_VC->Display();
		m_M->Storage();
	}

	~Computer() {
		if (m_CPU != NULL) {
			delete m_CPU;
			m_CPU = NULL;
		}
		if (m_VC != NULL) {
			delete m_VC;
			m_VC = NULL;
		}
		if (m_M != NULL) {
			delete m_M;
			m_M = NULL;
		}
	}

private:
	CPU* m_CPU;
	VideoCar* m_VC;
	Memory* m_M;
};

void test6_1() {
	// 不是new出来的 computer析构的时候会出错
	//InterFirmCPU interCPU;
	//LenovoFirmVideoCar lenovoVC;
	//InterFirmMemory interM;
	//Computer computer(&interCPU, &lenovoVC, &interM);
	//computer.DoWork();

	CPU* intelCPU = new InterFirmCPU;
	VideoCar* intelVC = new InterFirmVideoCar;
	InterFirmMemory* intelM = new InterFirmMemory;
	Computer computer2(intelCPU, intelVC, intelM);
	computer2.DoWork();
}

int main() {

	test6_1();
	system("pause");
	return 0;
}