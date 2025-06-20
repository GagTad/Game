#include "Grid.h"
#include <iostream>


Grid::Grid() {

	numRows = 20;
	numCols = 10;
	cellSize = 30;
	initialize();
	//Print();
	colors = GetCellColors();

}
void Grid::initialize() {
	for (int row = 0; row < numRows; ++row)
	{
		for (int  column = 0; column < numCols; ++column)
		{
			grid[row][column] = 0;
		}
	}

}
void Grid::Print() {
	for (int row = 0; row < numRows; ++row)
	{
		for (int column = 0; column < numCols; column++)
		{
			std::cout << grid[row][column] << " ";
		}

		std::cout << std::endl;
	}

}

void Grid::Draw() {

	for (int row = 0; row < numRows; ++row)
	{
		for (int column = 0; column < numCols; ++column)
		{
			int cellvalue = grid[row][column];
			DrawRectangle(column * cellSize +11 , row * cellSize + 11, cellSize - 1, cellSize - 1, colors[cellvalue]);
		}
	}
}

bool Grid::IsCellOutside(int row , int column) {

	if (row >= 0 && row < numRows && column >= 0 && column < numCols)
	{
		return false;
	}

	return true;
}
bool Grid::IsCellEmpty(int row , int column) {

	if (grid[row][column] == 0) 
	{
		return true;
	}
	return false;
}

bool Grid::IsRowFull(int row) {

	for (int column = 0; column < numCols; ++column)
	{
		if (grid[row][column] == 0)
		{
			return false;
		}
	}
	return true;

}

void Grid::ClearRow(int row) {
	
	if (IsRowFull(row))
	{
		for (int column = 0; column < numCols; ++column)
		{
			grid[row][column] == 0;

		}
	}
}

void Grid::MoveRowDown(int row , int numRows) {
	
	for (int column = 0; column < numCols; ++column)
	{
		grid[row + numRows][column] = grid[row][column];
		grid[row][column] = 0;

	}

}

int Grid::ClearFullRows() {

	int completed = 0;
	for (int row = numRows - 1; row >= 0; --row)
	{
		if (IsRowFull(row))
		{
			ClearRow(row);
			completed++;
		}
		else if (completed > 0)
		{
			MoveRowDown(row, completed);
		}
	}
	return completed;

}
