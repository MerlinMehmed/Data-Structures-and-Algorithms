/*
* Linked stack implementation
* Author: Merlin Mehmed
*/
#pragma once
#include "Stack.h"

template <typename T>
Stack<T>::Stack()
{
	tos = nullptr;
}

template <typename T>
Stack<T>::~Stack()
{
	eraseStack();
}

template <typename T>
Stack<T>::Stack(Stack const& st)
{
	copyStack(st);
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& other)
{
	if (this != other)
	{
		eraseStack();
		copyStack(other);
	}
	return *this;
}


template <typename T>
void Stack<T>::copyStack(Stack const& other)
{
	tos = nullptr;
	copy(other.tos);
}

template <typename T>
void Stack<T>::copy(Node* toCopy)
{
	if (toCopy == nullptr)
	{
		return;
	}
	copy(toCopy->next);
	push(toCopy->data);
}

// Push element to topof stack
template <typename T>
void Stack<T>::push(T el)
{
	Node *n = new Node;
	n->data = el;
	n->next = tos;
	tos = n;
}

// Pop element from top of stack
template <typename T>
T Stack<T>::pop()
{
	if (!isEmpty())
	{
		Node *x = tos;
		T y = tos->data;
		tos = x->next;
		delete x;
		return y;
	}
	return 0;
}

// Get the top element in stack
template <typename T>
T Stack<T>::top() const
{
	if (!isEmpty())
	{
		return tos->data;
	}
	return 0;
}

template <typename T>
bool Stack<T>::isEmpty() const
{
	return !tos;
}

template <typename T>
void Stack<T>::eraseStack()
{
	while (!isEmpty())
	{
		pop();
	}
}