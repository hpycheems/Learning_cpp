#include <iostream>
#include <set>
#include <vector>
#include <cassert>
#include <algorithm>

namespace Test {

#pragma region Class
	class Empty {
		virtual std::string printName() {}
	};//sizeof() = 1
	class RealEmpty:public Empty {
		std::string printName()const { return "xx"; }
	};
	class Object_ {
	public://无成员变量 
		using pointer = std::shared_ptr<Object_>;
		//因为存在一个纯虚函数，需要一个指针指向该函数， x64 sizeof() = 8; x86 sizeof() = 4
		virtual std::string debugName() const = 0;//纯虚函数 则该类为抽象类 
		virtual ~Object_() {}
	};
	class RealObject :public Object_ {
	public://无成员变量 
		std::string debugName() const { return "RealObject"; }
		~RealObject() { std::cout << "bey\n"; }
	};
	void testObject(const Object_& obj) {
		std::cout << obj.debugName()<<"\n";
	}
	//以下有什么问题么？ 为什么
	void testCase() {
		RealObject obj;//创建第一个对象
		testObject(obj);
		std::shared_ptr<Object_> pObj = std::make_shared<RealObject>();//创建第二个对象
		testObject(*pObj);
		std::unique_ptr<Object_> uObj = std::make_unique<RealObject>();//创建第三个对象
		testObject(*uObj);
		//错误在于 对于 uObj的析构调用的是Object的析构 pObj析构调用的是RealObject的析构， 
		//违反C++派生继承的基本原则 所以在派生类中，析构函数需要是虚的
		
		//不错是因为 它两的析构中都没做什么
	}
#pragma endregion

#pragma region Memory
	void printIntGroup(int* group, size_t size) {
		assert(group);
		for (size_t i = 0; i < size; i++)
		{
			std::cout << group[i] << std::endl;
		}
	}
	//forC forNew这些代码有啥问题 当在printIntGroup函数抛出异常后，发生内存泄露
	void forC() {
		int* intGroup = (int*)malloc(sizeof(int) * 10);//问题：对于malloc的返回值一定要检查
		if(intGroup)
			printIntGroup(intGroup, 10);
		free(intGroup);
		std::cout << "free intGroup" << std::endl;
	}
	void forNew() {
		int* intGroup = new int[10];
		printIntGroup(intGroup, 10);
		delete[] intGroup;//delete应该是数组的形式
	}

	//以下代码有啥问题 指针传入的是拷贝
	void remakeRoom(int* p, size_t size) {
		p = (int*)malloc(sizeof(int) * size);//这里的资源是传不出来的即 泄露掉
	}
	void testRemakeRoom() {
		const int size = 3;
		int* p = (int*)malloc(sizeof(int) * size);
		if (p) {
			if (size < 10)
				remakeRoom(p, 10);//传入的是指针， 只有指针指向的数据改变时才会映射到原来的数据
		}
		free(p);//此时释放的只是 在该函数开辟的内存
	}

	const char* nameInfo() {
		char info[] = "this is a test";//局部变量 函数结束后，就会被释放掉了，返回的指针也称为野指针
		return info;
	}

	void testInfo() {
		std::string info;
		if (info.empty()) info = nameInfo();
		//输出的是什么信息？
		std::cout << info << std::endl;
	}
#pragma endregion

#pragma region Iterator
	void printRange() {
		std::set<int> group;//set 存入的元素 默认递增的排序
		for (int i = 0; i < 100; i++)
		{
			group.insert(rand() % 100);
		}
		auto pos30 = group.find(30);//如果找不到的情况下， 返回的是 end()
		auto pos50 = group.find(50);//并且 *end() 是一个不存在的数
		//查找后返回的迭代器需要检查 ！=end()
		for (; pos30 != pos50; ++pos30)// 对于迭代器++使用前置的形式
		{
			std::cout << "info" << *pos30 << std::endl;//如果 pos30是end() 将其解引 和++ 用会使程序崩溃（cannot dereference end ma/set iterator）
		}
	}
	
