#include <stdio.h>

#define MAX 8
int tmp[MAX];
void merge(int list[], int left, int mid, int right) { 
	int l_idx, r_idx, c_idx, t_idx;
	// l_idx : ���� �迭�� Ŀ��
	// r_idx : ������ �迭�� Ŀ�� 
	// c_idx : �������� �����ϴ� �迭�� ���� ��ġ
	// t_idx : ���� ���Ҹ� �Ѳ����� ������ �� ����� �ӽ� �ε���
	l_idx = c_idx = left;
	r_idx = mid + 1;

	while (l_idx <= mid && r_idx <= right) { // l_idx <= 3 && r_idx <= 7
		if (list[l_idx] <= list[r_idx])
			tmp[c_idx++] = list[l_idx++];
		else
			tmp[c_idx++] = list[r_idx++];
		
	}

	if (l_idx>mid) {
		for (t_idx = r_idx; t_idx <= right; t_idx++)
			tmp[c_idx++] = list[t_idx];
	}
	else {
		for (t_idx = l_idx; t_idx <= mid; t_idx++)
			// (t_idx = 2; t_idx <= 3; t_idx++)
			tmp[c_idx++] = list[t_idx];  
	}
	
	// ���纻�� ������ ������ ����
	for (t_idx = left; t_idx <= right; t_idx++) {
		list[t_idx] = tmp[t_idx];
	}

	printf("SORTED : ");
	l_idx = -1;
	while (tmp[++l_idx] != 0) {
		printf("%d ", tmp[l_idx]);
	}
	printf("\n");
}


void merge_sort(int list[], int left, int right) {
	int mid;

	if (left == right) { // ���� �����ϴ� �迭�� ���Ұ� 1������ �迭�̴�? 
		return;
	}
	mid = (left + right) / 2; // ��� �ε����� ����
	merge_sort(list, left, mid);  // divide (left ~ mid)
	merge_sort(list, mid + 1, right);  // divide( mid +1 ~ right )
	merge(list, left, mid, right); // conquer
}

int main()
{
	int arr[MAX] = { 7, 8, 5, 4, 6, 1, 3, 2 };

	printf("Given array is \n");
	for (int i = 0; i < MAX; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	merge_sort(arr, 0, MAX - 1);

	printf("\nSorted array is \n");
	for (int i = 0; i < MAX; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}


