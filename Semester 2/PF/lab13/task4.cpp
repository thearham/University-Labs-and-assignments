#include <iostream>
#include <fstream>
using namespace std;

int main(){
	int matrix[2][4];
	int matrix2[4][2];
	ifstream file("data.txt");

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			file >> matrix[i][j];
		}
	}

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			matrix2[i][j] = matrix[j][i];
		}
	}
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			if (matrix2[i][j] == (-99))
			{
				continue;
			}
			cout << matrix2[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}