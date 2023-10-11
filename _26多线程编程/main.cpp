#include <iostream>
#include <thread>
#include <vector>
#include<chrono>
#include <cmath>

#include <atomic>
#include <mutex>

/*
	Ϊʲôʹ�ö��߳�
	(1) ��ǰ�Ļ����ĵ��̺߳����Ѿ�������
	(2) ���߳�ӵ�����������
	(3) API������죬����ϵͳ�ͱ�׼���Ѿ�֧���˶��߳�
	Ҫ������IO�ͼ����ҵ�ƽ���
	���ܵ����⣺
	 (1) ����
	 (2) ����
	 (3) ��������������ɵ�����
	 (4) ��Ч��

	 C++11�������¸���
	 �߽׽ӿڣ�async��future
	 �ͽ׽ӿڣ�thread mutex
*/
void helloThread() {
	for (int i = 0; i < 100; ++i)
	{
		std::cout << "hello second thread:" << i << std::endl;;
	}
}
void startThreadFunction(std::string s1, std::string s2) {
	std::cout << s1 << " " << s2 << "\n";
}
void firstThread() {
	std::thread t(helloThread);//����һ���߳�
	for (int i = 0; i < 100; ++i)
	{
		std::cout << "hello main thread" << i << std::endl;
	}

	//�����߳�
	//std::thread a([&] {startThreadFunction("a", "b"); });
	//std::thread e(startThreadFunction, std::cref("a"), std::cref("b"));
	//
	//std::thread b(startThreadFunction, "a", "b");//���ַ��������string�Ŀ�������


	//�̵߳��ս� ���߳���ɹ��������
	t.join();
}



/*
* �����Ĺ������ٵĻ� �õ��̻߳�ȶ��߳̿� ��Ϊ����һ���߳�Ҳ��ķѺܶ���Դ
  Ŀǰ�����̵߳Ļ�ȷʵ����������Ч��
*  �ѹ����ֶ���߳���ִ��
*/
double caculate(double v) {
	if (v <= 0)
		return v;
	//���߳����� 10����
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	return sqrt((v * v + std::sqrt((v - 5) * (v + 2.5)) / 2.0) / v);
}

template<class Iter, class Fun>
double visitRange(std::thread::id id, Iter iterBegin, Iter iterEnd, Fun func) {
	auto curId = std::this_thread::get_id();
	if (id == curId)
		std::cout << "hello main thread" << std::endl;
	else
		std::cout << "hello work thread" << std::endl;
	double v = 0;
	for (auto iter = iterBegin; iter != iterEnd; ++iter)
	{
		v += func(*iter);
	}
	return v;
}
void MultiThreadTest() {

	auto mainThread = std::this_thread::get_id();
	std::vector<double> v;
	for (int i = 0; i < 1000; i++)
	{
		v.push_back(rand());
	}
	std::cout << v.size() << "\n";
	double value = 0.0;
	auto nowc = clock();//���������Գ���ʼִ�е���ǰλ�ã��������߹���ʱ�Ӵ���� 1����
	for (auto& info : v) {
		value += caculate(info);
	}
	auto finishc = clock();
	std::cout << "single thread :" << value << "used " << (finishc - nowc) << std::endl;

	nowc = clock();
	auto iter = v.begin() + (v.size() / 2);
	double anotherv = 0.0;
	auto iterEnd = v.end();
	//����һ���߳� ����ǰ�󲿷�
	std::thread s([&anotherv, mainThread, iter, iterEnd]() {
		anotherv = visitRange(mainThread, iter, iterEnd, caculate);
		});
	//�����̼߳��� ǰ�벿��
	auto halfv = visitRange(mainThread, v.begin(), iter, caculate);

	//��ʱ �̱߳�����ɹ������� ����
	s.join();
	finishc = clock();
	std::cout << "multithread:" << (halfv + anotherv) << "used " << (finishc - nowc) << std::endl;
}

