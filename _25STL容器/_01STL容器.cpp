#include <iostream>
using namespace std;
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <cstring>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>

#include "Person.h"
#include "Position.h"

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
	//array<char, 100> carr;
	//strcpy(&carr[0], "hello world!\n");//建议使用 carr.data()
	//strcpy(carr.data(), "hello world!\n");

	//特殊
	//carr.fill(0);//将容器中的所有元素 赋值为0

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

	//std::remove(b.begin(), b.end(), 1);
	//和c的接口互用
	//vector<char> carr(100, 0);
	//strcpy(carr.data(), "hello world");
	//printf("%s", carr.data());

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

void listPart() {
	/*
		list 是c++98中引入的双向列 （double linked list）
		namespace std{
			template<class T, typename Allocator = allocator<T>>
		}
		特点不支持随机访问元素， 访问头部和尾部元素速度快
		任何位置插入删除元素都快，常量时间内完成
		插入和删除不会造成迭代器失效
		对于异常支持，出现异常对于list而言，要不成功，要不什么影响都没有
	*/

	using Group = list<float>;

	//构造 
	Group a;
	Group b = a;
	Group c(a);
	Group d(10);
	Group e(10, 1);
	Group f(e.begin(), e.end());
	Group g({ 1,2,3 });
	Group h = { 1,2,3 };

	//interface
	d.empty();
	d.size();
	d.max_size();
	//不提供的接口
	//d.capacity();
	//d.reserve(100)
	//d.shrink_to_fit();
	
	//operator == != < > >= <=

	//赋值 
	a = b;
	b.assign(3, 10);
	b.assign(c.begin(), c.end());
	b.assign({ 1,2,3 });

	//交换
	b.swap(a);
	swap(a, b);

	//元素访问 不能随机访问
	// b[0]
	//b.at(0)
	b.front();
	b.back();

	//迭代器
	b.begin();
	b.end();
	//...
	//迭代器移动
	auto iterBegin = b.begin();
	advance(iterBegin, 4);//移动到第五位
	//next(iterBegin, 1);//此方法也可

	a.pop_back();
	if (!a.empty()) a.pop_back();

	//删除
	b.erase(b.begin());
	b.erase(b.begin(), b.end());

	b.push_back(10);
	b.push_front(10);
	b.pop_back();
	b.pop_front();

	b.emplace(b.begin(), 1);
	b.emplace_back(1);
	b.emplace_front(1);
	auto iter = b.insert(b.end(), 10);
	iter = b.insert(b.end(), 10, 100);
	b.resize(10);
	b.resize(100, 1);

	//算法
	b.remove(1);//移除容器中所有为1的元素
	b.remove_if([](auto v) {return v > 5; });//有条件的移除
	b.reverse();//反转 1 2 3 4 -》 4 3 2 1
	b.sort();//默认 
	//list 不支持 使用通用的 sort 算法 因为不支持随机访问

	g.sort();
	g.merge(b);//合并 必须是有序的

	b.unique();// 元素必须是排好序的 1 1 2 2 3 3 4 4 -》 1 2 3 4
	c.splice(c.begin(), b);// 把b作为一块 接入到 c的某个位置
}

