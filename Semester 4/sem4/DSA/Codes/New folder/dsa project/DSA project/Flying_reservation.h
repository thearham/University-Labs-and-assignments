#include<iostream>
#include<fstream>
using namespace std;

struct Details
{

	void Flights()
	{
		cout << "\n************************************************************************\n";
		cout << "\n************************************************************************\n\n";

		string flights;
		ifstream fin;

		fin.open("Regular flights.txt", ios::in);
		if (!fin)
			cout << "\n File is not open.";
		else
		{
			while (!fin.eof())
			{
				fin >> flights;
				if (flights == "!")
				{
					cout << endl;
				}
				else
					cout << flights;
			}
		}
		cout << "\n************************************************************************\n";
		cout << "\n************************************************************************\n";
	}
	void Customers()
	{
		string customer;
		cout << "\n************************************************************************\n";
		cout << "\n************************************************************************\n\n";
		ifstream fin;
		fin.open("Customer.txt", ios::in);
		if (!fin)
			cout << "\nCustomer file is not opened.";
		else
		{
			while (!fin.eof())
			{
				fin >> customer;
				if (customer == ".")
				{
					cout << endl;
				}
				else
					cout << customer << "     ";
			}
		}

		cout << "\n************************************************************************\n";
		cout << "\n************************************************************************\n";

	}
	void Planes()
	{
		string planes;

		cout << "\n************************************************************************\n";
		cout << "\n************************************************************************\n\n";
		ifstream fin;
		fin.open("Planes.txt", ios::in);
		if (!fin)
			cout << "\nCustomer file is not opened.";
		else
		{
			while (!fin.eof())
			{
				fin >> planes;
				if (planes == ".")
				{
					cout << endl;
				}
				else
					cout << planes << "         ";
			}
		}

		cout << "\n************************************************************************\n";
		cout << "\n************************************************************************\n";
	}
	void Offers()
	{
		string offers;

		cout << "\n************************************************************************\n";
		cout << "\n************************************************************************\n\n";
		ifstream fin;
		fin.open("Offers.txt", ios::in);
		if (!fin)
			cout << "\nCustomer file is not opened.";
		else
		{
			while (!fin.eof())
			{
				fin >> offers;
				if (offers == ".")
				{
					cout << endl;
				}
				else
					cout << offers << "   ";
			}
		}

		cout << "\n************************************************************************\n";
		cout << "\n************************************************************************\n";
	}

};