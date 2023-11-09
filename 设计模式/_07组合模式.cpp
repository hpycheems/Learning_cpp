#include <iostream>
#include <vector>

class Component {
public:
	virtual ~Component() {}

	virtual Component* getChile() {
		return 0;
	}

	virtual void add(Component*) {}
	virtual void reomve(int) {}
	virtual void operation() = 0;
};

class Composite : public Component {
public:
	~Composite() {
		for (size_t i = 0; i < _children.size(); i++)
		{
			delete _children[i];
		}
	}

	Component* getChild(const unsigned int index) {
		return _children[index];
	}

	void add(Component* chiled)
	{
		_children.push_back(chiled);
	}

	void remove(const unsigned int index) {
		Component* child = _children[index];
		_children.erase(_children.begin() + index);
		delete child;
	}
	void operation()
	{
		for (unsigned int i = 0; i < _children.size(); i++)
		{
			_children[i]->operation();
		}
	}
private:
	std::vector<Component*> _children;
};

class Leaf :public Component {
public:
	Leaf(const int id) :_id(id) {

	}
	~Leaf() {}
	void operation() {
		std::cout << "Leaf " << _id << " operation" << std::endl;
	}

private:
	int _id;
};

int main7() {

	Composite composite;

	for (unsigned int i = 0; i < 5; i++)
	{
		composite.add(new Leaf(i));
	}

	composite.remove(0);
	composite.operation();


	return 0;
}