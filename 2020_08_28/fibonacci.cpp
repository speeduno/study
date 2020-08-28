#include <stdio.h>

int idx = 0;

int fibonacci(int n)
{
	if (n <= 1)
	{
		return n;
	}
		
	return fibonacci(n - 2) + fibonacci(n - 1);
}

int main()
{
	for (int i = 1; i <= 8; i++)
	{
		printf("Æ÷¹® : %d\n", fibonacci(i));
	}

	printf("Àç±Í : %d\n\n", fibonacci(8));

	return 0;
}