void forward_listPart() {
	/*
		forward_list 是c++11中引入的单向串列（singly linked list）
		namespace std{
		template<class T, typename Allocator = allocator<T>>
		class forward_list;
		}
		特点 不支持随机访问元素，访问头部元素速度快
		任何位置插入删除元素都很快，常量时间内完成
		插入和删除不会造成迭代器失效
		对于异常支持好，出现异常对于forward_list而言，要不成功，要不什么都不会发生
	*/

	using Group = forward_list<float>;

	//构造 
	Group a;
	Group b = a;
	Group c(a);
	Group d(10);
	Group e(10, 1);
	Group f(e.begin(), e.end());
	Group g({ 1,2,3 });
	Group h = { 1,2,3 };

	//interface
	d.empty();
	//d.size(); 不提供size
	d.max_size();
	//不提供的接口
	//d.capacity();
	//d.reserve(100)
	//d.shrink_to_fit();

	//operator == != < > >= <=

	//赋值 
	a = b;

	b.assign(3, 10);
	b.assign(c.begin(), c.end());
	b.assign({ 1,2,3 });

	//交换
	b.swap(a);
	swap(a, b);

	//元素访问 不能随机访问
	// b[0]
	//b.at(0)
	b.front();
	//b.back(); 

	//迭代器
	b.begin();
	b.cbegin();
	b.end();
	b.cend();
	//auto iter = b.before_begin();
	//*iter undefine 
	b.before_begin();
	b.cbefore_begin();
	//迭代器移动
	auto iterBegin = b.begin();
	advance(iterBegin, 4);//移动到第五位
	//next(iterBegin, 1);//此方法也可

	//删除
	b.erase_after(b.before_begin());//return void
	b.erase_after(b.before_begin(), b.end());//return void


	b.pop_front();
	b.emplace_after(b.before_begin(), 1);
	b.push_front(10);
	b.emplace_front(1);
	auto iter = b.insert_after(b.before_begin(), 10);
	iter = b.insert_after(b.before_begin(), 10, 100);
	b.resize(10);
	b.resize(100, 1);

	//算法
	b.remove(1);//移除容器中所有为1的元素
	b.remove_if([](auto v) {return v > 5; });//有条件的移除
	//b.reverse();//反转 1 2 3 4 -》 4 3 2 1
	//b.sort();//默认 
	//list 不支持 使用通用的 sort 算法 因为不支持随机访问
	g.merge(b);//合并 必须是有序的
	b.unique();// 元素必须是排好序的 1 1 2 2 3 3 4 4 -》 1 2 3 4
	//g.sort();
	//c.splice(c.begin(), b);// 把b作为一块 接入到 c的某个位置
	c.splice_after(c.before_begin(), b);

	auto iter_ = b.before_begin();
	//获取位置
	for (int i = 0; i < 2; i++){++iter_;}
	b.insert_after(iter_, 10);
}
// 智能指针中 的坑 不要用 weak_ptr存大量的数据
// 因为 当使用到时 会比 原生的数据 多出 14倍的性能消耗


void serPart() {
	/*
		set multiset 是c++98中引入的二叉树数据结构
		namespace std{
			template<typename T, typename Comapre = less<T>, typename Allocator = allocator<T>>
			class set;
		}

		namespace std{
			template<typename T, typename Comapre = less<T>, typename Allocator = allocator<T>>
			class multiset;
		}
		特点自动将元素排序
		插入和删除必须支持严格的若顺序
		(1) x < y == true, y < x == false
		(2) x < y == true, y < z == true , x < z == true
		(3) x < x === false
		(4) a == b, b== c , c== a
		不能改变元素的值

		辅助类
		namespace std{
			template<typename T1, class T2>
			struct pair{
				T1 first,
				T2 second;
			}
		}

		当存储的是自己实现的类的时候，需要提供一个比较的类来让容器知道按照什么对容器中的元素进行排序
		并且容器中的元素是不可变的，即 const
		当查找指定元素时，可能会出错
		可以通过重载 == 使用stl提供的 find方法
	*/
	using Group = set<int>;

	Group a;//默认构造
	Group b = a;//拷贝构造
	Group c(a);//拷贝构造
	Group e(c.begin(), c.end());//copy
	Group f({ 1,2,3 });	 // C++11
	Group g = { 1,2,3 }; // C++11

	//interface
	c.empty();
	c.size();
	c.max_size();
	//operator == != < > <= >=
	//不常用
	auto keycomp = c.key_comp();
	auto valuecomp = c.value_comp();

	//赋值
	g = b;

	//交换
	b.swap(c);//如果存在提供的交换函数，建议使用提供的交换函数，因为效率比较高
	swap(a, b);

	//迭代器
	b.begin();
	b.end();
	//...

	//算法
	auto num = a.count(1);//统计
	auto findIter = a.find(1);//查找 返回查找到的元素的迭代器 否则返回end()
	if (findIter == a.end()) {
		
	}
	else {
		*findIter;
	}

	auto lower = a.lower_bound(1);// >= 返回插入的位置
	auto upper = a.upper_bound(1);// >
	auto range = a.equal_range(1);// return make_pair(a.lower_bound(1), a.upper_bound(1))

	//插入 删除
	auto eraseInter = b.erase(b.begin());
	eraseInter = b.erase(c.begin(), c.end());
	b.clear();

	auto state = b.insert(1000);//state is a pair = make_pair<iterator,bool> 返回的是一个 pair first为迭代器 second为是否插入成功
	b.emplace(10);
	b.emplace_hint(b.end(), 1);
}

