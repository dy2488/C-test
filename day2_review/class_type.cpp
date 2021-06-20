/********************
File Name: class_type.cpp
Author: dy2488
Mail: 1439433776@qq.com 
Created Time: 2021年06月05日 星期六 15时35分26秒
********************/

#include<iostream>
using namespace std;

template<class NameTpye,class Age_Type>
class Person
{
	public:
		Person(NameTpye name,Age_Type age)
		{
			this->m_name=name;
			this->m_age=age;
		}

		NameTpye m_name;
		Age_Type m_age;
		void showInfo()
		{
			cout<<this->m_name<<" "<<this->m_age<<endl;
		}

};
int main()
{
	Person<string,int>p1("sss",22);
	p1.showInfo();

}


