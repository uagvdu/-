#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
//一个数组实现两个栈
//栈是一种数据结构，和内存中的堆栈并不是同一个

template<class T>
class ArrayStack //实际上是栈
{
public:
	ArrayStack()
		: _arr1(new T[1])
		, _size(0)
		, _capacity(1)
		, _size2(0)
		, _sz(_capacity - 1)
	{
		assert(_arr1);
		_arr2 = &_arr1[_capacity - 1];
		
	}

	~ArrayStack()
	{
		if (!_arr1)
		{
			delete[] _arr1;
			_size = 0;
			_capacity = 0;
			_size2 = 0;
			_sz = 0;
		}
	}

	ArrayStack(ArrayStack<T>& arr) //拷贝构造的仍然是一个数组
		: _size(arr._size)
		, _capacity(arr._capacity)
		, _size2(arr._size2)
		, _sz(arr._sz)
	{
		_arr1 = new T[_capacity];
		for (int i = 0 ; i < _capacity; i++)//重头到尾一次遍历，最方便。
		{
			_arr1[i] = arr._arr1[i];

		}
		
		
	}

	ArrayStack<T>& operator =(ArrayStack<T> arr)
	{
		swap(_arr1, arr._arr1);
		swap(_arr2, arr._arr2);

		swap(_size, arr._size);
		swap(_size2, arr._size2);

		swap(_capacity, arr._capacity);
		return *this;
	}

public:
	void Arr1_Push_Back(T d)
	{
		Check_Cap();  //栈a1插入和栈a2插入数据前，判断两边插入数据是否相遇，是：开辟空间
		_arr1[_size] = d;
		_size++;
	}
	void Arr2_Push_Back(T d)
	{
		Check_Cap();
		//*_arr2 = d;//所谓的2应该是arr1的2，而不是arr2的2，因为arr2为数组的末端位置，怎么来2？
		//_arr2--;
		//_size2++;
		_arr1[_capacity - _size2-1] = d;
		_size2++;
	}

	void Arr_DisPlay()
	{
		for (int i = 0; i < _capacity; i++)
		{
			cout << _arr1[i] << " ";
		}
		cout << endl;
	}

	void Arr1_DisPlay()
	{
		for (int i = 0; i < _size; i++)
		{
			cout << _arr1[i] << " ";
		}
		cout << endl;
	}

	void Arr2_DisPlay()
	{
		for (int j = _capacity - 1; j >_capacity - _size2 - 1; j--)
		{
			cout << _arr1[j] << " ";
		}
		cout << endl;
	}

	void Arr1_Pop_Back()
	{
		assert(_size > 0);
		_size--;
	}
	void Arr2_Pop_Back()
	{
		assert(_size2 > 0);
		_size2--;
	}



private:
	void Check_Cap()
	{
		//if (_arr1[_size] == _arr2[_size2])//若仅仅考虑空间内部的值是否相等，随机值谁知道会不会碰到一样的，此处虽然空间不同，但内部的随机值是一致的
		if (&_arr1[_size] == &_arr1[_capacity - _size2 - 1])
		{
			int t_capacity = _capacity * 2 + 1;
			int t = t_capacity;
			int s = _size2;
			T* tmp = new T[t_capacity];
			for (int i = 0; i < _size; i++)
			{
				tmp[i] = _arr1[i];
			}
			while (s--)
			{
				tmp[t - 1] = _arr1[_capacity-1];
				t--;
				_capacity--;
			}
			delete[] _arr1;
			_arr1 = tmp;
			_capacity = t_capacity;
		//	_sz = _capacity-1;   //同理，只要一扩容，_sz就会回到末端的位置，末端元素就会被覆盖
			_arr2 = &_arr1[_capacity - 1];//只要一扩容就会末端元素在插入新的元素会被覆盖
		}
	}


protected:
	T* _arr1;
	T* _arr2;
	int _size;
	int _size2;
	int _capacity;//容量是两栈共有
	int _sz ;
};

