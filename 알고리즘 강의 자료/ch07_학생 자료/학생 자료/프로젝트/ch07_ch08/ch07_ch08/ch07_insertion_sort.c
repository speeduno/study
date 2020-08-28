#include <stdio.h>

#define MAX 8

void print_array(int list[], int n) {
	int i;
	for (i = 0; i < n; ++i) {
		printf("%d ", list[i]);
	}
	printf("\n");
}


void insertion_sort(int list[]) {
	int i; // 정렬될 원소의 인덱스
	int j; // 정렬될 원소 기준 왼편에 있는 원소들의 인덱스
	int remember; 
	for (i = 1; i < MAX; ++i) { // i : 0, 1, 2, 3, 4, 5, 6, 7
		remember = list[j=i];
		while (--j >= 0 && list[j] > remember) { // j가 0 이상이고, j번 원소가 후보 원소보다 클 동안
			list[j + 1] = list[j]; // j의 다음칸에 j 원소를 대입
		}
		/*
		remember = list[i];
		for(j = i -1 ; j >= 0 && list[j] > remember; --j)
			list[j + 1] = list[j];*/

		list[j + 1] = remember;
	}
}
void main() {

	int arr[MAX] = { 8,7,4,6,1,3,2,5 };
	printf("정렬 전 : ");
	print_array(arr, MAX);

	insertion_sort(arr);

	printf("정렬 후 : ");
	print_array(arr, MAX);
}