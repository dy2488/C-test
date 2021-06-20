/********************
File Name: worker.h
Author: dy2488
Mail: 1439433776@qq.com 
Created Time: 2021年06月01日 星期二 00时48分17秒
********************/
#pragma once
#include <iostream>
#include <string>
using namespace std;

class Worker
{
	public:
		virtual void showInfo()=0;
		virtual string getDetName()=0;
		int m_id;
		string m_name;
		int m_DeptId;
};

