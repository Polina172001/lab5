#pragma once
#include "iostream"

using namespace std;

class Stack
{
	int *arr;
	int count, pos;
	int end = 0, start = 0, size = 0;

public:
	Stack(int count); //инициализация
	Stack(const Stack &other); //копирование
	Stack(Stack &&other); //перемещение
	~Stack(); //деструктор
	int GetSize();
	int GetLenght();
	void Push(int element); //Вставка элемента
	int Pop(); //Удаление элемента
	int Peek(); //Просмотр доступного элемента
	bool CheckNoEmptyStack(); //Проверка наличия элементов
	Stack &operator=(const Stack &other); //присваивание
	Stack &operator=(Stack &&other); //присваивание с перемещением
	friend ostream & operator << (ostream & stream, const Stack &a); //Вывод
};