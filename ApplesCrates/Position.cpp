/*
 * Author: Merlin Mehmed 
 */
#include "stdafx.h"

struct pos
{
	int x;
	int y;

	pos()
	{
		x = 0;
		y = 0;
	}

	pos(int i, int j)
	{
		x = i;
		y = j;
	}

	pos& operator=(pos const& p)
	{
		if (this != &p)
		{
			x = p.x;
			y = p.y;
		}

		return *this;
	}
};