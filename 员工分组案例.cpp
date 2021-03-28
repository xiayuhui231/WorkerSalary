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
		worker.m_Name = "员工";
		worker.m_Name += str[i];
		worker.m_Salary = rand() % 10000 + 10000; //  10000-19999
		v.push_back(worker);
	}
}

void setGroup(vector<Worker> &v, multimap<int, Worker> &m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		//随机编号
		int ItDept = rand() % 3;// 0  1  2
		m.insert(make_pair(ItDept, *it));
	}
}
void ShowWorker(multimap<int, Worker> &m)
{
	cout << "策划部门：" << endl;
	multimap<int, Worker>::iterator pos = m.find(CEHUA);
	int count = m.count(CEHUA);
	for (int i = 0; i < count; pos++, i++)
	{
		cout << "姓名： " << pos->second.m_Name << " 工资： " << pos->second.m_Salary << endl;
	}
	cout << "------------------------------" << endl;
	cout << "美术部门：" << endl;
	 pos = m.find(MEISHU);
	 count = m.count(MEISHU);
	for (int i = 0; i < count; pos++, i++)
	{
		cout << "姓名： " << pos->second.m_Name << " 工资： " << pos->second.m_Salary << endl;
	}
	cout << "------------------------------" << endl;
	cout << "研发部门：" << endl;
	 pos = m.find(YANFA);
	 count = m.count(YANFA);
	for (int i = 0; i < count; pos++, i++)
	{
		cout << "姓名： " << pos->second.m_Name << " 工资： " << pos->second.m_Salary << endl;
	}
}

//void test01()
//{
//	vector<Worker>vWorker;
//	setName(vWorker);
//	//分组
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
	//分组
	multimap<int, Worker>mWorker;
	setGroup(vWorker, mWorker);
	ShowWorker(mWorker);
	system("pause");
}