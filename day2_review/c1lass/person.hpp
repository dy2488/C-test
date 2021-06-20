/********************
File Name: /home/C++_test/day2_review/c1lass/person.hpp
Author: dy2488
Mail: 1439433776@qq.com 
Created Time: 2021年06月06日 星期日 17时05分24秒
********************/
#pragma once
#include<iostream>
using namespace std;

template<class T1, class T2>
class Person
{
	public:
		Person(T1 name, T2 age);
		void showPerson();
		T1 mName;
		T2 mAge;

};
template<class T1,class T2>
Person<T1,T2>::Person(T1 name, T2 age) 
{
	this->mName=name;
	this->mAge=age;
}
template<class T1,class T2>
void Person<T1,T2>::showPerson()
{
	cout<<this->mName<<" "<<this->mAge<<endl;
}

