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
	为什么使用多线程
	(1) 当前的机器的单线程红利已经结束了
	(2) 多线程拥有自身的优势
	(3) API日益成熟，操作系统和标准库已经支持了多线程
	要在数据IO和计算找到平衡点
	可能的问题：
	 (1) 死锁
	 (2) 乱序
	 (3) 并发访问数据造成的问题
	 (4) 低效率

	 C++11带来的新概念
	 高阶接口：async，future
	 低阶接口：thread mutex
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
	std::thread t(helloThread);//开启一个线程
	for (int i = 0; i < 100; ++i)
	{
		std::cout << "hello main thread" << i << std::endl;
	}

	//开启线程
	//std::thread a([&] {startThreadFunction("a", "b"); });
	//std::thread e(startThreadFunction, std::cref("a"), std::cref("b"));
	//
	//std::thread b(startThreadFunction, "a", "b");//这种方法会调用string的拷贝构造


	//线程的终结 在线程完成工作后结束
	t.join();
}



/*
* 当做的工作很少的话 用单线程会比多线程快 因为开启一个线程也会耗费很多资源
  目前开多线程的话确实会比单线程效率更高
*  把工作分多个线程来执行
*/
double caculate(double v) {
	if (v <= 0)
		return v;
	//让线程休眠 10毫秒
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

	auto mainThread = std::this_thread::get_id();//获取当前线程的ID
	std::vector<double> v;
	for (int i = 0; i < 1000; i++)
	{
		v.push_back(rand());
	}
	std::cout << v.size() << "\n";
	double value = 0.0;
	auto nowc = clock();//函数返回自程序开始执行到当前位置，处理器走过的时钟打点数 1毫秒
	for (auto& info : v) {
		value += caculate(info);
	}
	auto finishc = clock();
	std::cout << "single thread :" << value << "used " << (finishc - nowc) << std::endl;

	nowc = clock();
	auto iter = v.begin() + (v.size() / 2);
	double anotherv = 0.0;
	auto iterEnd = v.end();
	//开启一个线程 计算前后部分
	std::thread s([&anotherv, mainThread, iter, iterEnd]() {
		anotherv = visitRange(mainThread, iter, iterEnd, caculate);
		});
	//在主线程计算 前半部分
	auto halfv = visitRange(mainThread, v.begin(), iter, caculate);

	//此时 线程必须完成工作才能 继续
	s.join();
	finishc = clock();
	std::cout << "multithread:" << (halfv + anotherv) << "used " << (finishc - nowc) << std::endl;
}

#pragma region 线程同步
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
	//提供接口出来是一种错误做法 比如：忘记调用 unlock 调用两次lock等 
	//并且 一旦在lock后，unlock前抛出异常，则会死锁
	//void lockMutex() { m_mutex.lock(); }
	//void unlockMutex() { m_mutex.unlock(); }
private:
	//使用 atomic实现的原子操作 
	//int m_count;
	//std::atomic<int> m_count;
	int m_count;
	//atomic 的缺陷 当存在两个原子操作时
	//并且在函数中同时使用这两个原子操作的话 也是会存在着 问题。
	int m_totalResource;

	//使用头文件 mutex 应该让其为mutable变量，因为要让其在const函数中lock
	mutable std::mutex m_mutex;

	//建议不用把临界区接口暴露出去，直接在类中使用 ，此时还没有解决临界区中异常的问题
	//void lockMutex() { m_mutex.lock(); }
	//void unlockMutex() { m_mutex.unlock(); }
	void addCount() { m_count++; }// 写入寄存器 寄存器+1 写入内存
	void addResources(int r) { m_totalResource++; }

	//解决异常问题临界区中异常问题 利用析构函数来实现出现异常时 也会unlock
	//自定义Lock类 在构造时调用lock，在析构调用unlock

	//使用 mutex中提供的Lock std::lock_guard<std::mutex>
	//使用它的原因是 它能解决自定义Lock不能解决的问题 下面的银行问题
};

//自己实现的 Lock类 构造时 lock 析构时 unlock
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
		//提供mutex接口的错误
		//忘记调用unlock，程序死锁
		//调用两次lock之间没有调用unlock，程序死锁
		//在lock后，程序出现异常并捕获，但还没能调用unlock，程序死锁
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

	//使用多线程来计算 此时却得不出正确答案 原因：线程之间共享了 Counter对象，并且Counter对象并没有实现线程同步
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

	//(1) 如果没有必要的话，线程间不需要共享资源。 使用不同的对象在不同的线程中执行相同的事情，最后到主线程中汇总即可
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

	//(2)使用头文件 atomic 的原子操作 std::atomic<int> 、std::atomic_int 等
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

	while (true) {//通过这个例子 指出了 原子操作的缺陷 引出mutex
		if (printStep(counter2, 10000000)) {
			break;
		}
		else {

		}
	}

	a.join();
	b.join();
	std::cout << "total timers multithread " << counter2.count() << " " << totalValue << "\n";*/

	//(3)解决原子操作出现的问题 mutex（临界体）
}

