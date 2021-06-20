/********************
File Name: /home/C++_test/day1_review/src/employee.cpp
Author: dy2488
Mail: 1439433776@qq.com 
Created Time: 2021年06月01日 星期二 01时04分40秒
********************/

#include"../head_file/employee.h"
using namespace std;
Employee :: Employee(int id,string name,int dId)
{
	this->m_name=name;
	this->m_id=id;
	this->m_DeptId=dId;

}
void Employee::showInfo()
{
	cout<<"编号=>"<<this->m_id<<endl;
	cout<<"姓名=>"<<this->m_name<<endl;
	cout<<"岗位编号=>"<<this->getDetName()<<endl;

}
string Employee::getDetName()
{
	return "员工";

}


