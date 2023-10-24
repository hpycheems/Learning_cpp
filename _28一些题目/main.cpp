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
	public://�޳�Ա���� 
		using pointer = std::shared_ptr<Object_>;
		//��Ϊ����һ�����麯������Ҫһ��ָ��ָ��ú����� x64 sizeof() = 8; x86 sizeof() = 4
		virtual std::string debugName() const = 0;//���麯�� �����Ϊ������ 
		virtual ~Object_() {}
	};
	class RealObject :public Object_ {
	public://�޳�Ա���� 
		std::string debugName() const { return "RealObject"; }
		~RealObject() { std::cout << "bey\n"; }
	};
	void testObject(const Object_& obj) {
		std::cout << obj.debugName()<<"\n";
	}
	//������ʲô����ô�� Ϊʲô
	void testCase() {
		RealObject obj;//������һ������
		testObject(obj);
		std::shared_ptr<Object_> pObj = std::make_shared<RealObject>();//�����ڶ�������
		testObject(*pObj);
		std::unique_ptr<Object_> uObj = std::make_unique<RealObject>();//��������������
		testObject(*uObj);
		//�������� ���� uObj���������õ���Object������ pObj�������õ���RealObject�������� 
		//Υ��C++�����̳еĻ���ԭ�� �������������У�����������Ҫ�����
		
		//��������Ϊ �����������ж�û��ʲô
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
	//forC forNew��Щ������ɶ���� ����printIntGroup�����׳��쳣�󣬷����ڴ�й¶
	void forC() {
		int* intGroup = (int*)malloc(sizeof(int) * 10);//���⣺����malloc�ķ���ֵһ��Ҫ���
		if(intGroup)
			printIntGroup(intGroup, 10);
		free(intGroup);
		std::cout << "free intGroup" << std::endl;
	}
	void forNew() {
		int* intGroup = new int[10];
		printIntGroup(intGroup, 10);
		delete[] intGroup;//deleteӦ�����������ʽ
	}

	//���´�����ɶ���� ָ�봫����ǿ���
	void remakeRoom(int* p, size_t size) {
		p = (int*)malloc(sizeof(int) * size);//�������Դ�Ǵ��������ļ� й¶��
	}
	void testRemakeRoom() {
		const int size = 3;
		int* p = (int*)malloc(sizeof(int) * size);
		if (p) {
			if (size < 10)
				remakeRoom(p, 10);//�������ָ�룬 ֻ��ָ��ָ������ݸı�ʱ�Ż�ӳ�䵽ԭ��������
		}
		free(p);//��ʱ�ͷŵ�ֻ�� �ڸú������ٵ��ڴ�
	}

	const char* nameInfo() {
		char info[] = "this is a test";//�ֲ����� ���������󣬾ͻᱻ�ͷŵ��ˣ����ص�ָ��Ҳ��ΪҰָ��
		return info;
	}

	void testInfo() {
		std::string info;
		if (info.empty()) info = nameInfo();
		//�������ʲô��Ϣ��
		std::cout << info << std::endl;
	}
#pragma endregion

#pragma region Iterator
	void printRange() {
		std::set<int> group;//set �����Ԫ�� Ĭ�ϵ���������
		for (int i = 0; i < 100; i++)
		{
			group.insert(rand() % 100);
		}
		auto pos30 = group.find(30);//����Ҳ���������£� ���ص��� end()
		auto pos50 = group.find(50);//���� *end() ��һ�������ڵ���
		//���Һ󷵻صĵ�������Ҫ��� ��=end()
		for (; pos30 != pos50; ++pos30)// ���ڵ�����++ʹ��ǰ�õ���ʽ
		{
			std::cout << "info" << *pos30 << std::endl;//��� pos30��end() ������� ��++ �û�ʹ���������cannot dereference end ma/set iterator��
		}
	}
	
	//ɾ�������ض���ֵ
	template<class T>
	void removeAllSameValue(std::vector<T>& group, T value) {
		//���ʵ��
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
		//stl remove() �������ڵ�Ԫ�� �����ƶ� ��󷵻ص�һ��Ҫ�ɵ���Ԫ�صĵ�����
		group.erase(std::remove(group.begin(), group.end(), value), group.end());
	}
	void testRemoveAllSameValue() {
		std::vector<int> group;
		for (int i = 0; i < 1000; i++)
		{
			group.push_back(rand() % 10);
		}
		auto s = group.size();
		std::cout << "ԭ����Ԫ�ظ���" << s << std::endl;
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
		//��ô�ж��Ƿ��� ѭ������
		//������ͷ�ĵ�ַ��¼
		
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
		//�������ܲ� һ����һ�㣬һ����һ�㣬����������ʱ�������������Բ��
		auto nextNext = next->next;
		while (next && nextNext) {
			if (next == nextNext) {//��ʱ��������
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
		for (int i = 0; i < 10; i++)//����Ƿ�ѭ������
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
		
		for (int i = 0; i < 10; i++)//�����ѭ������
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
		// ����� b �� c��ʲô ����Ľ����Ψһ Ϊʲô  b = � c = �� Ϊʲô�أ�
		std::cout << "b = " << b << " "<< "c = " << c << std::endl;
	}

	// hand write foreach
	template<class Container, class Func>
	void foreach(Container& c, Func func) {
		//�����д��
		std::for_each(c.begin(), c.end(), func);
		std::for_each(std::begin(c), std::end(c), func);
		//���ڵ�������˵�� ��ʹ�ñȽ� ���ҿ��԰�c.end()�����
		for (auto iter = c.begin(); iter < c.end(); iter++) {// iter++�᷵��һ�������� ����ʹ��ǰ�õ�����
			func(*iter);
		}
	}
	// have some not "right use" 1 2 3 4  2
}
#pragma endregion


#pragma region algorithm
//�ж��Ƿ��ǻ���
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
	//���ط� 
	// �շ���0
	if (!buffer) return 0;
	// ֻ��һ���ַ�����1
	if (std::strlen(buffer) == 1) return 1;
	// ����ѭ���ж�
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

	//������ɢ

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
	if ((end - start) % 2 == 1) {//�������
		middlePart = huiwensize(buffer, header, bottom, middle, middle + 1);
	}
	else {//ż�����
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
		ObjectA(int c) :m_value(new int(c)) {//����׳��쳣
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
			//ObjectA �� B �����ʱ������׳��쳣
			//����׳��쳣 Object���ı�
			//���׳��쳣�� a��b����


			//����������ܻ��׳��쳣������׳��쳣 a��b�������ı�
			//���� �����ı� 
			//����
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

//�жϻ����Ĵ�С��
void is_big_ro_little_ending() {
	int i = 1;
	if (*(char*)&i == 1) {
		//С��
	}
	else {
		//���
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