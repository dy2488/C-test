/********************
File Name: /home/C++_test/day1_review/src/manager.cpp
Author: dy2488
Mail: 1439433776@qq.com 
Created Time: 2021年06月01日 星期二 23时50分40秒
********************/

#include"../head_file/manager.h"
using namespace std;
Manager::Manager(int id,string name, int dId)
{
	this->m_name=name;
	this->m_id=id;
	this->m_DeptId=dId;
}
void Manager::showInfo()
{
	cout<<"编号=>"<<this->m_id<<endl;
	cout<<"姓名=>"<<this->m_name<<endl;
	cout<<"岗位编号=>"<<this->getDetName()<<endl;

}
string Manager::getDetName()
{
return "经理";
}



