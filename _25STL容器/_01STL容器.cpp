#include <iostream>
using namespace std;
#include <array>
#include <vector>
#include <deque>
#include <cstring>


template<class T>
void containerAllInterface(T& a, T& b) {
	T c; //声明
	T d(a); // copy 
	T e = a; // copy
	T f(move(e)); // 转移完后，e中不存在元素
	auto iterB = b.begin();
	auto iterE = b.end();
	T g(iterB, iterE);//copy
	b.size();// 容器中的元素个数 forward_list不提供
	b.empty();// b.size() == 0
	b.max_size();//容器能装下的最大数量元素

	if (b == c) {
		//先比较元素个数
		//在比较元素
	}

	if (b != d) {}//！（b == c）

	if (b < e) {}//unordered_set unordered_map 等不可比较

	e = b;// = 赋值重载
	e = moev(b);
	e.swap(g);//array 是线性的；其余的是01
	swap(e, g);// 01 除了array

	e.cbegin(); // -> const_iterator
	e.cend();
	auto ea = e.cbegin();
	auto eaa = e.begin();
	// *ea -> const &
	// *eaa -> cosnt &(当是一个const 容器的时候), &

	e.clear();//清空 元素都会调用析构函数 array没有
}

//array 容器
void arrayPart() {
	/*
		array 实际上是对c/c++语言中原生数组进行的封装
		namespace std{
			template<class T, size_t N>
			class array;
		}
		特点：内存分配在栈（stack），绝对不会重新分配，随机访问元素
	*/
	int abc[100];
	array<int, 100> a;
	array<int, 100> b = {};//进行初始化

	array<int, 5> obj = { 1,2,3,4,5 };
	array<int, 5> obj2 = { 1,0 };//后面补0

	//interface
	a.empty();
	a.size();
	a.max_size();
	// operator == < != > <= >=
	auto aa = a;
	aa.swap(a);
	swap(aa, a);

	//访问元素
	a[1];//不会检查下标
	a.at(1);//检查下标是否合法 不合法时抛出异常
	a.front();//第一个元素
	a.back();//最后一个元素

	//迭代器相关
	a.begin();
	a.end();//指向的是容器最后一个元素的下一个元素
	a.cbegin();
	a.cend();
	a.rbegin();//从尾开始
	a.rend();//到头

	//和c的接口互用
	array<char, 100> carr;
	strcpy(&carr[0], "hello world!\n");//建议使用 carr.data()
	strcpy(carr.data(), "hello world!\n");

	//特殊
	carr.fill(0);//将容器中的所有元素 赋值为0

	//异常
	// c.at(pos);
	// copy move swap
}

void vectorPart() {
	/*
		vector 是c++98中引入的动态数组（dynamic array）
		namespace std{
			template<class T, typename Allocator = allocator<T> >
			class vector;
		}
		特点随机访问元素，末端添加删除元素效率高。前端和中间删除和添加元素效率低。
		存在当前容器大小和容量的关系
		内存紧凑
	*/
	using Group = vector<float>;

	Group a;//定义容器
	Group b = a;// 拷贝构造
	Group c(a);//拷贝构造
	Group d(10);//开辟大小为10 的容器
	Group e(10, 1.0f);//开辟大小为10 所有元素都为1.0f
	Group f(e.begin(), e.end());
	Group g({ 1.0f, 2.0f, 3.0f });
	Group h = { 1.0f,2.0f, 3.0f };//c++11 initialize list

	d.empty();
	d.size();
	d.max_size();//相对于其他container 返回值相对要小 除了array
	d.capacity();
	d.reserve(100);//预留空间
	d.shrink_to_fit();
	//operator == != < > <= >=

	//赋值
	b = g;
	b.assign(g.begin(), g.end());
	b.assign(3, 1.0f);//{ 1.0f, 2.0f, 3.0f }
	b.assign({ 1.0f, 2.0f, 3.0f });

	//交换
	b.swap(a);
	swap(b, a);

	//元素访问
	b[0];
	b.at(0);// exception out_of_range
	if (b.empty()) {
		b.front();//undefine 出错时是未定义的
		b.back();//undefine 出错时是未定义的
	}

	//迭代器相关
	a.begin();
	a.end();
	a.cbegin();
	a.cend();
	a.rbegin();
	a.rend();
	a.crbegin();
	a.crend();

	a.pop_back();// 可能会出错， undefine
	//single thread 
	//multithread maybe wrong
	if (a.empty())a.pop_back();

	//删除元素
	auto iterAfter = b.erase(b.begin());//返回删除这个元素的下一个位置，没有则为end
	iterAfter = b.erase(b.begin(), b.end());//需要检查迭代器是否失效

	b.push_back(10.0f);//尾插入
	b.pop_back();//尾删
	auto iter = b.insert(b.begin(), 10);//返回这个元素的迭代器
	iter = b.insert(b.end(), h.begin(), h.end());//插入一个区间，返回个这区间第一个元素的迭代器
	b.emplace(b.end(), 10.0f);//c++11 插入元素
	b.emplace_back(10.0f);// 在尾部进行插入

	b.resize(10);//如果原来的容器元素多于10,则多余的元素都被干掉了
	b.resize(100, 10);//生成出来的元素 赋值为 10
	b.resize(100000);
	b.clear();// 清空容器， 但它的capacity不会降低
	b.shrink_to_fit();//告诉容器，你可以降低capacity了 C++11

	//和c的接口互用
	vector<char> carr(100, 0);
	strcpy(carr.data(), "hello world");
	printf("%s", carr.data());

	//异常
	// (1) push_back
	// (2) 元素move/copy没有异常的话，insert emplace emplace_back push_back也不会有异常
	// (3) pop_back
	// (4) 元素move/copy 没有异常的话， erase
	// (5) swap clear

	//绝对不要用 vector存bool remenber
}


