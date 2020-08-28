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
	int i; // ���ĵ� ������ �ε���
	int j; // ���ĵ� ���� ���� ���� �ִ� ���ҵ��� �ε���
	int remember; 
	for (i = 1; i < MAX; ++i) { // i : 0, 1, 2, 3, 4, 5, 6, 7
		remember = list[j=i];
		while (--j >= 0 && list[j] > remember) { // j�� 0 �̻��̰�, j�� ���Ұ� �ĺ� ���Һ��� Ŭ ����
			list[j + 1] = list[j]; // j�� ����ĭ�� j ���Ҹ� ����
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
	printf("���� �� : ");
	print_array(arr, MAX);

	insertion_sort(arr);

	printf("���� �� : ");
	print_array(arr, MAX);
}