/********************
File Name: s3wapInt.cpp
Author: dy2488
Mail: 1439433776@qq.com 
Created Time: 2021年06月05日 星期六 00时50分12秒
********************/

#include<iostream>
using namespace std;


template<typename T>
T add2(T x,T y)
{
	return x+y;
}

int  add(int x,int y)
{
	return x+y;
}

void test01()
{
	int x=3;
	int y=5;
	bool tr=true;
	char c='a';
	int z=add(x,y);
	int z1=add2(x,y);
	//强制类型转换后可以用
	int z2=add2<int>(x,c);
	cout<<z<<endl;
	cout<<z1<<endl;
}
int main()
{
	test01();
	return 0;
}



