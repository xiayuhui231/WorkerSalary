#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include<string>
#include<ctime>

#define CEHUA 0
#define MEISHU 1
#define YANFA 2

class Worker
{
public:
	string m_Name;
	int m_Salary;
};

void setName(vector<Worker> &v)
{

	string str = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		Worker worker;
		worker.m_Name = "Ա��";
		worker.m_Name += str[i];
		worker.m_Salary = rand() % 10000 + 10000; //  10000-19999
		v.push_back(worker);
	}
}

void setGroup(vector<Worker> &v, multimap<int, Worker> &m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		//������
		int ItDept = rand() % 3;// 0  1  2
		m.insert(make_pair(ItDept, *it));
	}
}
void ShowWorker(multimap<int, Worker> &m)
{
	cout << "�߻����ţ�" << endl;
	multimap<int, Worker>::iterator pos = m.find(CEHUA);
	int count = m.count(CEHUA);
	for (int i = 0; i < count; pos++, i++)
	{
		cout << "������ " << pos->second.m_Name << " ���ʣ� " << pos->second.m_Salary << endl;
	}
	cout << "------------------------------" << endl;
	cout << "�������ţ�" << endl;
	 pos = m.find(MEISHU);
	 count = m.count(MEISHU);
	for (int i = 0; i < count; pos++, i++)
	{
		cout << "������ " << pos->second.m_Name << " ���ʣ� " << pos->second.m_Salary << endl;
	}
	cout << "------------------------------" << endl;
	cout << "�з����ţ�" << endl;
	 pos = m.find(YANFA);
	 count = m.count(YANFA);
	for (int i = 0; i < count; pos++, i++)
	{
		cout << "������ " << pos->second.m_Name << " ���ʣ� " << pos->second.m_Salary << endl;
	}
}

//void test01()
//{
//	vector<Worker>vWorker;
//	setName(vWorker);
//	//����
//	//multimap<int, Worker>mWorker;
//	//setGroup(vWorker, mWorker);
//
//	//ShowWorker(mWorker);
//
//}

int main() {
	srand((unsigned int)time(NULL));
	vector<Worker>vWorker;
	setName(vWorker);
	//����
	multimap<int, Worker>mWorker;
	setGroup(vWorker, mWorker);
	ShowWorker(mWorker);
	system("pause");
}