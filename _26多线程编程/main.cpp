#include <iostream>
#include <thread>
#include <vector>
#include<chrono>
#include <cmath>

#include <atomic>
#include <mutex>

/*
	为什么使用多线程
	(1) 当前的机器的单线程红利已经结束了
	(2) 多线程拥有自身的优势
	(3) API日益成熟，操作系统和标准库已经支持了多线程
	要在数据IO和计算找到平衡点
	可能得问题：
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
  目前开多线程的话确实会有两倍的效率
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

	auto mainThread = std::this_thread::get_id();
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

#pragma region //线程同步
template<class T>
class Lock {
public:
	Lock(T& mutex) :m_mutex{ mutex } { m_mutex.lock(); }
	~Lock() { m_mutex.unlock(); }
private:
	T& m_mutex;
};
//自己实现时的银行问题
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


	//使用标准库
	std::lock(a.Mutex, b.Mutex/* ... */);//当完全锁住后才往下执行 按照顺序 不管怎么传参
	std::lock_guard<std::mutex> lockA(a.Mutex, std::adopt_lock);//告诉它不要在构造时再锁啦
	std::lock_guard<std::mutex> lockA(b.Mutex, std::adopt_lock);
	if (a.Balance <= money) return;
	a.Balance -= money;
	b.Balance += money;
}
/* 多线程中 会出现的问题
	BankAccount alice(100);
	BankAccount bob(100);
	thread 1
	transferMoney(alice, bob,10);//when call lockB
	thread 2
	transferMoney(bob, alice,10);//when call lockA

	如何解决呢？自己实现（让线程锁定的顺序是一致的，如比较地址大小）
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
	int m_totalResource;
	//并且在函数中同时调用这两个原子操作的话 也是会存在着 问题。
	
	//使用头文件 mutex 应该让其为mutable变量，因为要让其在const函数中lock
	mutable std::mutex m_mutex;

	//建议不用把临界区接口暴露出去，直接在类中使用 ，此时还没有解决临界区中异常的问题
	void lockMutex() { m_mutex.lock(); }
	void unlockMutex() { m_mutex.unlock(); }
	void addCount() { m_count++; }// 写入寄存器 寄存器+1 写入内存
	void addResources(int r) { m_totalResource++; }

	//解决异常问题临界区中异常问题 利用析构函数来实现出现异常时 也会unlock
	//自定义Lock类 在构造时调用lock，在析构调用unlock

	//使用 mutex中提供的Lock std::lock_guard<std::mutex>
	//使用它的原因是 它能解决自定义Lock不能解决的问题
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

	//(1) 如果没有必要的话，线程间不需要共享资源
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

	//(2)使用头文件 atomic 的原子操作
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

	//(3)解决原子操作出现的问题 mutex（临界体）

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