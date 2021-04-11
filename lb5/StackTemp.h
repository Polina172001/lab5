
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
	//инициализация
	StackTemp(int count)
		: count(count)
	{
		this->count = count;
		arr = new T[count];
	}
	//копирование
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

	//перемещение
	StackTemp(StackTemp &&other)
	{
		arr = other.arr;
		count = other.count;
		other.arr = nullptr;
	}
	//деструктор
	~StackTemp()
	{
		delete[] arr;
	}
	//присваивание
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
	//присваивание с перемещением
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
	//Вставка элемента
	void Push(T element)
	{
		if (size <= count)
		{
			arr[end] = element;
			end = (end + 1);
			size++;
		}
	}
	//Удаление элемента
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
	//Просмотр элемента
	T Peek()
	{
		return arr[start];
	}
	//Проверка наличия элементов
	bool CheckNoEmptyQueue()
	{
		return (size > 0);
	}
	//Вывод

 friend ostream& operator<<(ostream& stream, StackTemp& a)
	{
		for (int i = 0; i <= a.count; ++i)
			cout << a.arr[i] << " ";
		return stream;
	}
};