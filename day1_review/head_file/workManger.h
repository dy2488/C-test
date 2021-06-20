/********************
File Name: workManger.h
Author: dy2488
Mail: 1439433776@qq.com 
Created Time: 2021年05月31日 星期一 18时40分03秒
********************/
#pragma once
#include"worker.h"
#include <fstream>
#define FILENAME "empFile.txt"
using namespace std;
class WorkManger
{
	public:
		WorkManger();
		void ShowMenu();
		void ExitSystem();
		void AddEmp();
		void save();
		void initEmp();
		void showEmp();
		void delEmp();
		void modEmp();
		void sortEmp();
		void findEmp();
		void cleanEmp();
		int idExist(int id);
		int getEmpNum();
		~WorkManger();
		bool mFileIsEmpty=false;
		int m_EmpNum;
		Worker **m_EmpArray;


};

