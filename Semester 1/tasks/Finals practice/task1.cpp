#include <iostream>
using namespace std;

int main()
{
	int i, j, size = 8;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if ((i+j == 0) || (i == 0 && j == 11) || (i == 4 && j == 0) || (i==4 && j == 11))
			{
				cout << "+";
			}
			else if (i == 2 && j == 0 || i == 2 && j == 11)
			{
				cout << "|";
			}
			else if (i == 0 && j % 2 == 0 || i == 4 && j % 2 == 0)
			{
				cout << "\\";
			}
			else if (i == 0 && j % 2 != 0 || i == 4 && j % 2 != 0)
			{
				cout << "/";
			}
			else {
				cout << " ";
			}
		}
		cout << "\n";
	}

	system("pause");
	return 0; 
}