#pragma region //�߳�ͬ��
template<class T>
class Lock {
public:
	Lock(T& mutex) :m_mutex{ mutex } { m_mutex.lock(); }
	~Lock() { m_mutex.unlock(); }
private:
	T& m_mutex;
};
//�Լ�ʵ��ʱ����������
struct BankAccount {
	BankAccount(int balance) :Balance{ balance } {}
	int Balance;
	std::mutex Mutex;
};
void transferMoney(BankAccount& a, BankAccount& b, int money) {
	if (&a == &b) return;
	std::lock_guard<std::mutex> lockA(a.Mutex);
	std::lock_guard<std::mutex> lockA(b.Mutex);
	if (a.Balance <= money) return;
	a.Balance -= money;
	b.Balance += money;


	//ʹ�ñ�׼��
	std::lock(a.Mutex, b.Mutex/* ... */);//����ȫ��ס�������ִ�� ����˳�� ������ô����
	std::lock_guard<std::mutex> lockA(a.Mutex, std::adopt_lock);//��������Ҫ�ڹ���ʱ������
	std::lock_guard<std::mutex> lockA(b.Mutex, std::adopt_lock);
	if (a.Balance <= money) return;
	a.Balance -= money;
	b.Balance += money;
}
/* ���߳��� ����ֵ�����
	BankAccount alice(100);
	BankAccount bob(100);
	thread 1
	transferMoney(alice, bob,10);//when call lockB
	thread 2
	transferMoney(bob, alice,10);//when call lockA

	��ν���أ��Լ�ʵ�֣����߳�������˳����һ�µģ���Ƚϵ�ַ��С��
*/


class Counter {
public:
	void addCountAndResources(int r) {
		std::lock_guard<std::mutex> lock(m_mutex);
		//lockMutex();
		addCount();
		addResources(1);
		//unlockMutex();
	}
	int count() { 
		std::lock_guard<std::mutex> lock(m_mutex);
		return m_count;
		//lockMutex(); auto r = m_count; unlockMutex(); return r; 
	}
	int aveResources() {
		std::lock_guard<std::mutex> lock(m_mutex);
		//lockMutex();
		if (m_count == 0)
		{
			unlockMutex();
			return 1;
		}
		auto r = m_totalResource / m_count;
		//unlockMutex();
		return r;
	}
	Counter() :m_count{ 0 }, m_totalResource{0} {}
	//�ṩ�ӿڳ�����һ�ִ������� ���磺���ǵ��� unlock ��������lock�� 
	//���� һ����lock��unlockǰ�׳��쳣���������
	//void lockMutex() { m_mutex.lock(); }
	//void unlockMutex() { m_mutex.unlock(); }
private:
	//ʹ�� atomicʵ�ֵ�ԭ�Ӳ��� 
	//int m_count;
	//std::atomic<int> m_count;
	int m_count;
	//atomic ��ȱ�� ����������ԭ�Ӳ���ʱ
	int m_totalResource;
	//�����ں�����ͬʱ����������ԭ�Ӳ����Ļ� Ҳ�ǻ������ ���⡣
	
	//ʹ��ͷ�ļ� mutex Ӧ������Ϊmutable��������ΪҪ������const������lock
	mutable std::mutex m_mutex;

	//���鲻�ð��ٽ����ӿڱ�¶��ȥ��ֱ��������ʹ�� ����ʱ��û�н���ٽ������쳣������
	void lockMutex() { m_mutex.lock(); }
	void unlockMutex() { m_mutex.unlock(); }
	void addCount() { m_count++; }// д��Ĵ��� �Ĵ���+1 д���ڴ�
	void addResources(int r) { m_totalResource++; }

	//����쳣�����ٽ������쳣���� ��������������ʵ�ֳ����쳣ʱ Ҳ��unlock
	//�Զ���Lock�� �ڹ���ʱ����lock������������unlock

