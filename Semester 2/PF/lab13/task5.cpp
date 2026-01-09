#include <iostream>
#include <fstream>
using namespace std;

int main(){
	int matrix1[2][4];
	int matrix2[2][4];
	int matrix3[2][4];
	ifstream file1("matrix1.txt");
	ifstream file2("matrix2.txt");

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			file1 >> matrix1[i][j];
			file2 >> matrix2[i][j];
		}
	}

	file1.close();
	file2.close();

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if(matrix1[i][j] == (-99) || matrix2[i][j] == (-99)){
				continue;
			}
			else
				matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}
	ofstream fout("output.txt");
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			
			fout << matrix3[i][j] << " ";
		}
		fout << endl;
	}
	fout.close();
	return 0;
}