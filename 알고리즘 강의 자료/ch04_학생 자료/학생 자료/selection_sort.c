#include <stdio.h>
#define MAX 6

void selection_sort(int arr[], int n)
{
	int i, j, minIndex, tmp;

	for (i = 0; i < n - 1; i++)
	{
		minIndex = i;
		for (j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}
		tmp = arr[minIndex];
		arr[minIndex] = arr[i];
		arr[i] = tmp;
	}
}

/*
int main() {
	int arr[MAX] = { 5, 4, 6, 1, 3, 2 };
	selection_sort(arr, MAX);
	for (int i = 0; i < MAX; i++) {
		printf("%d\n", arr[i]);
	}
	return 0;
}
*/



