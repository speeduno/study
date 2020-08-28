/*
	< 이진 탐색 트리의 삽입, 조회 >
	1. 삽입 
		- 루트부터 삽입을 시작
		- 부모 노드보다 작을 경우 왼쪽, 클 경우 오른쪽에 추가
		- 만약 자신이 있을 자리에 다른 노드가 존재할 경우 그 노드를 부모 노드로 지정하여 비교
		- 삽입이 완료 될 때까지 반복 
		- 중복된 원소가 있는 경우 삽입을 하지 않음

	2. 조회 
		- 재귀 호출을 통해 구현
		- 전위탐색(preorder) : 자신을 가장 먼저 조회한 후 왼쪽, 오른쪽 순으로 자손 노드를 탐색 
								( N - L - R )
		  중위탐색(inorder) : 왼쪽, 자신, 오른쪽 순으로 조회 ( L - N - R )
		  후위탐색(postorder) : 왼쪽, 오른쪽, 자신 순으로 조회 ( L - R - N )
*/

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct node {
	int data;
	struct node* left;  // 왼쪽 자식노드의 주소
	struct node* right; // 오른쪽 자식노드의 주소
}NODE;

NODE* root = NULL;

NODE* init(int data) {
	NODE* tmp = (NODE*)malloc(sizeof(NODE));
	memset(tmp, NULL, sizeof(NODE));
	tmp->data = data;
	return tmp;
}

void add(int data, NODE** addr) {

	NODE* tmp = *addr;

	// 공석이면 노드 대입 -> 함수 종료
	if (!tmp) { // tmp == NULL
		*addr = init(data);
		printf("%d 저장 완료! \n", data);
	}
	// data가 작을 경우 -> 왼쪽 자식으로
	else if (data < tmp->data) {
		add(data, &tmp->left);
	}
	// data가 클 경우 -> 오른쪽 자식으로
	else if (data > tmp->data) {
		add(data, &tmp->right);
	}
	// data가 같을 경우 -> 저장 X, 함수 종료
	else {
		printf("중복 원소는 저장할 수 없습니다. \n");
	}
}

void preorder(NODE* tmp) { // 전위 순회
	if (!tmp) {
		return;
	}
	printf("%d ", tmp->data); // N 노드 확인
	preorder(tmp->left); // L 왼쪽 이동
	preorder(tmp->right); // R 오른쪽 이동
}
void inorder(NODE* tmp) { // 중위 순회
	if (!tmp) {
		return;
	}
	inorder(tmp->left);
	printf("%d ", tmp->data);
	inorder(tmp->right);
}
void postorder(NODE* tmp) { // 후위 순회
	if (!tmp) {
		return;
	}
	postorder(tmp->left);
	postorder(tmp->right);
	printf("%d ", tmp->data);
}
void main() {
	add(100, &root);
	add(150, &root);
	add(50, &root);
	add(75, &root);
	add(200, &root);
	add(35, &root);
	add(75, &root);
	add(80, &root);

	printf("전위 : ");
	preorder(root);
	printf("\n");

	printf("중위 : ");
	inorder(root);
	printf("\n");

	printf("후위 : ");
	postorder(root);
	printf("\n");
}
