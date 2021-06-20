/********************
File Name: /home/C++_test/day1_review/head_file/manager.h
Author: dy2488
Mail: 1439433776@qq.com 
Created Time: 2021年06月01日 星期二 23时37分35秒
********************/
#pragma once
#include"worker.h"
using namespace std;
class Manager:public Worker
{
	public:
		Manager(int id,string name,int dId);
		void showInfo();
		string getDetName();
};


