#include <iostream>
using namespace std;
#include <stack>

//stack��һ���Ƚ���������ݽṹ��ֻ��һ������
//��ջ push
//��ջ pop

//ջ�� ���ڳ��ͽ�
//ջ�� 

//ջ�������б�����Ϊ ֻ��ջ��Ԫ�ز��ܱ������ʵ�
// empty �Ƿ�Ϊ�� size ����Ԫ�ظ���

//����ӿ�
/*
���캯����
stack<T> stk;
stack(const stack &stk);
��ֵ������
stack& operator=(const stack & stk);
���ݴ�ȡ��
push��elem����
pop();
top();
��С������
empty();
size();
*/

void test1_1() {
	stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);

	cout << "ջ�Ĵ�СΪ:" << s.size() << endl;

	while (!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}

	cout << "ջ�Ĵ�СΪ:" << s.size() << endl;
}

int main1() {
	test1_1();
	system("pause");
	return 0;
}