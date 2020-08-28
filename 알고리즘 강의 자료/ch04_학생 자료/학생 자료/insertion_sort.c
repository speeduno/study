#include <stdio.h>
#define MAX 6

void insertion_sort(int data[], int n)
{
	int i, j, remember;
	for (i = 1; i < n; i++)
	{
		remember = data[(j = i)];
		while (--j >= 0 && remember < data[j]) {
			for (int a = 0; a < MAX; ++a) {
				printf("%d ", data[a]);
			}
			printf("\n");
	
			data[j + 1] = data[j];
			data[j] = remember;
		}
	}
}
/*
int main() {
	int arr[MAX] = { 5, 4, 6, 1, 3, 2 };
	insertion_sort(arr, MAX);
	for (int i = 0; i < MAX; i++) {
		printf("%d\n", arr[i]);
	}
	return 0;
}
*/



