#pragma once
#include "iostream"

using namespace std;

class Stack
{
	int *arr;
	int count, pos;
	int end = 0, start = 0, size = 0;

public:
	Stack(int count); //�������������
	Stack(const Stack &other); //�����������
	Stack(Stack &&other); //�����������
	~Stack(); //����������
	int GetSize();
	int GetLenght();
	void Push(int element); //������� ��������
	int Pop(); //�������� ��������
	int Peek(); //�������� ���������� ��������
	bool CheckNoEmptyStack(); //�������� ������� ���������
	Stack &operator=(const Stack &other); //������������
	Stack &operator=(Stack &&other); //������������ � ������������
	friend ostream & operator << (ostream & stream, const Stack &a); //�����
};