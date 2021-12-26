#pragma once

#ifndef __LIST_H__
#define __LIST_H__

#include <iostream>
using namespace std;

typedef int DataType;

struct Node
{
	DataType data;
	Node* next;
	// ����� ����� ���� ������������, ������, ���������� Node

	Node(DataType d = 0, Node* n = NULL);
	Node(const Node& node2);
	bool operator==(const Node& node2) const;
};

class myiterator
{
	Node* p;
public:
	myiterator(Node* tmp) : p(tmp) {};

	DataType& operator*() { return p->data; };

	myiterator& operator++()
	{
		p = p->next;
		return *this;
	};

	friend class List;
};

class List
{
	// ����� ����
	Node* head;
public:
	//  List(const List& list2);
	//  List& operator=(const List& list2);
	List();
	~List();

	void InsertToHead(const DataType& d);             // �������� ������� d ������
	void InsertToTail(const DataType& d);             // �������� ������� d ���������
	void DeleteToTail();

	void Clean();                                     // ������� ��� ������  
	void Delete(const DataType& d);                   // ������� ����� �� ��������� data = d				

	bool isEmpty() { return (head == nullptr); }

	DataType ViewHead() { return head->data; }

	myiterator begin() { return myiterator(head); };

	//void InsertAfter(Node* node, const DataType& d);   // �������� ������� d ����� ����� node
	//Node* Search(const DataType& d);                   // ����� ��������� �� ����� �� ��������� data = d
	//int GetSize();                                     // ������ ����� ������� � ������
	//Node* GetHead();                                   // �������� ��������� �� ������ ����� ������

	//void Inverse();                                    // ������������� ������, �.�. ������ ������ ���� � �������� �������
	//List Merge(Node* node, const List& list2);         // ������� ������3, ������� ������2 � ������� ������ ����� ��������� node  
	//List Merge(const List& list2);                     // ������� ������3, ������� � ����� �������� ������ ������2

	//bool operator==(const List& list2) const;          // ������ �����, ���� �������� � ��� ���� � ���������� �������
	//friend ostream& operator<<(ostream& os, const List& l);

	List(DataType* arr, int size);
	void DeleteHead();
	void print(char* direction);

};

#endif  // __LIST_H__