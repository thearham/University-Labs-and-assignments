#pragma once
#include "Stack.h"
#include <fstream>
class mazeClass : public stack {
private:
	int size;
	int **maze;
public:
	mazeClass();
	mazeClass(int arr[][4], int size);
	bool isValidMove(int x, int y);
	void printMaze();
	void solveMaze();
	void saveMaze(string filename);
	~mazeClass();
};
mazeClass::mazeClass() {
	this->size = 0;
}
mazeClass::mazeClass(int arr[][4], int size) {
	this->size = size;
	maze = new int*[this->size];
	for (int i = 0; i < this->size; i++)
	{
		maze[i] = new int[this->size];
	}
	for (int i = 0; i < this->size; ++i) {
		for (int j = 0; j < this->size; ++j) {
			maze[i][j] = arr[i][j];
		}
	}
}
void mazeClass::printMaze() {
	for (int i = 0; i < this->size; ++i) {
		for (int j = 0; j < this->size; ++j) {
			cout << maze[i][j] << "\t";
		}
		cout << endl;
	}
}

bool mazeClass::isValidMove(int x, int y) {
	if (x >= 0 && x < this->size && y >= 0 && y < this->size && maze[x][y] == 1) {
		return true;
	}
	else {
		return false;
	}
}
void mazeClass::solveMaze() {
	int startRow = 0, startColumn = 0;
	int endRow = this->size - 1, endColumn = this->size - 1;
	int currentRow = 0;
	int currentColumn = 0;
	push(startRow, startColumn);
	
	while (!empty()) {
		 currentRow = toprow();
		 currentColumn = topcolumn();

		if (currentRow == endRow && currentColumn == endColumn) {
			maze[currentRow][currentColumn] = -1;
			break;
		}

		maze[currentRow][currentColumn] = -1;

		if (isValidMove(currentRow + 1, currentColumn)) {
			push(currentRow + 1, currentColumn);
		}
		else if (isValidMove(currentRow - 1, currentColumn)) {
			push(currentRow - 1, currentColumn);
		}
		else if (isValidMove(currentRow, currentColumn + 1)) {
			push(currentRow, currentColumn + 1);
		}
		else if (isValidMove(currentRow, currentColumn - 1)) {
			push(currentRow, currentColumn - 1);
		}
		else {
			pop();
		}
	}

	for (int i = 0; i < this->size; ++i) {
		for (int j = 0; j < this->size; ++j) {
			if (maze[i][j] == -1) {
				cout << "1\t";
			}
			else {
				cout << "0\t";
			}
		}
		cout <<endl;
	}
}
void mazeClass::saveMaze(string filename) {
	ofstream fout(filename);
	for (int i = 0; i < this->size; ++i) {
		for (int j = 0; j < this->size; ++j) {
			if (maze[i][j] == -1) {
				fout << "1\t";
			}
			else {
				fout << "0\t";
			}
		}
		fout <<endl;
	}
	fout.close();
}
mazeClass::~mazeClass()
{
	for (int i = 0; i < this->size; i++)
	{
		delete[] maze[i];
	}
	delete[]maze;
}

