#include <iostream>
using namespace std;
#include <map>
#include <vector>

#define CHEHUA 0
#define MEISHU 1
#define YANFA  2
//员工分组案例

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
		w.m_Name = "员工";
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
	cout << "策划部门：" << endl;
	multimap<int, Worker>::iterator pos = m.find(CHEHUA);
	int count = m.count(CHEHUA);
	int index = 0;
	for (; pos != m.end() && index <count;pos++,index++)
	{
		cout << "姓名 " << pos->second.m_Name << " 工资 " << pos->second.Salary << endl;
	}

	cout << "美术部门：" << endl;
	pos = m.find(MEISHU);
	count = m.count(MEISHU);
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名 " << pos->second.m_Name << " 工资 " << pos->second.Salary << endl;
	}

	cout << "研发部门：" << endl;
	pos = m.find(YANFA);
	count = m.count(YANFA);
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名 " << pos->second.m_Name << " 工资 " << pos->second.Salary << endl;
	}

}
int main() {

	srand((unsigned)time(0));

	//创建员工
	vector<Worker> vWorker;

	createWorker(vWorker);
	//员工分组
	multimap<int, Worker> mWorker;
	workerGroup(vWorker, mWorker);

	//输出分组员工
	showGroupWorker(mWorker);

	//测试
	//for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); it++)
	//{
	//	cout << "姓名 " << it->m_Name << " 工资 " << it->Salary << endl;
	//}

	system("pause");
	return 0;
}