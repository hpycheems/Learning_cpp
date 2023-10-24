#include <iostream>
#include <vector>
#include <cmath>
#include <list>
#include <string>

#include<chrono>
#include <thread>
#include <atomic>
#include <mutex>
#include <condition_variable>

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
  Ŀǰ�����̵߳Ļ�ȷʵ��ȵ��߳�Ч�ʸ���
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

	auto mainThread = std::this_thread::get_id();//��ȡ��ǰ�̵߳�ID
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

#pragma region �߳�ͬ��
class Counter {
public:
	void addCountAndResources(int r) {
		std::lock_guard<std::mutex> lock(m_mutex);
		//Lock<std::mutex> lock_(m_mutex);
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
			return 1;
		}
		auto r = m_totalResource / m_count;
		//unlockMutex();
		return r;
	}
	Counter() :m_count{ 0 }, m_totalResource{ 0 } {}
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
	//�����ں�����ͬʱʹ��������ԭ�Ӳ����Ļ� Ҳ�ǻ������ ���⡣
	int m_totalResource;

	//ʹ��ͷ�ļ� mutex Ӧ������Ϊmutable��������ΪҪ������const������lock
	mutable std::mutex m_mutex;

	//���鲻�ð��ٽ����ӿڱ�¶��ȥ��ֱ��������ʹ�� ����ʱ��û�н���ٽ������쳣������
	//void lockMutex() { m_mutex.lock(); }
	//void unlockMutex() { m_mutex.unlock(); }
	void addCount() { m_count++; }// д��Ĵ��� �Ĵ���+1 д���ڴ�
	void addResources(int r) { m_totalResource++; }

	//����쳣�����ٽ������쳣���� ��������������ʵ�ֳ����쳣ʱ Ҳ��unlock
	//�Զ���Lock�� �ڹ���ʱ����lock������������unlock

	//ʹ�� mutex���ṩ��Lock std::lock_guard<std::mutex>
	//ʹ������ԭ���� ���ܽ���Զ���Lock���ܽ�������� �������������
};

//�Լ�ʵ�ֵ� Lock�� ����ʱ lock ����ʱ unlock
template<class T>
class Lock {
public:
	Lock(T& mutex) :m_mutex{ mutex } { m_mutex.lock(); }
	~Lock() { m_mutex.unlock(); }
private:
	T& m_mutex;
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
	if (count == maxCount) {
		std::cout << "ok finished\n";
		return true;
	}
	return false;
}

void threadSync() {
	auto now = clock();
	std::vector<int> arr;
	arr.reserve(10000000);
	for (int i = 0; i < 10000000; i++)
	{
		arr.push_back(rand() % 100);
	}
	double totalValue = 0;
	Counter counter;
	realWork(counter, totalValue, arr.begin(), arr.end());
	auto finish = clock();
	std::cout << "total times " << counter.count() << " " << totalValue << "\n";
	std::cout << "single thread :" << (finish - now) << "\n";

	//ʹ�ö��߳������� ��ʱȴ�ò�����ȷ�� ԭ���߳�֮�乲���� Counter���󣬲���Counter����û��ʵ���߳�ͬ��
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

	//(1) ���û�б�Ҫ�Ļ����̼߳䲻��Ҫ������Դ�� ʹ�ò�ͬ�Ķ����ڲ�ͬ���߳���ִ����ͬ�����飬������߳��л��ܼ���
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
	realWork(counter5, totalValue3, arr.begin(), iter);
	d.join();
	e.join();

	int count = counter3.count() + counter4.count() + counter5.count();
	double total = totalValue + totalValue2 + totalValue3;
	std::cout << " timers " << count << " " << total << "\n";*/

	//(2)ʹ��ͷ�ļ� atomic ��ԭ�Ӳ��� std::atomic<int> ��std::atomic_int ��
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

	while (true) {//ͨ��������� ָ���� ԭ�Ӳ�����ȱ�� ����mutex
		if (printStep(counter2, 10000000)) {
			break;
		}
		else {

		}
	}

	a.join();
	b.join();
	std::cout << "total timers multithread " << counter2.count() << " " << totalValue << "\n";*/

	//(3)���ԭ�Ӳ������ֵ����� mutex���ٽ��壩
}

