#include "Stack.h"

Stack::Stack(int count)
	: count(count)
{
	this->count = count;
	arr = new int[count];
}


Stack::Stack(const Stack &other)
{
	arr = new int[other.count];
	count = other.count;
	end = other.end;
	start = other.start;
	size = other.size;
	for (int i = 0; i < count; ++i)
	{
		arr[i] = other.arr[i];
	}
}



Stack::Stack(Stack &&other)
{
	arr = other.arr;
	count = other.count;
	other.arr = nullptr;
}

Stack::~Stack()
{
	delete[] arr;
}

Stack &Stack::operator=(const Stack &other)

{
	if (this == &other)
	{
		return *this;
	}
	delete[] arr;
	arr = new int[other.count];
	count = other.count;
	for (int i = 0; i < count; ++i)
	{
		arr[i] = other.arr[i];
	}
}

Stack &Stack::operator=(Stack &&other)
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

int Stack::GetSize()
{
	return this->size;
}

int Stack::GetLenght()
{
	return this->size;
}

void Stack::Push(int element)
{
	if (size <= count)
	{
		arr[end] = element;
		end = (end + 1);
		size++;
	}
}

int Stack::Pop()
{
	if (size > 0)
	{
		int element = arr[start];
		start = (start + 1) % count;
		size--;
		return element;
	}
	return 0;
}

int Stack::Peek()
{
	return arr[start];
}

bool Stack::CheckNoEmptyStack()
{
	return (size > 0);
}


ostream & operator << (ostream & stream, const Stack &a)
{
	for (int i = 0; i <= a.count; ++i)
		cout << a.arr[i] << " ";
	return stream;
}