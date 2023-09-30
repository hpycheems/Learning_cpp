#include "SpeechManager.h"

SpeechManager::SpeechManager()
{
	//��ʼ�� ����
	this->Init();

	//����ѡ��
	this->createSpeaker();

	//���ļ�
	readRecord();
}

void SpeechManager::show_Menu()
{
	cout << "==================================" << endl;
	cout << "======	  ��ӭ�μ��ݽ�����   =====" << endl;
	cout << "========  1.��ʼ�ݽ�����  ========" << endl;
	cout << "========  2.�鿴�����¼  ========" << endl;
	cout << "========  3.��ձ�����¼  ========" << endl;
	cout << "========  0.�˳���������  ========" << endl;
	cout << "==================================" << endl;
}

void SpeechManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

void SpeechManager::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		//����ѡ��
		string name = "ѡ��";
		name += nameSeed[i];

		Speaker s;
		s.m_Name = name;

		for (int j = 0; j < 2; j++)
		{
			s.m_Score[j] = 0;
		}

		//��ʼ�����
		v1.push_back(1001 + i);

		//��ӵ�map
		m_Speaker.insert(make_pair(1001 + i, s));
	}
}

void SpeechManager::startSpeech()
{
	//��һ�� ����

	// ��ǩ
	this->sheechDraw();

	// ��ʼ����
	this->startConpete();

	// ��ʾ����
	showScore();

	
	// �ڶ��ֱ���
	this->m_Index++;
	// ��ǩ
	this->sheechDraw();
	// ��ʼ����
	this->startConpete();
	// ��ʾ����
	showScore();
	//������������浽�ļ���
	saveRecord();

	//��ʼ�� ����
	this->Init();

	//����ѡ��
	this->createSpeaker();

	//���ļ�
	readRecord();

	cout << "����������" << endl;
	system("pause");
	system("cls");
}

void SpeechManager::sheechDraw()
{
	cout << "��<<" << this->m_Index << ">>�ֱ�����ʼ��ǩ" << endl;
	cout << "---------------------" << endl;
	cout << "��ǩ������£�" << endl;
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
	cout << "------------��<<" << this->m_Index << ">>�ֱ�����ʼ--------------" << endl;
	
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

		//���
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

		//cout << "��� " << *it << " ���� " << this->m_Speaker[*it].m_Name << " �÷� " << avg << endl;

		this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;

		groupScore.insert(make_pair(avg, *it));

		if (num % 6 == 0) {
			cout << "��" << num / 6 << "С������ɼ����£�" << endl;
			for (map<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "��ţ�" << it->second << " ���ƣ�" << this->m_Speaker[it->second].m_Name << " �÷� " << it->first << endl;
			}
			cout << endl;
		
			//ȡǰ��
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
	cout << "------------��" << this->m_Index << "�ֱ������-------------" << endl;
	system("pause");
}

void SpeechManager::showScore()
{
	cout << "----------��" << this->m_Index << "�ֱ�������ѡ������------------" << endl;

	vector<int> v;
	if (this->m_Index == 1) {
		v = v2;
	}
	else {
		v = vVictory;
	}

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "��ţ�" << *it << " ���ƣ�" << this->m_Speaker[*it].m_Name
			<< " �÷֣� " << this->m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
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

	cout << "�ļ�����ɹ�" << endl;
	this->fileEmpty = false;
}

void SpeechManager::readRecord()
{
	ifstream ifs("sheech.csv", ios::in);
	if (!ifs.is_open()) {
		fileEmpty = true;
		//cout << "�ļ�������" << endl;
		return;
	}
	
	char c;
	ifs >> c;
	if (ifs.eof()) {
		fileEmpty = true;
		//cout << "�ļ�Ϊ��" << endl;
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
		cout << "�ļ�Ϊ�գ����ļ�������" << endl;
	}
	else {
		for (int i = 0; i < m_Record.size(); i++)
		{
			cout << "��" << i + 1 << "���¼ : "
				<< "�ھ����:" << m_Record[i][0] << " �÷�:" << m_Record[i][1] << " "
				<< "�������:" << m_Record[i][2] << " �÷�:" << m_Record[i][3] << " "
				<< "�Ǿ����:" << m_Record[i][4] << " �÷�:" << m_Record[i][5] << endl;
		}
	}
	system("pause");
	system("cls");
}

void SpeechManager::clearRecord()
{
	cout << "ȷ��Ҫ�����" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.ȡ��" << endl;
	int celect = 0;
	cin >> celect;

	if (celect == 1) {
		ofstream ofs("sheech.csv", ios::trunc);
		ofs.close();
		cout << "��ճɹ�" << endl;
		//��ʼ�� ����
		this->Init();

		//����ѡ��
		this->createSpeaker();

		//���ļ�
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
