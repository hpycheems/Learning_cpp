#include <iostream>

class Handler {
public:
	virtual ~Handler() {}

	virtual void setHandler(Handler* s) {
		_successor = s;
	}

	virtual void HandlerRequest() {
		if (_successor != nullptr) {
			_successor->HandlerRequest();
		}
	}
protected:
	Handler* _successor;
};

class ConcreteHandler :public Handler {
public:
	~ConcreteHandler() {};

	bool canHandle() {
		return false;
	}

	void HandlerRequest() {
		if (canHandle()) {
			std::cout << "Handled by Concrete Handler 1 \n";
		}
		else {
			std::cout << "Cannot be handled by Handler 1" << std::endl;
			Handler::HandlerRequest();
		}
	}

};

class ConcreteHandler2 : public Handler {
public:
	~ConcreteHandler2() {}

	bool canHandle() {
		return true;
	}

	void HandlerRequest() {
		if (canHandle()) {
			std::cout << "Handled by Concrete Handler 2 \n";
		}
		else {
			std::cout << "Cannot be handled by Handler 2" << std::endl;
			Handler::HandlerRequest();
		}
	}
};


int main5() {

	ConcreteHandler c1;
	ConcreteHandler2 c2;
	c1.setHandler(&c2);
	c1.HandlerRequest();

	return 0;
}