//自己实现时的银行问题
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


	//使用标准库 std::lock(mutex1,mutex2,...);
	std::lock(a.Mutex, b.Mutex/* ... */);//当完全锁住后才往下执行 按照顺序 不管怎么传参
	//std::lock_guard<std::mutex> lock(mutex, std::adopt_lock);
	std::lock_guard<std::mutex> lockA(a.Mutex, std::adopt_lock);//告诉它不要在构造时再锁啦
	std::lock_guard<std::mutex> lockB(b.Mutex, std::adopt_lock);
	if (a.Balance <= money) return;
	a.Balance -= money;
	b.Balance += money;
}
/* 多线程中 会出现的问题
	BankAccount alice(100);
	BankAccount bob(100);
	thread 1
	transferMoney(alice, bob,10);//when call lockB 在线程1锁住alice的时候 线程2也刚锁住bob 这时候线程1往下执行 发现bob被锁住了 
	线程2往下执行发现alice被锁住了这时候进入死锁
	thread 2
	transferMoney(bob, alice,10);//when call lockA

	如何解决呢？自己实现（让线程锁定的顺序是一致的，如比较地址大小）
	利用系统提供的 std::lock() 实现
*/
#pragma endregion

#pragma region Thread 的死法
//对于thread，生成之后自己管理， 生成之后不管了都是合理的，所以不按照C++的构造析构来设计
class Object {
public:
	Object() { std::cout << "hello"; }
	~Object() { std::cout << "world!"; }
};

void joinWorker() {
	Object o;
	//std::this_thread::sleep_for(std::chrono::seconds(1));//线程休眠1秒钟
}
//自己实现 类来管理 线程 从而解决出现异常时的情况
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
	//当 只开启一个线程后 不在管理它时 当函数结束后会调用 abort()程序中止
	//Object o;

	std::thread a(joinWorker);
	ThreadGuard j(a);//此时程序正常运行

	std::thread b(detachWorker);
	//std::this_thread::sleep_for(std::chrono::seconds(1));
	b.detach();//此时如果 主函数执行完毕后，线程也随之终止，但线程的函数是否执行完毕是未知的
	//detach() 函数让线程自动管理，

	// 自己管理线程
	//if (b.joinable()) {//当线程还未关闭时 则关闭
	//	b.join();
	//}
}

#pragma endregion

#pragma region 线程的时间 的交互
std::mutex _mutex;
std::atomic<bool> ready{ false };
void _worker(int i) {
	//废操作 空的while会占用大量的CPU资源
	while (!ready)
	{
		//std::this_thread::yield();//把资CPU源释放 当开启的线程数 比建议的线程数多时，此方法是不管用的
		std::this_thread::sleep_for(std::chrono::seconds(1));//可以有效降低占用率，但不是很好的方法
	}
	//线程不安全
	//std::cout << i << " info\n";
	//实际上是： std::cout .opeator<<(i) std::cout .operator<<("info")

	//线程安全
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

//引出的问题 如何解决循环中使用了共享数据的同步操作

//单线程版本
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

//多线程版本
std::mutex mutex_;//锁
std::atomic<bool> ready_{ false };//原子操作
std::atomic<bool> quit_{ false };
std::list<Message> multiList;//消息列表

void worker_(int i) {
	while (!ready_) {
	}
	while (!quit_)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1));//线程消息1毫秒
		std::lock_guard<std::mutex> lock(mutex_);
		if (multiList.empty()) continue;//如果消息列表不为空 则跳过本次循环
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
		std::this_thread::sleep_for(std::chrono::milliseconds(1));//这个等待时间是我们不能确定的，我们不能知道等待这个时间会让效率提供或者降低
		//因此才引入了condition_Variable
		std::lock_guard<std::mutex> lock(mutex_);
		multiList.push_back(std::string("second"));
	}

	while (true) {
		std::lock_guard<std::mutex> lock(mutex_);//因为消息列表时线程之间共享的资源，在使用时需要将它锁住
		if (multiList.empty()) {
			quit_ = true;
			std::cout << "quit\n";
			break;
		}
	}

	for (auto& thread : pool)//自己管理线程
	{
		if (thread.joinable()) {
			thread.join();
		}
	}
	auto finish = clock();
	std::cout << "total times " << (finish - now) << "\n";
}


//线程间正确的传递信号 condition_variable 头文件
std::mutex mutex_1;
std::condition_variable cv;//条件变量 
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
			std::unique_lock<std::mutex> lock(mutex_1);//不使用lock_guard是因为 它不能实现下面的代码
			cv.wait(lock, [] {return quit_1 || !conditionList.empty(); });//此时会释放lock，并且等待后面的条件，如果条件达成
			//则重新锁住后 继续往后执行
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
		cv.notify_one();//随机唤醒一个线程  让其处理
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
*  总结：
*	使用的头文件 thread atomic mutex
*	thread 用于开启线程
*	atomic 原子操作	std::atomic_int
*	mutex 临界区 std::mutex
*
*	线程之间的通信
*	使用conditionVariable 的消息通知可以有效的解决 线程无效操作的问题 通过消息通知来解决
*/



int main() {

	//unsigned int n = std::thread::hardware_concurrency();//建议的线程数
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