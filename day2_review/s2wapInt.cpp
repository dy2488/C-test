/********************
File Name: s2wapInt.cpp
Author: dy2488
Mail: 1439433776@qq.com 
Created Time: 2021年06月04日 星期五 23时45分53秒
********************/

#include<bits/stdc++.h>
using namespace std;

template<typename T>
void myswap(T &a,T &b)
{
	T temp=a;
	a=b;
	b=temp;
}


template<typename T>
void mySort(T arr[],int len)
{
	for (int i=0; i<len;i++) {
		int max=i;
		for(int j=i+1;j<len;j++)
		{
			if(arr[max]>arr[j])
			{
				max=j;
			}

		}
		if(max!=i)
		{
			myswap(arr[max],arr[i]);
			
		}



	}
}
template<typename T>
void printArray(T arr[],int len)
{
	for (int i=0; i<len; i++) {
		cout<<arr[i]<<" "<<endl;
	}
	cout<<endl;
}

void test01()
{
	char charArr[]="dsdsbcoes";
	int num=sizeof(charArr)/sizeof(char);
	mySort(charArr, num);
	printArray(charArr,num);
}
int main()
{
	test01();
	return 0;
}