	//ʹ�� mutex���ṩ��Lock std::lock_guard<std::mutex>
	//ʹ������ԭ���� ���ܽ���Զ���Lock���ܽ��������
};
int work(int a) {
	return a + a;
}
template<class Iter>
void realWork(Counter& c, double& totalValue, Iter b, Iter e) {
	for (; b != e; ++b) {
		totalValue += work(*b);
		//�ṩmutex�ӿڵĴ���
		//���ǵ���unlock����������
		//��������lock֮��û�е���unlock����������
		//��lock�󣬳�������쳣�����񣬵���û�ܵ���unlock����������
		//c.lockMutex();
		//c.addCount();
		//c.addResources(1);
		//c.unlockMutex();
		c.addCountAndResources(1);
	}
}

bool printStep(Counter& c, int maxCount) {
	auto count = c.count();
	//c.lockMutex();
	auto ave = c.aveResources();
	if (ave != 1) std::cout << "has bad thing happended\n";
	//c.unlockMutex();
	if(count == maxCount) {
		std::cout << "ok finished\n";
		return true;
	}
	return false;
}

void threadSync() {
	std::vector<int> arr;
	arr.reserve(10000000);
	for (int i = 0; i < 10000000; i++)
	{
		arr.push_back(rand() % 100);
	}
	double totalValue = 0;
	Counter counter;
	realWork(counter, totalValue, arr.begin(), arr.end());
	std::cout << "total times" << counter.count() << " " << totalValue << "\n";

	/*totalValue = 0;
	Counter counter2;
	auto iter = arr.begin() + (arr.size() / 3);
	auto iter2 = arr.begin() + (arr.size() / 3 * 2);
	auto end = arr.end();
	std::thread a([&counter2, &totalValue, iter, iter2]
		{realWork(counter2, totalValue, iter, iter2); });
	std::thread b([&counter2, &totalValue, iter2, end]
		{realWork(counter2, totalValue, iter2, end); });
	realWork(counter2, totalValue, arr.begin(), iter);
	a.join();
	b.join();
	std::cout << "total timers multithread " << counter2.count() << " " << totalValue << "\n";*/

	//(1) ���û�б�Ҫ�Ļ����̼߳䲻��Ҫ������Դ
	/*totalValue = 0;
	double totalValue2 = 0;
	double totalValue3 = 0;
	Counter counter3;
	Counter counter4;
	Counter counter5;
	std::thread d([&counter3, &totalValue, iter, iter2] 
		{realWork(counter3, totalValue, iter, iter2); });
	std::thread e([&counter4, &totalValue2, iter2, end] 
		{realWork(counter4, totalValue2, iter2, end); });
	d.join();
	e.join();
	realWork(counter5, totalValue3, arr.begin(), iter);
	int count = counter3.count() + counter4.count() + counter5.count();
	double total = totalValue + totalValue2 + totalValue3;
	std::cout << " timers " << count << " " << total << "\n";*/

	//(2)ʹ��ͷ�ļ� atomic ��ԭ�Ӳ���
	totalValue = 0;
	Counter counter2;
	auto iter = arr.begin() + (arr.size() / 3);
	auto iter2 = arr.begin() + (arr.size() / 3 * 2);
	auto end = arr.end();
	std::thread a([&counter2, &totalValue, iter, iter2]
		{realWork(counter2, totalValue, iter, iter2); });
	std::thread b([&counter2, &totalValue, iter2, end]
		{realWork(counter2, totalValue, iter2, end); });
	realWork(counter2, totalValue, arr.begin(), iter);

	while (true) {
		if (printStep(counter2, 10000000)) {
			break;
		}
		else {

		}
	}

	a.join();
	b.join();
	std::cout << "total timers multithread " << counter2.count() << " " << totalValue << "\n";

	//(3)���ԭ�Ӳ������ֵ����� mutex���ٽ��壩

}
#pragma endregion





int main() {

	//unsigned int n = std::thread::hardware_concurrency();
	//std::cout << n << "\n";
	//
	//MultiThreadTest();


	threadSync();

	system("pause");
	return 0;
}