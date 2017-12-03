/*
 * Linked stack implementation
 * Author: Merlin Mehmed
 */

#pragma once

template <typename T>
class Stack
{
private:
	struct Node
	{
		Node *next;
		T data;
	};

	Node *tos;

	void eraseStack();
	void copyStack(Stack const& other);
	void copy(Node *toCopy);
public:
	Stack();
	~Stack();
	Stack(Stack const& st);
	Stack& operator=(Stack const& other);

	void push(T el);
	T pop();
	T top() const;
	bool isEmpty() const;
};