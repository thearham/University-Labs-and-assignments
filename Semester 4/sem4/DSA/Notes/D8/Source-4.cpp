#include <iostream>
int fact(int n)
{
	if (n > 0)
		return n*fact(n - 1);

	else if (n == 0)
		return 1;
}

int sum(int n)
{
	if (n > 0)
		return n+sum(n - 1);

	else if (n == 0)
		return 0;
}

int fib(int n)
{
	if (n > 2)
		return fib(n - 1) + fib(n - 2);
	else if (n == 2)
		return 1;
	else if (n == 1)
		return 0;
}

int count(int n)
{
	if (n > 0)
		return 1 + count(n / 10);
	else if (n == 0)
		return 0;
}

int sumOfDigits(int n)
{
	if (n > 0)
		return (n%10) + sumOfDigits(n / 10);
	else if (n == 0)
		return 0;
}

void d2B(int n)
{
	if (n > 0)
	{
		d2B(n / 2);
		std::cout << n % 2;
	}
	
}

int main()
{
	d2B(29);
	std::cout << std::endl;
	return 0;
}