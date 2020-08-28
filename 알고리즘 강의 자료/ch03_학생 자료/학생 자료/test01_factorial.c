#include <stdio.h>

int factorial(int n) { // n : 5
	if (n == 1) 
		return n;
	return n * factorial(n - 1);
}

/*
void main() {
	printf("%d \n", factorial(5));
}
*/