//�Լ�ʵ��ʱ����������
struct BankAccount {
	BankAccount(int balance) :Balance{ balance } {}
	int Balance;
	std::mutex Mutex;
};
void transferMoney(BankAccount& a, BankAccount& b, int money) {
	//if (&a == &b) return;
	//std::lock_guard<std::mutex> lockA(a.Mutex);
	//std::lock_guard<std::mutex> lockB(b.Mutex);
	//if (a.Balance <= money) return;
	//a.Balance -= money;
	//b.Balance += money;


	//ʹ�ñ�׼�� std::lock(mutex1,mutex2,...);
	std::lock(a.Mutex, b.Mutex/* ... */);//����ȫ��ס�������ִ�� ����˳�� ������ô����
	//std::lock_guard<std::mutex> lock(mutex, std::adopt_lock);
	std::lock_guard<std::mutex> lockA(a.Mutex, std::adopt_lock);//��������Ҫ�ڹ���ʱ������
	std::lock_guard<std::mutex> lockB(b.Mutex, std::adopt_lock);
	if (a.Balance <= money) return;
	a.Balance -= money;
	b.Balance += money;
}
/* ���߳��� ����ֵ�����
	BankAccount alice(100);
	BankAccount bob(100);
	thread 1
	transferMoney(alice, bob,10);//when call lockB ���߳�1��סalice��ʱ�� �߳�2Ҳ����סbob ��ʱ���߳�1����ִ�� ����bob����ס�� 
	�߳�2����ִ�з���alice����ס����ʱ���������
	thread 2
	transferMoney(bob, alice,10);//when call lockA

	��ν���أ��Լ�ʵ�֣����߳�������˳����һ�µģ���Ƚϵ�ַ��С��
	����ϵͳ�ṩ�� std::lock() ʵ��
*/
#pragma endregion

#pragma region Thread ������
//����thread������֮���Լ����� ����֮�󲻹��˶��Ǻ���ģ����Բ�����C++�Ĺ������������
class Object {
public:
	Object() { std::cout << "hello"; }
	~Object() { std::cout << "world!"; }
};

void joinWorker() {
	Object o;
	//std::this_thread::sleep_for(std::chrono::seconds(1));//�߳�����1����
}
//�Լ�ʵ�� �������� �߳� �Ӷ���������쳣ʱ�����
class ThreadGuard {
public:
	ThreadGuard(std::thread& thread) :m_thread{ thread } {}
	~ThreadGuard() { if (m_thread.joinable()) m_thread.join(); }
private:
	std::thread& m_thread;
};
void detachWorker() {
	Object o;
}
void killThreadTest() {
	//�� ֻ����һ���̺߳� ���ڹ�����ʱ ���������������� abort()������ֹ
	//Object o;

	std::thread a(joinWorker);
	ThreadGuard j(a);//��ʱ������������

	std::thread b(detachWorker);
	//std::this_thread::sleep_for(std::chrono::seconds(1));
	b.detach();//��ʱ��� ������ִ����Ϻ��߳�Ҳ��֮��ֹ�����̵߳ĺ����Ƿ�ִ�������δ֪��
	//detach() �������߳��Զ�����

	// �Լ������߳�
	//if (b.joinable()) {//���̻߳�δ�ر�ʱ ��ر�
	//	b.join();
	//}
}

#pragma endregion

#pragma region �̵߳�ʱ�� �Ľ���
std::mutex _mutex;
std::atomic<bool> ready{ false };
void _worker(int i) {
	//�ϲ��� �յ�while��ռ�ô�����CPU��Դ
	while (!ready)
	{
		//std::this_thread::yield();//����CPUԴ�ͷ� ���������߳��� �Ƚ�����߳�����ʱ���˷����ǲ����õ�
		std::this_thread::sleep_for(std::chrono::seconds(1));//������Ч����ռ���ʣ������Ǻܺõķ���
	}
	//�̲߳���ȫ
	//std::cout << i << " info\n";
	//ʵ�����ǣ� std::cout .opeator<<(i) std::cout .operator<<("info")

	//�̰߳�ȫ
	printf("hello world %d\n", i);
}

void threadInteractable() {
	const auto threadCount = 4;
	std::vector<std::thread> pool;
	for (int i = 0; i < threadCount; i++)
	{
		pool.emplace_back(_worker, i);
	}

	std::this_thread::sleep_for(std::chrono::seconds(5));

	ready = true;
	for (auto& thread : pool) {
		if (thread.joinable()) {
			thread.join();
		}
	}
}

//���������� ��ν��ѭ����ʹ���˹������ݵ�ͬ������

//���̰߳汾
class Message {
public:
	const std::string& data()const { return m_data; }
	Message() {}
	Message(std::string std) :m_data{ std::move(std) } {}
private:
	std::string m_data;
};
std::list<Message> globalList;
void workerr() {
	while (!globalList.empty()) {
		auto iter = globalList.begin();
		globalList.erase(iter);
	}
}
void SingleThreadVersion() {
	auto now = clock();
	for (int i = 0; i < 10000; i++)
	{
		globalList.push_back("this is a test" + std::to_string(i));
	}
	workerr();


	for (int i = 0; i < 10000; i++)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
		globalList.push_back(std::string("second"));
	}
	workerr();

	auto finish = clock();
	std::cout << "total times " << (finish - now) << "\n";
}

