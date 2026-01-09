#include "Maze.h"
#include <sstream>

int main()
{
	int mazearray[4][4];
	int size = 4;
	
	ifstream fin("input.txt");
	if (!fin.is_open()) {
        cout << "Unable to open the file" << endl;
        return 1; 
    }
    string line;
    int numRows = 0;
    while (getline(fin, line) && numRows < size) {
        istringstream iss(line);

        int numCols = 0;
        int value;

        while (iss >> value && numCols < size) {
            mazearray[numRows][numCols] = value;
            ++numCols;
        }

        ++numRows;
    }
    fin.close();

	mazeClass maze(mazearray, size);

	cout << "The given maze is:" << endl;
	maze.printMaze();

	cout << "\nThe solution of given maze is:" << endl;
	maze.solveMaze();
	maze.saveMaze("output.txt");
	system("pause");
	return 0;
}
