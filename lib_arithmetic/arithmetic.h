// ���������� ������� � ������� ��� ���������� �������������� ���������
#ifndef __ARITHMETIC_H__
#define __ARITHMETIC_H__
#include <iostream>
#include "stack.h"
#include <string>
#include <vector>
using namespace std;

using namespace std;

struct Lexema
{
	string val; //�������� �������
	int type;  //��� �������
	double x;  //�������� ����� ��� ����������

	Lexema()
	{
		val = "0";
		type = -1;
		x = 0.0;
	}

	Lexema(string v, int t = -1)
	{
		val = v;
		type = t;
		x = 0.0;
	}

	Lexema(char v, int t = -1)
	{
		val = v;
		type = t;
		x = 0.0;
	}

	int operator ==(const Lexema& l) const
	{
		return((val == l.val) && (type == l.type));
	}

	friend ostream& operator<<(ostream os, const Lexema& l)
	{
		os << l.val;
		return os;
	}

	~Lexema() {}
};

class Arithmetic
{
	string input;
	double res;
	int status; //������ ���������
	vector<Lexema> lexInput;//������ ������
	vector<Lexema> lexPolish;// ������ ������ � ������� ��
public:
	 Arithmetic(string s = "");
	 ~Arithmetic();
	 void Divide();//������� �� �������
	 void Converting();//������������� � ��
	 void Variable_value();//��������� �������� ����������
	 void Calculation();//���������� ���������
	 void Launch();//������
	 vector<Lexema> Input_Lex();
	 vector<Lexema> Input_Polish();
	 double Result();
	 void Input();
	 bool check_brackets();
};
#endif