	//删除所有特定的值
	template<class T>
	void removeAllSameValue(std::vector<T>& group, T value) {
		//如何实现
		int left = 0, right = group.size();
		while (left < right) {
			if (group[left] == value) {
				group[left] = group[right - 1];
				right--;
			}
			else {
				left++;
			}
		}
		group.resize(left);
		//stl remove() 在区间内的元素 往后移动 最后返回第一个要干掉的元素的迭代器
		group.erase(std::remove(group.begin(), group.end(), value), group.end());
	}
	void testRemoveAllSameValue() {
		std::vector<int> group;
		for (int i = 0; i < 1000; i++)
		{
			group.push_back(rand() % 10);
		}
		auto s = group.size();
		std::cout << "原来的元素个数" << s << std::endl;
		for (auto value : group)
			std::cout << value << " ";
		removeAllSameValue(group, 0);
		auto after = group.size();

		std::cout << "========================================================\n";

		std::cout << "total removed" << (s - after) << std::endl;
		for (auto value : group)
			std::cout << value << " ";
	}
#pragma endregion
}

#pragma region Struct
namespace CStruct {
	struct SList {
		SList* next;
		int value;
	};
	inline bool isCircle(SList* header) {
		//怎么判断是否是 循环链表
		//把链表头的地址记录
		
		/*auto a = header;
		std::cout << a << "\n";
		while (header->next != nullptr) {
			header = header->next;
			if (header == a) {
				return true;
			}
		}
		return false;*/

		if (!header)
			return false;
		auto next = header->next;
		if (!next)
			return false;
		//两个人跑步 一个快一点，一个慢一点，当两个相遇时，则这个操作是圆的
		auto nextNext = next->next;
		while (next && nextNext) {
			if (next == nextNext) {//此时两人相遇
				return true;
			}
			next = next->next;
			nextNext = nextNext->next;
			if(nextNext){
				nextNext = nextNext->next;
			}
		}
		return false;
	}
	void printLink(SList* header) {
		std::cout << header->value << " ";
		while (header->next != nullptr) {
			std::cout << header->value << " ";
			header = header->next;
		}
	}
	//has two state
	
	void testSList() {
		SList* next = nullptr;
		SList* current = nullptr;
		SList* start = nullptr;
		for (int i = 0; i < 10; i++)//这个是非循环链表
		{
			current = new SList;
			current->next = next;
			current->value = i;
			next = current;
			if (!start) start = current;
		}
		//printLink(start);
		auto cir = isCircle(start);
		std::cout << "is or not cir:"<< cir << "\n";

		next = nullptr;
		current = nullptr;
		start = nullptr;
		
		for (int i = 0; i < 10; i++)//这个是循环链表
		{
			current = new SList;
			current->next = next;
			current->value = i;
			next = current;
			if (!start) start = current;
		}
		start->next = current;
		//auto firstElem = start->next;
		//std::cout << firstElem->value << "\n";
		//printLink(start);
		cir = isCircle(start);
		std::cout << "is or not cir:" << cir << "\n";
	}


	void valueTest() {
		char a = 64;// 0100 0000
		char b = a << 1;// 1000 0000 -128
		char c = b >> 1;// 0100 0000 -64
		std::cout << "a = " << a << std::endl;
		// 输出的 b 和 c是什么 输出的结果不唯一 为什么  b = � c = 空 为什么呢？
		std::cout << "b = " << b << " "<< "c = " << c << std::endl;
	}

	// hand write foreach
	template<class Container, class Func>
	void foreach(Container& c, Func func) {
		//最简便的写法
		std::for_each(c.begin(), c.end(), func);
		std::for_each(std::begin(c), std::end(c), func);
		//对于迭代器来说， 不使用比较 并且可以把c.end()提出来
		for (auto iter = c.begin(); iter < c.end(); iter++) {// iter++会返回一个迭代器 所有使用前置迭代器
			func(*iter);
		}
	}
	// have some not "right use" 1 2 3 4  2
}
#pragma endregion


