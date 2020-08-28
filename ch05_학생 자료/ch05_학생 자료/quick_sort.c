#include <stdio.h>
#define MAX 8
#define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp) )

void quick_sort(int arr[MAX], int min, int max) {
	int l = min + 1;
	int r = max;
	int p = min;
	int tmp;
	int pivot;

	if (max - min <= 1) { 
		return; 
	}
	pivot = arr[min];
	while (l < r) {
		while (arr[l] < pivot && l < max) { 
			++l;
		}
		while (arr[r] > pivot && r > min) { 
			--r;
		}
		if (l <= r) {
			SWAP(arr[l], arr[r], tmp);
		}
	}

	if (min <= r) {
		SWAP(arr[min], arr[r], tmp);
		p = r;
	}

	quick_sort(arr, min, p - 1); // divide
	quick_sort(arr, p + 1, max); // divide
}
void quick_sort_test() {
	int arr[MAX] = { 4, 2, 6, 5, 8, 7, 1, 3 };
	quick_sort(arr, 0, MAX - 1);
}
