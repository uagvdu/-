#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
//һ������ʵ������ջ
//ջ��һ�����ݽṹ�����ڴ��еĶ�ջ������ͬһ��

template<class T>
class ArrayStack //ʵ������ջ
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

	ArrayStack(ArrayStack<T>& arr) //�����������Ȼ��һ������
		: _size(arr._size)
		, _capacity(arr._capacity)
		, _size2(arr._size2)
		, _sz(arr._sz)
	{
		_arr1 = new T[_capacity];
		for (int i = 0 ; i < _capacity; i++)//��ͷ��βһ�α�������㡣
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
		Check_Cap();  //ջa1�����ջa2��������ǰ���ж����߲��������Ƿ��������ǣ����ٿռ�
		_arr1[_size] = d;
		_size++;
	}
	void Arr2_Push_Back(T d)
	{
		Check_Cap();
		//*_arr2 = d;//��ν��2Ӧ����arr1��2��������arr2��2����Ϊarr2Ϊ�����ĩ��λ�ã���ô��2��
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
		//if (_arr1[_size] == _arr2[_size2])//���������ǿռ��ڲ���ֵ�Ƿ���ȣ����ֵ˭֪���᲻������һ���ģ��˴���Ȼ�ռ䲻ͬ�����ڲ������ֵ��һ�µ�
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
		//	_sz = _capacity-1;   //ͬ��ֻҪһ���ݣ�_sz�ͻ�ص�ĩ�˵�λ�ã�ĩ��Ԫ�ؾͻᱻ����
			_arr2 = &_arr1[_capacity - 1];//ֻҪһ���ݾͻ�ĩ��Ԫ���ڲ����µ�Ԫ�ػᱻ����
		}
	}


protected:
	T* _arr1;
	T* _arr2;
	int _size;
	int _size2;
	int _capacity;//��������ջ����
	int _sz ;
};

