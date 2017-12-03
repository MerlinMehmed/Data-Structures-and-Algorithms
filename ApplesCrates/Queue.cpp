/*
* Linked queue implementation
* Author: Merlin Mehmed
*/

#include "stdafx.h"
#include "Queue.h"

template <typename T>
Queue<T>::Queue() : front(NULL), back(NULL) {}

template <typename T>
Queue<T>::~Queue()
{
	eraseQueue();
}

template <typename T>
Queue<T>::Queue(Queue<T> const& other) : front(NULL), back(NULL)
{
	copyQueue(other);
}

template <typename T>
Queue<T>& Queue<T>::operator=(Queue<T> const& other)
{
	if (this != &other)
	{
		eraseQueue();
		copyQueue(other);
	}
	return *this;
}

// Push element to the end of queue
template <typename T>
void Queue<T>::enqueue(T const& x)
{
	Node<T> *n = new Node<T>;
	n->data = x;
	n->next = NULL;
	if (isEmpty())
	{
		front = n;
	}
	else
	{
		back->next = n;
	}
	back = n;
}

// Pop the first element in queue
template <typename T>
T Queue<T>::dequeue()
{
	if (!isEmpty())
	{
		Node<T> *x = front;
		T y = front->data;
		front = x->next;
		delete x;
		return y;
	}
}

// Get the value of the first element in queue
template <typename T>
T Queue<T>::getFront() const
{
	if (!isEmpty())
	{
		return front->data;
	}
	exit(1);
}

// Check if queue is empty
template <typename T>
bool Queue<T>::isEmpty() const
{
	return front == NULL;
}

template <typename T>
void Queue<T>::eraseQueue()
{
	while (!isEmpty())
	{
		dequeue();
	}
}

template <typename T>
void Queue<T>::copyQueue(Queue<T> const& other)
{
	back = NULL;
	if (!other.isEmpty())
	{
		Node<T> *p = other.front;
		while (p)
		{
			enqueue(p->data);
			p = p->next;
		}
	}
}