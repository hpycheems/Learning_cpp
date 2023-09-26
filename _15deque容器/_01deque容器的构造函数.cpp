#include<iostream>
using namespace std;
#include <deque>

//˫�����飬���Զ�ͷ�˽��в���ɾ������

//vector����ͷ���Ĳ���ɾ��Ч�ʵ�
//deque��Զ��ԣ�����ͷ���Ĳ���ɾ���ٶȻ��vector��
//vector����Ԫ��ʱ���ٶȻ��deque�죬

//deque�ڲ�����ԭ��
//deque�ڲ���һ���п�����ά��ÿ�λ������е����ݣ������������ʵ����
//�п���ά������ÿ���������ĵ�ַ��ʹ��ʹ��dequeʱ��һƬ�������ڴ�ռ䡣
//deque֧�������ȡ

//deque���캯��
/*
deque<T> deqT;
deque(beg,end);
deque(n, elem);
deque(const deque & deq);
*/
void printDeque1(const deque<int> &d) {
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test1_1() {

	deque<int> d;
	for (int i = 0; i < 10; i++)
	{
		d.push_back(i);
	}
	printDeque1(d);

	deque<int> d2(d.begin(), d.end());
	printDeque1(d2);

	deque<int> d3(10, 100);
	printDeque1(d3);

	deque<int> d4(d3);
	printDeque1(d4);

}

int main1() {
	test1_1();
	system("pause");
	return  0;
}