/*
 * Author: Merlin Mehmed
 */

#include "stdafx.h"
#include "Queue.cpp"
#include "Position.cpp"
#include <iostream>
using namespace std;

const int R = 3; // crate rows
const int C = 5; // crate columns

bool isValid(int x, int y)
{
	return x >= 0 && y >= 0 && x <= R && y <= C;
}

bool areRotten(int crate[R][C])
{
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (crate[i][j] == 1)
				return false;
	return true;
}

void print(int crate[R][C])
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
			cout << crate[i][j] << ' ';
		cout << endl;
	}
	cout << endl;
}

int rotApples(int crate[R][C])
{
	int steps = 1;
	Queue<pos> q;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (crate[i][j] == 2)
				q.enqueue(pos(i, j));
	q.enqueue(pos(-1, -1));

	while (!q.isEmpty())
	{
		pos cur = q.dequeue();
		if (isValid(cur.x - 1, cur.y) && crate[cur.x - 1][cur.y] == 1)
		{
			crate[cur.x - 1][cur.y] = 2;
			q.enqueue(pos(cur.x - 1, cur.y));
		}
		if (isValid(cur.x + 1, cur.y) && crate[cur.x + 1][cur.y] == 1)
		{
			crate[cur.x + 1][cur.y] = 2;
			q.enqueue(pos(cur.x + 1, cur.y));
		}
		if (isValid(cur.x, cur.y + 1) && crate[cur.x][cur.y + 1] == 1)
		{
			crate[cur.x][cur.y + 1] = 2;
			q.enqueue(pos(cur.x, cur.y + 1));
		}
		if (isValid(cur.x, cur.y - 1) && crate[cur.x][cur.y - 1] == 1)
		{
			crate[cur.x][cur.y - 1] = 2;
			q.enqueue(pos(cur.x, cur.y - 1));
		}

		if (cur.x == -1)
		{
			steps++;
			if (q.isEmpty())
			{
				steps = -1;
				break;
			}
			q.enqueue(pos(-1, -1));
		}

		if (areRotten(crate) || q.isEmpty())
			break;
	}
	return steps;
}