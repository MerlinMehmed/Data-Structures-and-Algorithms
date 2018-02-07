/*
 * Sudoku solver using backtracking
 * Author: Merlin Mehmed
 */

#include "stdafx.h"
#include <iostream>

const int N = 9;
const int EMPTY = 0;

// Searches the board to find empty box
// If found return true and location is saved in row and col
bool findEmpty(int board[N][N], int &row, int &col)
{
	for (row = 0; row < N; row++)
		for (col = 0; col < N; col++)
			if (board[row][col] == EMPTY)
				return true;
	return false;
}

// Searches if a number is already used in a row
bool isUsedInRow(int board[N][N], int row, int num)
{
	for (int col = 0; col < N; col++)
		if (board[row][col] == num)
			return true;
	return false;
}

// Searches if a number is already used in a column
bool isUsedInCol(int board[N][N], int col, int num)
{
	for (int row = 0; row < N; row++)
		if (board[row][col] == num)
			return true;
	return false;
}

// Searches if a number is already used in a box
// sRow - box start row
// sCol - box start column
bool isUsedInBox(int board[N][N], int sRow, int sCol, int num)
{
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			if (board[row + sRow][col + sCol] == num)
				return true;
	return false;
}

// Checks if a number is legal to assign
bool isLegal(int board[N][N], int row, int col, int num)
{
	return !isUsedInRow(board, row, num) &&
		!isUsedInCol(board, col, num) &&
		!isUsedInBox(board, row - row%3, col - col%3, num);
}

// Solves the sudoku
bool solve(int board[N][N])
{
	int row;
	int col;

	if (!findEmpty(board, row, col))
		return true;

	for (int num = 1; num <= N; num++)
	{
		if (isLegal(board, row, col, num))
		{
			board[row][col] = num;

			if (solve(board))
				return true;

			board[row][col] = EMPTY;
		}
	}
	return false;
}

// Prints the board
void printBoard(int board[N][N])

{
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < N; col++)
			printf("%2d", board[row][col]);
		printf("\n");
	}
}

