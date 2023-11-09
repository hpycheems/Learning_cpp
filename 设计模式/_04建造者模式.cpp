#include <string>
#include <iostream>


class Protuct {
public:
	Protuct() {}
	~Protuct() {}

	void makeA(const std::string& part) {
		this->partA = part;
	}

	void makeB(const std::string& part) {
		this->partB = part;
	}

	void makeC(const std::string& part) {
		this->partC = part;
	}

	std::string getPart() {
		return (partA + " " + partB + " " + partC);
	}

private:
	std::string partA;
	std::string partB;
	std::string partC;
};

class Builder {
public:
	virtual ~Builder() {}

	Protuct get() {
		return _protuct;
	}

	virtual void buildPartA() = 0;
	virtual void buildPartB() = 0;
	virtual void buildPartC() = 0;
protected:
	Protuct _protuct;
};

class ConcreteBuilderX : public Builder {
public:
	void buildPartA() {
		_protuct.makeA("partA-X");
	}
	void buildPartB() {
		_protuct.makeB("partB-X");
	}
	void buildPartC() {
		_protuct.makeC("partC-X");
	}
};

class ConcreteBuilderY :public Builder {
public:
	void buildPartA() {
		_protuct.makeA("partA-Y");
	}
	void buildPartB() {
		_protuct.makeB("partB-Y");
	}
	void buildPartC() {
		_protuct.makeC("partC-Y");
	}
};

class Director {
public:

	Director() :_builder() {}
	~Director() {
		if (_builder) {
			delete _builder;
		}
	}

	void setBuilder(Builder* builder) {
		if (_builder) {
			delete _builder;
		}
		_builder = builder;
	}

	Protuct get() {
		return _builder->get();
	}

	void constuct() {
		_builder->buildPartA();
		_builder->buildPartB();
		_builder->buildPartC();
	}
private:
	Builder* _builder;
};

int main4() {

	/*Director d;
	d.setBuilder(new ConcreteBuilderX);
	d.constuct();
	Protuct p = d.get();
	std::cout << p.getPart() << "\n";

	d.setBuilder(new ConcreteBuilderY);
	d.constuct();
	p = d.get();
	std::cout << p.getPart() << "\n";*/
	Director d;
	d.setBuilder(new ConcreteBuilderX);
	d.constuct();
	Protuct p = d.get();
	std::cout << p.getPart() << "\n";


	system("pause");
	return 0;
}