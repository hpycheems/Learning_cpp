#include <iostream>
using namespace std;
#include <map>
#include <vector>

#define CHEHUA 0
#define MEISHU 1
#define YANFA  2
//Ա�����鰸��

class Worker {
public:
	string m_Name;
	int Salary;
};

void createWorker(vector<Worker>& woker) {
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		Worker w;
		w.m_Name = "Ա��";
		w.m_Name += nameSeed[i];
		w.Salary = rand() % 3000 + 7000;
		woker.push_back(w);
	}
}

void workerGroup(const vector<Worker>& v, multimap<int, Worker>& m) {
	for (vector<Worker>::const_iterator it = v.begin(); it != v.end(); it++)
	{
		int index = rand() % 3; // 0 - 2
		m.insert(make_pair(index, *it));
	}
}
void showGroupWorker(multimap<int, Worker>& m) {
	cout << "�߻����ţ�" << endl;
	multimap<int, Worker>::iterator pos = m.find(CHEHUA);
	int count = m.count(CHEHUA);
	int index = 0;
	for (; pos != m.end() && index <count;pos++,index++)
	{
		cout << "���� " << pos->second.m_Name << " ���� " << pos->second.Salary << endl;
	}

	cout << "�������ţ�" << endl;
	pos = m.find(MEISHU);
	count = m.count(MEISHU);
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "���� " << pos->second.m_Name << " ���� " << pos->second.Salary << endl;
	}

	cout << "�з����ţ�" << endl;
	pos = m.find(YANFA);
	count = m.count(YANFA);
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "���� " << pos->second.m_Name << " ���� " << pos->second.Salary << endl;
	}

}
int main() {

	srand((unsigned)time(0));

	//����Ա��
	vector<Worker> vWorker;

	createWorker(vWorker);
	//Ա������
	multimap<int, Worker> mWorker;
	workerGroup(vWorker, mWorker);

	//�������Ա��
	showGroupWorker(mWorker);

	//����
	//for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); it++)
	//{
	//	cout << "���� " << it->m_Name << " ���� " << it->Salary << endl;
	//}

	system("pause");
	return 0;
}