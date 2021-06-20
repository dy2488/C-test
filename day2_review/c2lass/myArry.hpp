/********************
File Name: myArry.h
Author: dy2488
Mail: 1439433776@qq.com 
Created Time: 2021年06月06日 星期日 19时59分32秒
********************/

#include<iostream>
using namespace std;

template<class T>
class MyArry
{
	public:
		MyArry(int capacity)
		{
			this->mCapacity=capacity;
			this->mSize=0;
			this->pAddress=new T[this->mCapacity];
		}
		//拷贝构造
		MyArry(const MyArry& arr)
		{
			this->mCapacity=arr.mCapacity;
			this->mSize=arr.mSize;
			this->pAddress=new T[arr.mCapacity];
			for (int i=0;i<arr.mCapacity;i++) {
				this->pAddress[i]=arr.pAddress[i];
			}
		}
		//operator=
		MyArry& operator=(const MyArry& arr)
		{
			//先判断原来堆区有没有数据
			if(this->pAddress!=NULL)
			{
				delete [] this->pAddress;
				this->pAddress=NULL;
				this->mCapacity=0;
				this->mSize=0;
			}
			//深拷贝
			this->mCapacity=arr.mCapacity;
			this->mSize=arr.mSize;
			this->pAddress=new T[arr.mCapacity];
			for(int i=0;i<this->mSize;i++)
			{
				this->pAddress[i]=arr.pAddress[i];
			}
			return *this;
		}


		//析构函数
		~MyArry()
		{
			if(this->pAddress!=NULL)
			{
				delete [] this->pAddress;
				this->pAddress=NULL;
			}

		}



	private:
		T* pAddress;//指针指向堆区开辟的真实数据
		int mCapacity;//数组容量
		int mSize;//数组大小
}

