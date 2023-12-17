#include <iostream>
#include <thread>


struct LinkList
{
	int data;
	LinkList* next;
};
void LinkListInsert(LinkList* head, int data, int index) {
	int count = 0;
	LinkList* lastPoint = nullptr;
	LinkList* insertPoint = head;

	while (count < index) {
		lastPoint = insertPoint;
		insertPoint = insertPoint->next;
		++count;
	}

	LinkList temp;
	temp.data = data;
	temp.next = insertPoint;
	lastPoint->next = &temp;
}

void LinkListRemove(LinkList* head, int index) {
	int count = 0;
	LinkList* lastPoint = nullptr;
	LinkList* insertPoint = head;
	while (count < index) {
		lastPoint = insertPoint;
		insertPoint = insertPoint->next;
		++count;
	}
	lastPoint->next = insertPoint->next;
}

int LinkListFind(LinkList* head,int data) {
	auto result = head->next;
	while (result) {
		if (result->data == data) {
			return result->data;
		}
	}
	return -1;
}


void PrintThreadName() {
	std::cout << std::this_thread::get_id() << std::endl;
}

int main() {

	std::thread A;


	return 0;
}
