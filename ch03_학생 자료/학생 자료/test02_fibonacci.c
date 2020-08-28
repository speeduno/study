#include <stdio.h>

int fibonacci(int n) { // n : 4
	printf("n : %d \n", n);
	if (n <= 1) 
		return n;
	return fibonacci(n - 2) + fibonacci(n - 1);
}


void main() {
	int i;
	for (i = 1; i <= 10; ++i) 
		fibonacci(i);
	
}