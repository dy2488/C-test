/********************
File Name: swapInt.cpp
Author: dy2488
Mail: 1439433776@qq.com 
Created Time: 2021年06月04日 星期五 01时58分11秒
********************/

#include<bits/stdc++.h>
using namespace std;
void swapInt(int &x,int&y)
{
	int temp=x;
	x=y;
	y=temp;
}

template <typename T>
void mySwap(T &a,T &b)
{
	T temp=a;
	a=b;
	b=temp;
}

int main()
{
	int x=100;
	int y=200;
	mySwap(x,y);
	cout<<x<<" "<<y<<endl;
	return 0;

}



