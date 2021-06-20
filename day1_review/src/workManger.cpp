/********************
File Name: workManger.cpp
Author: dy2488
Mail: 1439433776@qq.com 
Created Time: 2021年05月31日 星期一 18时43分08秒
********************/
#include"../head_file/workManger.h"
#include"../head_file/employee.h"
#include"../head_file/boss.h"
#include"../head_file/manager.h"

WorkManger::WorkManger()
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);
	if(!ifs.is_open())
	{
		cout<<"文件不存在"<<endl;
		this->m_EmpNum=0;
		this->m_EmpArray=NULL;
		this->mFileIsEmpty=true;
		ifs.close();
		return;
	}
	char ch;
	ifs>>ch;
	if(ifs.eof())
	{
		//文件为空
		cout<<"文件为空"<<endl;
		this->m_EmpNum=0;
		this->m_EmpArray=NULL;
		this->mFileIsEmpty=true;
		ifs.close();
		return;
	}
	int num=this->getEmpNum();
	this->m_EmpNum=num;
	//开辟空间
	this->m_EmpArray=new Worker*[this->m_EmpNum];
	this->initEmp();

	//初始化数据
	//this->m_EmpNum=0;
	//this->m_EmpArray=NULL;
}

int WorkManger::getEmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);
	int id;
	string name;
	int dId;
	int sum=0;
	while (ifs>>id &&ifs>>name && ifs>>dId) {
		sum++;
	}
	ifs.close();
	return sum;
}
void WorkManger::findEmp()
{
	system("clear");
	if(this->mFileIsEmpty)
	{
		cout<<"文件为空或者不存在"<<endl;
	}
	else {
		cout<<"请输入要查找的方式"<<endl;
		cout<<"1---按照编号来查"<<endl;
		cout<<"2---按照姓名来查"<<endl;
		int select=0;
		cin>>select;
		if(select==1)
		{
			int id;
			cout<<"输入查找的职工编号"<<endl;
			cin>>id;
			int ret=idExist(id);
			if(ret!=-1)
			{
				cout<<"查找成功"<<endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else {
			cout<<"查找失败，该编号的职工不存在"<<endl;
			}
		}
		else if(select==2)
		{
			bool flag=false;
			string name;
			cout<<"请输入要查找的姓名"<<endl;
			cin>>name;
			for (int i=0; i<this->m_EmpNum; i++) {
				if(this->m_EmpArray[i]->m_name==name)
				{
					cout<<"查找成功"<<endl;
					cout<<this->m_EmpArray[i]->m_id<<"号的信息如下"<<endl;
					this->m_EmpArray[i]->showInfo();
					flag=true;
				}

			}
			if(flag==false)
			{
				cout<<"查找失败 此人不存在"<<endl;
			}

		}
		else {
		cout<<"输入有误，请重新输入。"<<endl;
		cout<<"1---按照编号来查"<<endl;
		cout<<"2---按照姓名来查"<<endl;
		}

	}

}
void WorkManger::cleanEmp()
{
	system("clear");
	cout<<"此操作有风险，请确认是否清空数据Y/N"<<endl;
	char z;
	cin>>z;
	if(z=='y'||z=='Y')
	{
		ofstream ofs(FILENAME,ios::trunc);
		ofs.close();
		if(this->m_EmpArray!=NULL)
		{
			for (int i=0;i<this->m_EmpNum; i++) {
				if(this->m_EmpArray[i]!=NULL)
				{
					delete this->m_EmpArray[i];
				}

			}
			this->m_EmpNum=0;
			delete [] this->m_EmpArray;
			this->m_EmpArray=NULL;
			this->mFileIsEmpty=true;
		}
		cout<<"清楚成功"<<endl;
	}

}

void WorkManger::sortEmp()
{
	if(this->mFileIsEmpty)
	{
		cout<<"文件为空或者不存在"<<endl;
	}
	else {
	cout<<"请选择排序的方式"<<endl;
	cout<<"1---按工号进行升序"<<endl;
	cout<<"2---按工号进行降序"<<endl;
	int select;
	cin>>select;
	for (int i=0; i<this->m_EmpNum; i++) {
		//声明最小值或者最大值下标
		int minOrMax=i;
		for (int j=i+1; j<this->m_EmpNum; j++) {
			if(select==1)
			{
				if(this->m_EmpArray[minOrMax]->m_id>this->m_EmpArray[j]->m_id)
				{
					minOrMax=j;
				}

			}
			else {
				if(this->m_EmpArray[minOrMax]->m_id>this->m_EmpArray[j]->m_id)
				{
					minOrMax=j;
				}

			}

		}
		if(i!=minOrMax)
		{
			Worker * temp=this->m_EmpArray[i];
			this->m_EmpArray[i]=this->m_EmpArray[minOrMax];
			this->m_EmpArray[minOrMax]=temp;
		}


	}
	cout<<"排序成功，请选择是否写入到文件里面Y/N"<<endl;
	char z;
	cin>>z;
	if(z=='y'||z=='Y')
	{
		this->save();
		cout<<"排序成功，并且已经写入文件"<<endl;
	}
	else {
	cout<<"成功取消添加"<<endl;
	}

	}



}


void WorkManger::modEmp()
{
	system("clear");
	if(this->mFileIsEmpty)
	{
		cout<<"文件不存在或文件为空";
	}
	else {
	cout<<"请输入要修改的员工编号"<<endl;
	int id;
	cin >> id;
	int ret=this->idExist(id);
	if(ret!=-1)
	{
		delete this->m_EmpArray[ret];
		int newId=0;
		string newString="";
		int dSelect=0;
		cout<<"查到："<<id<<"号职工，请输入新职工工号"<<endl;
		cin>>newId;
		cout<<"请输入新姓名"<<endl;
		cin>>newString;
		cout<<"请输入岗位"<<endl;
		cout<<"1---员工"<<endl;
		cout<<"2---经理"<<endl;
		cout<<"3---老板"<<endl;
		cin>>dSelect;
		Worker *worker=NULL;
		switch (dSelect) {
			case 1:
				worker=new Employee(newId,newString,dSelect);
				break;
			case 2:
				worker=new Manager(newId,newString,dSelect);
				break;
			case 3:
				worker=new Boss(newId,newString,dSelect);
				break;
			default:
				break;
		}
		this->m_EmpArray[ret]=worker;
		cout<<"修改成功"<<this->m_EmpArray[ret]->m_DeptId<<endl;
		this->save();
	}
	else{
		cout<<"修改失败，查无此人"<<endl;
	}


	}

}

int WorkManger::idExist(int id)
{
	int index=-1;
	for(int i=0;i<this->m_EmpNum;i++)
	{
		if(this->m_EmpArray[i]->m_id==id)
		{
			index=i;
			break;
		}

	}
	return index;

}


void WorkManger::initEmp()
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);
	int id;
	string name;
	int dId;
	int idex=0;
	while (ifs>>id && ifs>>name && ifs>>dId) {
		Worker * worker=NULL;
		if(dId==1)
		{
			worker=new Employee(id,name,dId);
		}
		if(dId==2)
		{
			worker=new Manager(id,name,dId);
		}
		if(dId==3)
		{
			worker=new Boss(id,name,dId);
		}
		this->m_EmpArray[idex]=worker;
		idex++;

	}
	ifs.close();

}


