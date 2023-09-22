#include <iostream>
using namespace std;

class AbstrctDrinking {
public :
	virtual void Boil() = 0;

	virtual void Brew() = 0;
	
	virtual void PourInCup() = 0;

	virtual void PutSomthing() = 0;

	void makeDrink() {
		Boil();
		Brew();
		PourInCup();
		PutSomthing();
	}
};

class Coffe :public AbstrctDrinking {
public:
	void Boil() {
		cout << "Öó °×¿ªË®" << endl;
	}

	void Brew() {
		cout << "³åÅÝ ¿§·È" << endl;
	}

	void PourInCup() {
		cout << "µ¹Èë ±­ÖÐ" << endl;
	}

	void PutSomthing() {
		cout << "¼ÓÈëÅ£ÄÌºÈÌÇ" << endl;
	}
};

class Tea :public AbstrctDrinking {
public:
	void Boil() {
		cout << "Öó ¿óÈªË®" << endl;
	}

	void Brew() {
		cout << "³åÅÝ ²èÒ¶" << endl;
	}

	void PourInCup() {
		cout << "µ¹Èë ±­ÖÐ" << endl;
	}

	void PutSomthing() {
		cout << "¼ÓÈëèÛè½" << endl;
	}
};

void doWork(AbstrctDrinking * abs) {
	abs->makeDrink();
	delete abs;
}

void test4_1() {
	doWork(new Coffe);

	cout << "_________" << endl;

	doWork(new Tea);
}

int main4() {

	test4_1();

	system("pause");
	return 0;
}