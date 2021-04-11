
#pragma once
#include <iostream>
using namespace std;

template<typename T>
class StackTemp
{
	T *arr;
	int count;
	int end = 0, start = 0, size = 0;

public:
	//�������������
	StackTemp(int count)
		: count(count)
	{
		this->count = count;
		arr = new T[count];
	}
	//�����������
	StackTemp(const StackTemp &other)
	{
		arr = new T[other.count];
		count = other.count;
		end = other.end;
		start = other.start;
		size = other.size;
		for (int i = 0; i < count; ++i)
		{
			arr[i] = other.arr[i];
		}
	}

	//�����������
	StackTemp(StackTemp &&other)
	{
		arr = other.arr;
		count = other.count;
		other.arr = nullptr;
	}
	//����������
	~StackTemp()
	{
		delete[] arr;
	}
	//������������
	StackTemp&operator=(const StackTemp &other)
	{
		if (this == &other)
		{
			return *this;
		}
		delete[] arr;
		arr = new T[other.count];
		count = other.count;
		for (int i = 0; i < count; ++i)
		{
			arr[i] = other.arr[i];
		}
	}
	//������������ � ������������
	StackTemp&operator=(StackTemp &&other)
	{
		if (this == &other)
		{
			return *this;
		}
		delete[] arr;
		arr = other.arr;
		count = other.count;
		other.arr = nullptr;
	}

	int GetSize()
	{
		return this->size;
	}
	//������� ��������
	void Push(T element)
	{
		if (size <= count)
		{
			arr[end] = element;
			end = (end + 1);
			size++;
		}
	}
	//�������� ��������
	T Pop()
	{
		if (size > 0)
		{
			T element = arr[start];
			start = (start + 1) % count;
			size--;
			return element;
		}
		return 0;
	}
	//�������� ��������
	T Peek()
	{
		return arr[start];
	}
	//�������� ������� ���������
	bool CheckNoEmptyQueue()
	{
		return (size > 0);
	}
	//�����

 friend ostream& operator<<(ostream& stream, StackTemp& a)
	{
		for (int i = 0; i <= a.count; ++i)
			cout << a.arr[i] << " ";
		return stream;
	}
};