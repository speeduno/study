#include <stdio.h>
void recursive_func(int n) { // n : 5
	if (n == 0)
		return;
	printf("before call : %d \n", n);
	recursive_func(n - 1);
	printf("after call : %d \n", n);
}
/*
void main() {
	recursive_func(5);
}
*/