void dequePart() {
	/*
		deque 是c++98 中引入的动态数组（dynamic array）
		namespace std{
			template<class T, typename Allocator = allocator<T>>
			class deque;
		}
		特点随机访问元素，末端和头部添加和删除元素效率高，中间添加和删除元素效率低
		元素访问和迭代比vector要慢，迭代器不能是普通的指针
	*/

	using Group = deque<int>;

	Group a; //定义
	Group b = a; // 拷贝构造
	Group c(a); // 拷贝

	Group d(10);
	Group e(10, 1);
	Group f(e.begin(), e.end());
	Group g({ 1,2,3 });
	Group h = { 1,2,3 };

	d.empty();
	d.size();
	d.max_size();
	
	d.shrink_to_fit();//c++11

	//赋值
	b = g;
	b.assign(3, 10);//3 个10
	b.assign(g.begin(), g.end());
	b.assign({ 1,2,3 });

	//交换
	b.swap(g);
	swap(b, g);

	//元素访问
	b[0];
	b.at(0);//检查下标

	//迭代器相关
	b.begin();
	b.end();
	b.cbegin();
	b.cend();
	//。。。

	b.pop_back();// maybe wrong
	if (b.empty()) b.pop_back();

	auto iterAfter = b.erase(b.begin());
	iterAfter = b.erase(b.begin(), b.end());

	b.push_back(10);
	b.pop_back();
	b.push_front(1);
	b.pop_front();
	b.emplace(b.begin(), 1);
	b.emplace_back(10);
	b.emplace_front(1);
	
	auto iter = b.insert(b.end(), 1);
	iter = b.insert(b.end(), 10, -10);//插入 10 个 -10

	b.insert(b.end(), h.begin(), h.end());
	b.resize(10);
	b.resize(100, 10);
	b.clear();
	b.shrink_to_fit();

	//异常
	// (1)push_bakc push_front
	// (2)元素 move/copy 没有异常的话， insert emplace_back push_back emplace_front
	// (3)pop_back pop_front
	// (4)元素 move/copy没有异常的话 erase
	// （5）swap clara
	//

	//deque使用场景
	/*using Buffer = vector<char>;
	using BufferGroup = deque<Buffer>;
	BufferGroup group;
	Buffer buffer;
	auto ok = readFromCline(socket, &buffer);
	if (ok) {
		group.emplace_back(move(buffer));
	}
	else {

	}

	while (!group.empty()) {
		auto ok = sendToClient(socket, group.front());
		if (ok) {
			group.pop_front();
		}
		else {

		}
	}*/
}

int main() {
	//STL是一个框架，将数据结构和算法进一步抽象。
	//容器、算法、迭代器
	//Container
	//1 序列式容器 array\vector\deque\list\forward_list 数组 或者指针
	//2 关联式容器 set\map\multi_map\multi_set 二叉树 红黑树 
	// hash_map\hash_set 
	//3 无顺序容器 unordered_map/unordered_set/unordered_multimap/unordered_multiset
	//
	// stack
	// queue
	// priority_queue(带优先级的队列)
	// string
	// bitset
	// 
	// regex（正则表达式） 
	// thread async future time

	//
	// 容器内元素的条件
	// (1)必须可以复制或者搬移（隐含的条件是在拷贝和搬移的过程中应该没有副作用）
	// (2)元素必须可以被赋值操作来复制或者搬移（因为容器和算法对复写的要求）
	// (3)元素可以被销毁
	// 不同容器的特殊要求
	// 针对于序列式容器，元素必须有默认的构造函数
	// 针对某些操作，元素必须定义 == 
	// 对于关联式容器，排序准则默认的是 < less
	// 无序容器，必须要提供一个hash函数 == 
	// stl容器里面存的是元素的值而不是引用
	//
	// 
	//  
	// STL的设计原则是效率优先、安全为次
	system("pause");
	return 0;
}