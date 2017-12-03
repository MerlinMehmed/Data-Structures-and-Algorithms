/*
 * Linked queue implementation
 * Author: Merlin Mehmed
 */

#pragma once
#include "stdafx.h"

template <typename T>
struct Node {
	Node *next;
	T data;
};

template <typename T>
class Queue
{
private:
	Node<T> *front, *back;
	void eraseQueue();
	void copyQueue(Queue<T> const& other);
public:
	Queue();
	~Queue();
	Queue(Queue const& other);
	Queue& operator=(Queue<T> const& other);

	void enqueue(T const& x);
	T dequeue();
	T getFront() const;
	bool isEmpty() const;
};