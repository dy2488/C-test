/********************
File Name: Main.cpp
Author: dy2488
Mail: 1439433776@qq.com 
Created Time: 2021年05月31日 星期一 18时58分38秒
********************/

#include"../head_file/workManger.h"
using namespace std;

int main()
{
	WorkManger wm;
	int choice;
	while (true) {
		wm.ShowMenu();
		cout<<"请输入要选择的服务"<<endl;
		cout<<"0--->退出"<<endl;
		cout<<"1--->添加员工"<<endl;
		cout<<"2--->查看员工"<<endl;
		cout<<"3--->删除员工"<<endl;
		cout<<"4--->修改员工"<<endl;
		cout<<"5--->查找员工"<<endl;
		cout<<"6--->排序员工"<<endl;
		cout<<"7--->删除列表"<<endl;
		cin>>choice;
		switch (choice) {
			case 0:
				wm.ExitSystem();
				break;
			case 1:
				wm.AddEmp();
				break;
			case 2:
				wm.showEmp();
				break;
			case 3:
				wm.delEmp();
				break;
			case 4:
				wm.modEmp();
				break;
			case 5:
				wm.findEmp();
				break;
			case 6:
				wm.sortEmp();
				break;
			case 7:
				wm.cleanEmp();
				break;
			default:
				system("clear");
		}
	}


	return 0;
}

