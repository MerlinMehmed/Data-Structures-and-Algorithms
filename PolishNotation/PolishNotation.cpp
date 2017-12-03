/*
 * Infix to postfix representation of expression
 * Calculation of postfix representation
 * Author: Merlin Mehmed
 */

#include "Stack.cpp"
#include <iostream>
#include <string.h>
using namespace std;

int priority(char c)
{
	switch (c)
	{
	case '^': return 2;
	case '*':
	case '/': return 1;
	case '+':
	case '-': return 0;
	default: return -1;
	}
}

bool isOperator(char c)
{
	return ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z'));
}

bool isOperation(char c)
{
	return (c == '^' || c == '*' || c == '/' || c == '+' || c == '-');
}

char* translate(char* e)
{
	char* res = new char[strlen(e) + 1];
	int j = 0;
	int size = strlen(e);
	Stack<char> st;
	st.push('(');
	for (int i = 0; i < size; i++)
	{
		if (isOperator(e[i]))
		{
			res[j] = e[i];
			j++;
		}
		else if (e[i] == '(')
		{
			st.push(e[i]);
		}
		else if (e[i] == ')')
		{
			char x = st.top();
			while (x != '(')
			{
				res[j] = x; j++;
				st.pop();
				x = st.top();
			}
		}
		else if (isOperation(e[i]))
		{
			char x = st.top();
			while (x != '(' && priority(x) >= priority(e[i]))
			{
				res[j] = x;
				j++;
				st.pop();
				x = st.top();
			}
			st.push(e[i]);
		}
	}
	char x = st.pop();
	while (x != '(')
	{
		res[j] = x;
		j++;
		x = st.pop();
	}
	res[j] = '\0';
	return res;
}

int performOp(int x, int y, char c)
{
	switch (c)
	{
	case '^': return (int) pow(x, y);
	case '*': return x * y;
	case '/': return x / y;
	case '+': return x + y;
	case '-': return x - y;
	default: return -1;
	}
}

int calculate(char* e)
{
	Stack<int> st;
	int size = strlen(e);
	int res;
	int x, y;
	for (int i = 0; i < size; i++)
	{
		if (isOperator(e[i]))
		{
			st.push(e[i] - '0');
		}
		else if (isOperation(e[i]))
		{
			y = st.pop();
			x = st.pop();
			res = performOp(x, y, e[i]);
			st.push(res);
		}
	}
	return st.pop();
}