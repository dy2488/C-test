/********************
File Name: t1ype_class.cpp
Author: dy2488
Mail: 1439433776@qq.com 
Created Time: 2021年06月06日 星期日 16时49分28秒
********************/

#include<iostream>
using namespace std;
#include "person.hpp"

void test()
{
	Person<string,int>p("dingyu",111);
	p.showPerson();
}
int main()
{
	test();
	return 0;
}






