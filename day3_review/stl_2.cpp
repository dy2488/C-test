/********************
File Name: stl_2.cpp
Author: dy2488
Mail: 1439433776@qq.com 
Created Time: 2021年06月20日 星期日 13时08分55秒
********************/

#include<iostream>
#include <vector>
using namespace std;

class Person
{
	public:
		Person(string name,int age)
		{
			this->m_Name=name;
			this->m_Age=age;
		}
		int m_Age;
		string m_Name;
};

void test01()
{
	vector<Person> v;
	Person p1("zhangsan",11);
	Person p2("lisi",111);
	Person p3("wangwu",21);
	Person p4("sss",01);
	Person p5("saaaa",18);
	Person p6("llll",41);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	v.push_back(p6);

	for(vector<Person>::iterator it=v.begin();it!=v.end();it++)
	{
		cout<<"姓名"<<(*it).m_Name<<endl;
		cout<<"年龄"<<(*it).m_Age<<endl;

	}
}
int main()
{
	test01();
}
