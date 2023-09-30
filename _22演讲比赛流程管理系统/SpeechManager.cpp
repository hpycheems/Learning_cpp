#include "SpeechManager.h"

SpeechManager::SpeechManager()
{
	//初始化 属性
	this->Init();

	//创建选手
	this->createSpeaker();

	//读文件
	readRecord();
}

void SpeechManager::show_Menu()
{
	cout << "==================================" << endl;
	cout << "======	  欢迎参加演讲比赛   =====" << endl;
	cout << "========  1.开始演讲比赛  ========" << endl;
	cout << "========  2.查看往届记录  ========" << endl;
	cout << "========  3.清空比赛记录  ========" << endl;
	cout << "========  0.退出比赛程序  ========" << endl;
	cout << "==================================" << endl;
}

void SpeechManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

void SpeechManager::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		//创建选手
		string name = "选手";
		name += nameSeed[i];

		Speaker s;
		s.m_Name = name;

		for (int j = 0; j < 2; j++)
		{
			s.m_Score[j] = 0;
		}

		//初始化编号
		v1.push_back(1001 + i);

		//添加到map
		m_Speaker.insert(make_pair(1001 + i, s));
	}
}

void SpeechManager::startSpeech()
{
	//第一轮 比赛

	// 抽签
	this->sheechDraw();

	// 开始比赛
	this->startConpete();

	// 显示晋级
	showScore();

	
	// 第二轮比赛
	this->m_Index++;
	// 抽签
	this->sheechDraw();
	// 开始比赛
	this->startConpete();
	// 显示晋级
	showScore();
	//将比赛结果保存到文件中
	saveRecord();

	//初始化 属性
	this->Init();

	//创建选手
	this->createSpeaker();

	//读文件
	readRecord();

	cout << "本届比赛完毕" << endl;
	system("pause");
	system("cls");
}

void SpeechManager::sheechDraw()
{
	cout << "第<<" << this->m_Index << ">>轮比赛开始抽签" << endl;
	cout << "---------------------" << endl;
	cout << "抽签结果如下：" << endl;
	if (this->m_Index == 1) {
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	else {
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "---------------" << endl;
	system("pause");
	cout << endl;
}

void SpeechManager::startConpete()
{
	cout << "------------第<<" << this->m_Index << ">>轮比赛开始--------------" << endl;
	
	multimap<double, int, greater<double>> groupScore;
	int num = 0;

	vector<int> v_Src;
	if (this->m_Index == 1) {
		v_Src = v1;
	}
	else {
		v_Src = v2;
	}

	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;
		deque<double> d;

		//打分
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;
			//cout << score << " ";
			d.push_back(score);
		}
		//cout << endl;

		sort(d.begin(), d.end(), greater<double>());
		d.pop_front();
		d.pop_back();

		double sum = accumulate(d.begin(), d.end(),0);
		double avg = sum / (double)d.size();

		//cout << "编号 " << *it << " 姓名 " << this->m_Speaker[*it].m_Name << " 得分 " << avg << endl;

		this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;

		groupScore.insert(make_pair(avg, *it));

		if (num % 6 == 0) {
			cout << "第" << num / 6 << "小组比赛成绩如下：" << endl;
			for (map<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "编号：" << it->second << " 名称：" << this->m_Speaker[it->second].m_Name << " 得分 " << it->first << endl;
			}
			cout << endl;
		
			//取前三
			int count = 0;
			for (map<double, int, greater<int>>::iterator it = groupScore.begin() ; it != groupScore.end() && count < 3; it++, count++)
			{
				if (this->m_Index == 1) {
					v2.push_back(it->second);
				}
				else {
					vVictory.push_back(it->second);
				}
			}

			groupScore.clear();
		}
		
	}
	cout << "------------第" << this->m_Index << "轮比赛完毕-------------" << endl;
	system("pause");
}

void SpeechManager::showScore()
{
	cout << "----------第" << this->m_Index << "轮比赛晋级选手如下------------" << endl;

	vector<int> v;
	if (this->m_Index == 1) {
		v = v2;
	}
	else {
		v = vVictory;
	}

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "编号：" << *it << " 名称：" << this->m_Speaker[*it].m_Name
			<< " 得分： " << this->m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
	}

	cout << endl;

	system("pause");
	system("cls");
	this->show_Menu();
}

void SpeechManager::saveRecord()
{
	ofstream ofs;
	ofs.open("sheech.csv", ios::out | ios::app);

	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << "," 
			<< this->m_Speaker[*it].m_Score[1]<<",";
	} 
	ofs << endl;

	ofs.close();

	cout << "文件保存成功" << endl;
	this->fileEmpty = false;
}

void SpeechManager::readRecord()
{
	ifstream ifs("sheech.csv", ios::in);
	if (!ifs.is_open()) {
		fileEmpty = true;
		//cout << "文件不存在" << endl;
		return;
	}
	
	char c;
	ifs >> c;
	if (ifs.eof()) {
		fileEmpty = true;
		//cout << "文件为空" << endl;
		return;
	}
	
	ifs.putback(c);

	this->fileEmpty = false;	
	string data;
	int index = 0;
	while (ifs >> data) {
		vector<string >v;
		int pos = -1;
		int start = 0;

		while (true) {
			pos = data.find(",", start);
			if (pos == -1) {
				break;
			}
			string temp = data.substr(start, pos - start);
			//cout << temp << endl;
			v.push_back(temp);
			start = pos + 1;
		}
		this->m_Record.insert(make_pair(index, v));
		index++;
	}

	ifs.close();

}

void SpeechManager::showRecord()
{
	if (fileEmpty) {
		cout << "文件为空，或文件不存在" << endl;
	}
	else {
		for (int i = 0; i < m_Record.size(); i++)
		{
			cout << "第" << i + 1 << "届记录 : "
				<< "冠军编号:" << m_Record[i][0] << " 得分:" << m_Record[i][1] << " "
				<< "季军编号:" << m_Record[i][2] << " 得分:" << m_Record[i][3] << " "
				<< "亚军编号:" << m_Record[i][4] << " 得分:" << m_Record[i][5] << endl;
		}
	}
	system("pause");
	system("cls");
}

void SpeechManager::clearRecord()
{
	cout << "确定要清空吗？" << endl;
	cout << "1.确定" << endl;
	cout << "2.取消" << endl;
	int celect = 0;
	cin >> celect;

	if (celect == 1) {
		ofstream ofs("sheech.csv", ios::trunc);
		ofs.close();
		cout << "清空成功" << endl;
		//初始化 属性
		this->Init();

		//创建选手
		this->createSpeaker();

		//读文件
		readRecord();
	}
	system("pause");
	system("cls");
	
}

SpeechManager::~SpeechManager()
{
}

void SpeechManager::Init()
{
	v1.clear();
	v2.clear();
	vVictory.clear();
	m_Speaker.clear();
	m_Record.clear();

	m_Index = 1;
}
