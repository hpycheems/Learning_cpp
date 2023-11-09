#include <iostream>

class Receiver {
public:
	~Receiver() {}

	void action() {
		std::cout << "Receive : execute action " << "\n";
	}
};

class Command {
public:
	virtual ~Command() {}
	virtual void execute() = 0;

protected:
	Command() {}
};

class ConcreteCommand :public Command{
public:
	ConcreteCommand(Receiver* receiver) :_receiver(receiver){}
	~ConcreteCommand() {
		if (_receiver) {
			delete _receiver;
		}
	}
	void execute() {
		_receiver->action();
	}
private:
	Receiver* _receiver;
};

class Invoker {
public:
	void set(Command* command) {
		_command = command;
	}

	void confirm() {
		_command->execute();
	}
private:
	Command* _command;
};

int main6() {
	ConcreteCommand c(new Receiver());
	Invoker i;
	i.set(&c);
	i.confirm();

	return 0;
}