//���̰߳汾
std::mutex mutex_;//��
std::atomic<bool> ready_{ false };//ԭ�Ӳ���
std::atomic<bool> quit_{ false };
std::list<Message> multiList;//��Ϣ�б�

void worker_(int i) {
	while (!ready_) {
	}
	while (!quit_)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1));//�߳���Ϣ1����
		std::lock_guard<std::mutex> lock(mutex_);
		if (multiList.empty()) continue;//�����Ϣ�б�Ϊ�� ����������ѭ��
		auto iter = multiList.begin();
		multiList.erase(iter);
	}
}
void MultableThreadVersion() {
	auto now = clock();
	const auto threadCount = 4;
	for (int i = 0; i < 10000; i++)
	{
		multiList.push_back("this is a test" + std::to_string(i));
	}
	std::vector<std::thread> pool;
	for (int i = 0; i < threadCount; i++)
	{
		pool.emplace_back(worker_, i);
	}

	ready_ = true;
	std::cout << "ready\n";

	for (int i = 0; i < 10000; i++)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1));//����ȴ�ʱ�������ǲ���ȷ���ģ����ǲ���֪���ȴ����ʱ�����Ч���ṩ���߽���
		//��˲�������condition_Variable
		std::lock_guard<std::mutex> lock(mutex_);
		multiList.push_back(std::string("second"));
	}

	while (true) {
		std::lock_guard<std::mutex> lock(mutex_);//��Ϊ��Ϣ�б�ʱ�߳�֮�乲�����Դ����ʹ��ʱ��Ҫ������ס
		if (multiList.empty()) {
			quit_ = true;
			std::cout << "quit\n";
			break;
		}
	}

	for (auto& thread : pool)//�Լ������߳�
	{
		if (thread.joinable()) {
			thread.join();
		}
	}
	auto finish = clock();
	std::cout << "total times " << (finish - now) << "\n";
}


//�̼߳���ȷ�Ĵ����ź� condition_variable ͷ�ļ�
std::mutex mutex_1;
std::condition_variable cv;//�������� 
std::atomic<bool> ready_1{ false };
std::atomic<int> totalSize = 0;
bool quit_1{ false };
std::list<Message> conditionList;

void worker_1(int i) {
	while (!ready_1) {}
	Message msg;
	while (!quit_1) {
		{
			//std::lock_guard<std::mutex> lock(mutex_1); 
			std::unique_lock<std::mutex> lock(mutex_1);//��ʹ��lock_guard����Ϊ ������ʵ������Ĵ���
			cv.wait(lock, [] {return quit_1 || !conditionList.empty(); });//��ʱ���ͷ�lock�����ҵȴ����������������������
			//��������ס�� ��������ִ��
			if (quit_1)
				return;

			auto iter = conditionList.begin();
			msg = std::move(*iter);
			conditionList.erase(iter);
		}
		totalSize += strlen(msg.data().c_str());
	}
}

void conditionVariableVersion() {
	auto now = clock();
	const auto threadCount = 4;
	for (int i = 0; i < 10000; i++)
	{
		conditionList.push_back("this is a test" + std::to_string(i));
	}

	std::vector<std::thread> pool;
	for (int i = 0; i < threadCount; i++)
	{
		pool.emplace_back(worker_1, i);
	}
	ready_1 = true;
	std::cout << "ready\n";
	for (int i = 0; i < 10000; i++)
	{
		std::lock_guard<std::mutex> lock(mutex_1);
		conditionList.push_back(std::string("second"));
		cv.notify_one();//�������һ���߳�  ���䴦��
	}

	while (true) {
		std::lock_guard<std::mutex> lock(mutex_1);
		if (conditionList.empty()) {
			quit_1 = true;
			cv.notify_all();
			break;
		}
	}

	for (auto& thread : pool) {
		if (thread.joinable())
		{
			thread.join();
		}
	}

	auto finish = clock();
	std::cout << "all times:" << (finish - now) << "\n";
}

#pragma endregion



/*
*  �ܽ᣺
*	ʹ�õ�ͷ�ļ� thread atomic mutex
*	thread ���ڿ����߳�
*	atomic ԭ�Ӳ���	std::atomic_int
*	mutex �ٽ��� std::mutex
*
*	�߳�֮���ͨ��
*	ʹ��conditionVariable ����Ϣ֪ͨ������Ч�Ľ�� �߳���Ч���������� ͨ����Ϣ֪ͨ�����
*/



int main() {

	//unsigned int n = std::thread::hardware_concurrency();//������߳���
	//std::cout << n << "\n";
	//
	//MultiThreadTest();
	//killThreadTest();
	//threadSync();
	//threadInteractable();
	//SingleThreadVersion();
	//MultableThreadVersion();

	conditionVariableVersion();

	system("pause");
	return 0;
}