void mapPart() {
	/*
		map multimap 是C++98中引入的二叉树数据结构
		namespace std{
			template<typename Key, typename T, typename Compare = less<Key>, 
			typename Allocator = allocator<pair<const Key, T>>>
			class map;

			template<typename Key, typename T, typename Compare = less<Key>,
			typename Allocator = allocator<pair<const Key, T>>>
			class multimap;
		}
		特点自动将元素排序
		插入和删除查找O(logn)
		插入key元素必须支持严格的弱顺序
		(1) x < y == true, y < x == false
		(2) x < y == true, y < z == true , x < z == true
		(3) x < x === false
		(4) a == b, b== c , c== a
		不能改变Key元素的值
	*/
	using Group = map<int, string>;

	Group a;//默认构造
	Group b(a);//拷贝构造
	Group c = a;//拷贝构造
	Group d(a.begin(), a.end());//copy
	Group e({ {1,"l" },{2,"k"},{3,"x"} });//C++11

	d.empty();//是否为空
	d.size();//容器中元素个数
	d.max_size();
	//opeator == != < > <= >=
	//不太会用到
	auto keycomp = c.key_comp();//返回一个比较键的函数对象
	auto valuecomp = c.value_comp();//返回一个比较只的函数对象

	//赋值
	b = c;

	//交换
	b.swap(c);
	
	//迭代器
	a.begin();
	a.end();

	auto num = a.count(1);// 按照key来统计 统计
	auto findIter = a.find(1);//按照key来查找 查找
	if (findIter == a.end()) {

	}
	else {
		std::pair<int, std::string> obj;
		obj = *findIter;//这个操作会消耗比较多的性能 因为 int 和 const int 不同 需要重新拷贝一份
		//*findIter // std::pair<const int, string>&
	}

	auto lower = a.lower_bound(1);// 返回一个插入位置 >=
	auto upper = a.upper_bound(1);// 返回一个插入位置 >
	auto range = a.equal_range(1);//return std::make_pair(a.lower_bound(1), a.upper_bound(1))

	//删除 和插入
	auto eraseIter = b.erase(b.begin());
	eraseIter = b.erase(b.begin(), b.end());
	auto state = b.insert(std::make_pair(100, "good"));

	//auto insertIter = b.insert(c.begin(), c.end());
	b.emplace(std::make_pair(1, "ll"));
	b.emplace(11, std::string("a"));// b.emplace(std::pair<const int,std::string(10,"a")>)
	b.emplace(29, "asd");//b.emplace(std::pair<const int, std::strnig(10,"thrid")>);
	b.emplace_hint(b.begin(), std::make_pair(10, "p"));

	//访问元素
	//[]
	//auto string
	auto& info = b[10];
	// []-> auto iter = b.insert(std::make_pair(13, std::string())).first; return (*iter).second
	b[13];//查找不成功时 会自动创建一个元素 并且使用默认构造函数， 

	//at //出错则会抛出异常
	try {
		auto& findInfo = b.at(10);
	}
	catch (...) {

	}

	//建议的访问方式
	auto findIter_ = b.find(10);
	if (findIter_ != b.end()) {
		auto& b = (*findIter_).second;
	}
	else {

	}
}

void unorderSetAndMap() {
	/*
		unordermulti_set unorder_set
		unordermulti_map unorder_map
		是C++11中 以hash table为基础的，内部元素没有明确顺序的容器
		namespace std{
			template<typename Key, typename T, typename Hash = hash<Key>, typename EqPred = equal_to<Key>,
			typemane Allocator = allocator<pair<const Key, T>>>
			class unorder_map;

			template<typename Key, typename T, typename Hash = hash<Key>, typename EqPred = equal_to<Key>,
			typemane Allocator = allocator<pair<const Key, T>>>
			class unorder_multimap;

			template<typename T, typename Hash = hash<Key>, typename EqPred = equal_to<Key>,
			typemane Allocator = allocator<pair<T>>>
			class unorder_set;

			template<typename T, typename Hash = hash<Key>, typename EqPred = equal_to<Key>,
			typemane Allocator = allocator<pair<T>>>
			class unorder_multiset;
		}
		插入和删除查找O(1)
		不能改变Key元素的值
	*/
	using Group = std::unordered_map<Position, Person>;
	Group a;

}
//使用unorder_map存储自定义的类
//此时需要提供一个模板类的特化
//写在类中

int main() {
	//serPart();
	//set<int> s{2,3,1,4};
	//for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	//{
	//	cout << *it << " ";
	//}
	//cout << "\n";
	//auto itre = s.lower_bound(3);//返回的是要插入位置的迭代器
	//for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	//{
	//	cout << *it << " ";
	//}
	//cout << "\n";
	//cout << *itre << endl;

	vector<int> v = { 1,2,2,3,4,4,5,6,7,8,8 };
	std::remove(v.begin(), v.end(), 4);
	for (auto value : v) {
		std::cout << value << " ";
	}


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
	// bitset 用于存储 bool
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