/********************
File Name: employee.h
Author: dy2488
Mail: 1439433776@qq.com 
Created Time: 2021年06月01日 星期二 00时52分22秒
********************/
#pragma once
#include"worker.h"
using namespace std;

class Employee : public Worker
{
	public:
		Employee(int id,string name,int dId);
		void showInfo();
		string getDetName();

};

