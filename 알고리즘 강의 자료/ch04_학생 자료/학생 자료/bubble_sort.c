#include <stdio.h>
#define MAX 6

void bubble_sort(int arr[], int n) {
	int i, j, temp;
	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main() {
	int arr[MAX] = { 5, 4, 6, 1, 3, 2 };
	bubble_sort(arr, MAX);
	for (int i = 0; i < MAX; i++) {
		printf("%d\n", arr[i]);
	}
	return 0;
}