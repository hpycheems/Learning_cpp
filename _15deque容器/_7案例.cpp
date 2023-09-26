#include<iostream>
using namespace std;
#include <deque>
#include <vector>
#include <algorithm>

class Person {
public:
	Person() {}

	string m_Name;
	int m_Score;
};

void createPerson(vector<Person>& q) {
	string name = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		Person p;
		p.m_Name = "选手";
		p.m_Name += name[i];
		p.m_Score = 0;
		q.push_back(p);
	}
}

void printDeque7(deque<int> d) {
	for (deque<int>::iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void setScore(vector<Person>& q) {
	for (vector<Person>::iterator it = q.begin(); it != q.end(); it++)
	{
		deque<int> scores;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;
			scores.push_back(score);
		}
		
		//cout << it->m_Name << "的打分" << endl;
		//printDeque7(scores);

		sort(scores.begin(), scores.end());
		scores.pop_back();
		scores.pop_front();

		int sum = 0;
		for (deque<int>::iterator it = scores.begin(); it != scores.end(); it++)
		{
			sum += *it;
		}
		float avg = sum / scores.size();
		it->m_Score = avg;
	}
}
void showScore(vector<Person>& q) {
	for (vector<Person>::iterator it = q.begin(); it != q.end(); it++) {
		cout << "Name = " << it->m_Name << " 平均分" << it->m_Score << endl;
	}
}
int main() {

	srand((unsigned)time(0));

	vector<Person> p;
	createPerson(p);

	/*cout << "========" << endl;
	for (vector<Person>::iterator it = p.begin(); it != p.end(); it++)
	{
		cout << "Name ： " << it->m_Name << " 分位数：" << it->m_Score << endl;
	}*/
	setScore(p);

	showScore(p);

	system("pause");
	return 0;
}