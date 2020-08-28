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

#define TRUE 1
#define FALSE 0

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

int search(int data) { 
	NODE* tmp = root;
	static int cnt = 0;
	while (tmp) {
		printf("%d회째 확인중.. \n", ++cnt);
		if (tmp->data == data) {
			return TRUE;
		}
		if (data < tmp->data) {
			tmp = tmp->left;
		}
		else if (data > tmp->data) {
			tmp = tmp->right;
		}
	}
	return FALSE;
}

void delete(int data, NODE** p) {
	NODE* tmp = *p;
	if (tmp == NULL) {
		printf("삭제할 데이터가 없습니다. \n");
	}

	// tmp가 삭제할 노드니?
	else if (tmp->data == data) {
		// *p : tmp(삭제할 노드)가 저장되어있는 곳
		// ( tmp가 루트라면 : root / 일반 노드라면 : 자신이 적혀있는 부모노드 측의 right 혹은 left )

		// 자식 노드가 2개니?
		if (tmp->left && tmp->right) {
			// 후계자 노드 설정 (왼쪽 자손 노드 중 가장 큰 수)
			NODE* heir = tmp->left;
			while (heir->right) {
				heir = heir->right;
			}

			// 후계자 노드의 데이터 복사
			tmp->data = heir->data;

			// 후계자 노드 삭제
			delete(heir->data, &tmp->left);
		}

		// 자식 노드가 왼쪽 1개니?
		else if (tmp->left) {
			*p = tmp->left; // 부모와 자식을 연결
			printf("%d 삭제 완료! \n", tmp->data);
			free(tmp);
		}
		// 자식 노드가 오른쪽 1개거나, 자식이 0개니?
		else {
			*p = tmp->right; // 부모와 자식을 연결
			printf("%d 삭제 완료! \n", tmp->data);
			free(tmp);
		}
		
	}

	// data가 tmp 보다 작니?
	else if (data < tmp->data) {
		delete(data, &tmp->left);
	}
	// data가 tmp 보다 크니?
	else {
		delete(data, &tmp->right);
	}
}


void main() {
	add(100, &root);
	add(50, &root);
	add(150, &root);
	add(25, &root);
	add(75, &root);
	add(125, &root);
	add(175, &root);
	add(60, &root);
	add(80, &root);
	add(135, &root);
	add(160, &root);
	add(200, &root);
	add(55, &root);
	add(85, &root);
	add(130, &root);
	add(53, &root);
	add(57, &root);
	add(83, &root);

	printf("전위 : ");
	preorder(root);
	printf("\n");

	printf("중위 : ");
	inorder(root);
	printf("\n");

	printf("후위 : ");
	postorder(root);
	printf("\n");

	/*if (search(55)) {
		printf("있습니다! \n");
	}
	else {
		printf("없습니다! \n");
	}*/

	delete(75, &root);
	printf("전위 : ");
	preorder(root);
	printf("\n");
}
