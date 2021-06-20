/********************
File Name: stl_day1.cpp
Author: dy2488
Mail: 1439433776@qq.com 
Created Time: 2021年06月20日 星期日 12时51分05秒
********************/

#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
void myPrint(int val)
{
	cout<<val<<endl;
}

void test01()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	vector<int>::iterator itBegin=v.begin();
	vector<int>::iterator itEnd=v.end(); //最后一个元素的下一个位置
	//遍历
	while (itBegin!=itEnd) {
		cout<<*itBegin<<endl;
		itBegin++;
	}
	//第二种遍历方法
	//for(vector<int>::iterator it=v.begin();it!=v.end();it++)
	//第三种遍历方法
	//for_each(v.begin(), v.end(), myPrint)
	

}
int main()
{
	test01();
}
