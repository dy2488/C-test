/********************
File Name: /home/C++_test/day1_review/src/boss.cpp
Author: dy2488
Mail: 1439433776@qq.com 
Created Time: 2021年06月01日 星期二 23时18分17秒
********************/

#include"../head_file/boss.h"
using namespace std;
Boss::Boss(int id, string name,int dId)
{
	this->m_id=id;
	this->m_name=name;
	this->m_DeptId=dId;

}
void Boss::showInfo()
{
	cout<<"编号=>"<<this->m_id<<endl;
	cout<<"姓名=>"<<this->m_name<<endl;
	cout<<"岗位编号=>"<<this->getDetName()<<endl;

}
string Boss::getDetName()
{
	return "老板";
}




