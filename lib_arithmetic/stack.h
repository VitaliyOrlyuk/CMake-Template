// ���������� � ���������� ���������� �����
// ���� ������������ ��������: 
// - ������� ��������, +
// - ���������� ��������, +
// - �������� �������� �������� (��� ��������)+
// - �������� �� �������, +
// - ��������� ���������� ��������� � �����+
// - ������� �����+
// ��� ������� � ������ ���� ������ �������������� ������

#ifndef STACK_H
#define STACK_H

#include <iostream>

template<class T>
class Stack
{
private:
	T* stack; //��������� �� ����
	int size; //���������� ��������� � �����
	int index; // ����� �������� �������� � �����
public:
	Stack(int s = 10); 
	Stack(const Stack<T>& s);
	~Stack();

	void Push(const T val);     // ������� �������� � ������� �����
	T& Pop();                   // ���������� �������� �� �����
	T& See(); // �������� �������� ��������(��� ��������)
	bool isEmpty(); // �������� �� �������
	int Number(); //���������� ��������� � �����
	void Clean(); //������� �����
};

template<class T> 
Stack<T>::Stack(int s)
{
	if (s >= 0)
	{
		size = s;
		index = -1;
		stack = new T[size];
	}
	else
		throw std::exception("Error: array size cannot be negative");
}

template<class T>
Stack<T>::Stack(const Stack<T>& s)
{
	size = s.size;
	index = s.index;
	stack = new T[s.size];
	for (int i = 0; i < size; i++)
	{
		stack[i] = s.stack[i];
	}
}

template<class T>
Stack<T>::~Stack()
{
	delete[] stack;
}

template<class T>
void Stack<T>::Push(const T val)
{
	if (index + 1 < size)
	{
		index++;
		stack[index] = val;
	}
	else
	{
		Stack<T> Copy(*this);
		delete[] stack;
		size = size * 2;
		stack = new T[size];
		for (int i = 0; i, size; i++)
			stack[i] = Copy.stack[i];
		index++;
		stack[index] = val;
	}
}

template<class T>
T& Stack<T>::Pop()
{
	if (isEmpty())
		throw std::exception("Error: stack is empty");
	return stack[index--];
}

template<class T>
T& Stack<T>::See()
{
	if (isEmpty())
		throw std::exception("Error: stack is empty");
	return stack[index];
}

template<class T>
bool Stack<T>::isEmpty()
{
	if (index == -1)
		return true;
	else
		return false;
}

template<class T>
int Stack<T>::Number()
{
	return index + 1;
}

template<class T>
void Stack<T>::Clean()
{
	size = 0;
}
#endif