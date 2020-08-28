#include <stdio.h>

#define MAX 8
int tmp[MAX];
void merge(int list[], int left, int mid, int right) { 
	int l_idx, r_idx, c_idx, t_idx;
	// l_idx : 왼쪽 배열의 커서
	// r_idx : 오른쪽 배열의 커서 
	// c_idx : 작은수가 들어가야하는 배열의 현재 위치
	// t_idx : 남은 원소를 한꺼번에 저장할 때 사용할 임시 인덱스
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
	
	// 복사본의 내용을 원본에 복사
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

	if (left == right) { // 현재 봐야하는 배열이 원소가 1개뿐인 배열이니? 
		return;
	}
	mid = (left + right) / 2; // 가운데 인덱스를 구함
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


