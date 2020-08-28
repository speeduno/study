#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(a, b) { int c = a; a = b; b = c; }
#define MAX 10

void quick_sort(int* arr, int start, int end) {
	int pivot = arr[(end + start) / 2];
	int i = start;
	int j = end;
	while (i <= j) {
		while (arr[i] < pivot) {
			++i;
		}
		while (arr[j] > pivot) {
			--j;
		}
		if (i <= j) {
			SWAP(arr[i], arr[j]);
			++i;
			--j;
		}
	}
	if (start < j) {
		quick_sort(arr, start, j);
	}
	if (i < end) {
		quick_sort(arr, i, end);
	}

}
void print_array(int* data) {
	for (int i = 0; i < MAX; ++i) {
		printf("%d\t", data[i]);
	}
	printf("\n");
}

void set_data(int* data) {
	srand(time(0));
	for (int i = 0; i < MAX; ++i) {
		data[i] = rand() % 1000;
	}
}

void main() {
	int a[MAX] = { 0, };
	set_data(a);				// 테스트용 난수 생성
	print_array(a);				// 정렬 전
	quick_sort(a, 0, MAX - 1);	// 퀵소트
	print_array(a);				// 정렬 후
}