void WorkManger::ShowMenu()
{

	cout<<" "<<endl;
	cout<<"hello use system !"<<endl;

}
void WorkManger::save()
{
	ofstream ofs;
	ofs.open(FILENAME,ios::out);
	for (int i=0; i<this->m_EmpNum;i++) {
		ofs<<this->m_EmpArray[i]->m_id<<" "
			<<this->m_EmpArray[i]->m_name<<" "
			<<this->m_EmpArray[i]->m_DeptId<<endl;
	}
	ofs.close();
}

void WorkManger::ExitSystem()
{
	cout<<"欢迎下次使用！"<<endl;
	exit(0);
}
void WorkManger::AddEmp()
{
	cout<<"请输入添加员工数量"<<endl;
	int addNum=0;
	cin >>addNum;
	if(addNum>0)
	{
		int NewSize=this->m_EmpNum+addNum;
		Worker **newSpace=new Worker*[NewSize];
		if(this->m_EmpArray!=NULL)
		{
			for (int i=0; i<this->m_EmpNum;i++) {
				newSpace[i]=this->m_EmpArray[i];
			}
		}
		for (int i=0; i<addNum; i++) {
			int id;
			string name;
			int dSelect;
			cout<<"请输入第"<<i+1<< "个员工的编号："<<endl;
			cin>>id;
			cout<<"请输入第"<<i+1<< "个员工的姓名："<<endl;
			cin>>name;
			cout<<"请选择职工岗位"<<endl;
			cout<<"1普通职工"<<endl;
			cout<<"2经理"<<endl;
			cout<<"3老板"<<endl;
			cin>>dSelect;
			Worker *worker=NULL;
				switch (dSelect) {
					case 1:
						worker=new Employee(id,name,1);
						break;
					case 2:
						worker=new Manager(id,name,2);
						break;
					case 3:
						worker=new Boss(id,name,3);
						break;
					default:
						break;
				}
					newSpace[this->m_EmpNum+i]=worker;
				}
		delete [] this->m_EmpArray;
		this->m_EmpArray=newSpace;
		this->m_EmpNum=NewSize;
		system("clear");
		cout<<"成功添加了"<<addNum<<"名新职工"<<endl;
		this->mFileIsEmpty=false;
		this->save();
		}


	else {
	cout<<"输入数据有误，请冲行输入！"<<endl;
		system("clear");
	}

}
void WorkManger::delEmp()
{
	if(this->mFileIsEmpty)
	{
		cout<<"文件为空"<<endl;
	}
	else {
	cout<<"请输入要删除职工的编号"<<endl;
	int id;
	cin>>id;
	int index=this->idExist(id);
	if(index!=-1)
	{
		for(int i=index;i<this->m_EmpNum;i++)
		{
			this->m_EmpArray[i]=this->m_EmpArray[i+1];
		}
		this->m_EmpNum--;
		this->save();
		cout<<"删除成功"<<endl;

	}
	else {
	cout<<"删除失败 未找到该职工"<<endl;
	}

	}


}

void WorkManger::showEmp()
{
		system("clear");
	if(this->mFileIsEmpty)
	{
		cout<<"文件为空"<<endl;
	}
	for (int i=0; i<m_EmpNum; i++) {
		this->m_EmpArray[i]->showInfo();
	}



}



WorkManger::~WorkManger()
{

	if(this->m_EmpArray!=NULL)
	{
		for (int i=0; i<this->m_EmpNum; i++) {
			if(this->m_EmpArray[i]!=NULL)
			{
				delete [] this->m_EmpArray[i];
			}

		}
		delete [] this->m_EmpArray;
		this->m_EmpArray=NULL;
	}


}