#pragma region algorithm
//判读是否是回文
bool isPalindrome(const char* str, int begin, int end) {
	while (begin <= end)
	{
		if (str[begin] == str[end]) {
			begin++;
			end--;
		}
		else return false;
	}
	return true;
}
int maxHuiwen(const char* buffer) {
	//朴素法 
	// 空返回0
	if (!buffer) return 0;
	// 只有一个字符返回1
	if (std::strlen(buffer) == 1) return 1;
	// 两层循环判断
	int length = std::strlen(buffer);
	int longest = 1;
	for (int i = 0; i < length; i++)
	{
		for (int j = i + 1; j < length; j++)
		{
			if (isPalindrome(buffer, i, j)) {
				longest = longest < j - i + 1 ? j - i + 1 : longest;
			}
		}
	}
	
	return longest;

	//中心扩散

}
int huiwensize(const char* buffer, int header, int bottom, int start, int end);
int maxHuiwenHelper(const char* buffer, int start, int end, int header, int bottom) {
	if (start == end)
		return 1;
	if (start > end) return 0;
	auto middle = (end + start) / 2;
	auto frontPart = maxHuiwenHelper(buffer, start, middle, header, bottom);
	auto endPart = maxHuiwenHelper(buffer, middle + 1, end, header, bottom);
	auto middlePart = 0;
	if ((end - start) % 2 == 1) {//奇数情况
		middlePart = huiwensize(buffer, header, bottom, middle, middle + 1);
	}
	else {//偶数情况
		middlePart = huiwensize(buffer, header, bottom, middle - 1, middle + 1) + 1;
	}
	if (frontPart > endPart) {
		return std::max(frontPart, middlePart);
	}
	else {
		return std::max(endPart, middlePart);
	}
}
int huiwensize(const char* buffer, int header, int bottom, int start, int end) {
	int count = 0;
	while (buffer[start] == buffer[end]) {
		count += 2;
		if (start <= header || end >= bottom) break;
		--start;
		++end;
	}
	return count;
}

// abc -> 1
// aa -> 2
// aba -> 3
// abccba -> 6
// abcdabcdeedcba -> 10
// abaabcddcda -> 8
#pragma endregion

#pragma region exception
namespace Exception {
	class ObjectA {
	public:
		ObjectA(int c) :m_value(new int(c)) {//随机抛出异常
			if (((c + rand()) % 5 == 0)) throw "bad";
		}
		int value() const { return *m_value; }
		void swap(ObjectA& rhs) { std::swap(m_value, rhs.m_value); }
	private:
		std::unique_ptr<int> m_value;
	};
	class ObjectB {
	public:
		ObjectB(int c) :m_value(new int(c)) {
			if (((c + rand()) % 5 == 0)) throw "bad 2";
		}
		int value() const { return *m_value; }
		void swap(ObjectB& rhs) { std::swap(m_value, rhs.m_value); }
	private:
		std::unique_ptr<int> m_value;
	};

	class Object {
	private:
		ObjectA m_a;
		ObjectB m_b;
	public:
		Object() :m_a(rand()), m_b(rand()) {}
		void resetAAndB(int a, int b) {
			//ObjectA 和 B 构造的时候随机抛出异常
			//如果抛出异常 Object不改变
			//不抛出异常， a和b互换


			//这个函数可能会抛出异常，如果抛出异常 a、b不发生改变
			//否则 发生改变 
			//构造
			try
			{
				ObjectA tempA(a);
				ObjectB tempB(b);
				m_a.swap(tempA);
				m_b.swap(tempB);
			}
			catch (const std::exception&)
			{

			}
		}
	};
}
#pragma endregion

//判断机器的大小端
void is_big_ro_little_ending() {
	int i = 1;
	if (*(char*)&i == 1) {
		//小端
	}
	else {
		//大端
	}
}


int main() {
	srand((unsigned int)time(NULL));

	//Test::testInfo();
	//std::set<int> v;
	//v.insert(1);
	//auto pos30 = v.find(30);
	//auto pos31 = pos30++;
	//Test::testRemoveAllSameValue();
	//CStruct::testSList();
	//std::cout << (char)(64 << 1) << std::endl;
	//std::cout << (char)128 << std::endl;
	//Struct::valueTest();

	//std::cout<< maxHuiwen(std::string("abcdabcdeedcba").c_str()) << "\n";
	//Test::testCase();
	//Test::testRemakeRoom();

	//std::cout << sizeof(char) << std::endl;
	char a = 64;
	char b = a << 1;
	std::cout << (int)b << std::endl;
	return 0;
}