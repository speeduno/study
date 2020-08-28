#include <stdio.h>
#define MAX 8

void print_array(int list[]){
	int i;
	for(i = 0; i < MAX; ++i){
		printf("%d ", list[i]);
	}
}
void bubble_sort(int arr[]) {
	int tmp;
	int i, j;
	for (i = MAX; i > 0; --i) {
		for (j = 0; j < i-1; ++j) {
			if (arr[j] > arr[j + 1]) {
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}
}

void main() {
	int arr[MAX] = { 4, 5, 7, 1, 3, 6, 8, 2 };
	//int arr[MAX] = { 1,2,3,4,5,6,7,8 };
	//int arr[MAX] = { 8,7,6,5,4,3,2,1 };
	printf("Before : ");
	print_array(arr);

	bubble_sort(arr);

	printf("After : ");
	print_array(arr);
}