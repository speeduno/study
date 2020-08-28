
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


// AVL 트리 함수
int height(NODE* n);
int balance_factor(NODE* tmp);
void check_balance(NODE** p, int data);
void rotate(NODE** p, int b_factor);


NODE* root = NULL;

NODE* init(int data) {
	NODE* tmp = (NODE*)malloc(sizeof(NODE));
	if (tmp) {
		memset(tmp, NULL, sizeof(NODE));
		tmp->data = data;
	}
	return tmp;
}

void add(int data, NODE** addr) {

	NODE* tmp = *addr;

	// 공석이면 노드 대입 -> 함수 종료
	if (!tmp) { // tmp == NULL
		*addr = init(data);
		printf("%d 저장 완료! \n", data);
		check_balance(&root, data); ////////////////////////
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


/*
	height() : 노드의 최대 높이를 구한다 ( 노드부터 가장 먼 곳의 단말 노드까지의 거리 )
	인자 : 높이를 구하고 싶은 노드
	리턴 : 높이
*/
int height(NODE* n) {
	int left_depth, right_depth;

	if (n == NULL) {
		return 0;
	}

	left_depth = height(n->left);
	right_depth = height(n->right);

	return (left_depth > right_depth ? left_depth : right_depth) + 1;
}
/*
	balance_factor() : 밸런스 팩터를 구한다. ( 절대값이 1 이하이 경우 균형으로 판단 )
	인자 : 밸런스 팩터를 구할 노드
	리턴 : 밸런트 팩터
*/
int balance_factor(NODE* tmp) {
	return height(tmp->left) - height(tmp->right);
}
void check_balance(NODE** p, int data) {
	int b;
	NODE* n = *p;
	if (!n) {
		return;
	}
	// 현재 노드가 추가된 노드와 같다면 함수 종료
	if (data == n->data) {
		return;
	}

	// 그렇지 않으면 (루트 ~ 새 노드까지의 경유 노드라면)밸런스 팩터 구함
	b = balance_factor(n); // 밸런스 팩터 구하기 
	if (abs(b) > 1) { // 불균형 상태라면 ( b < -1 || b > 1 )
		rotate(p, b); // 회전 실행
	}
	check_balance(data < n->data ? &n->left : &n->right, data);

}
void rotate(NODE** p, int b_factor) {
	printf("회전 실행! \n");
	NODE* tmp = *p;
	int first = b_factor > 0; // 1 : L, 0 : R
	int second = first ? (balance_factor(tmp->left) > 0) : (balance_factor(tmp->right) > 0);
	// L이면 left의 밸런스팩터를 확인하고 R이면 right의 밸런스팩터를 확인한다.
	// 이때 나온 결과가 1이면 L, 0이면 R
	NODE* median; // 중간값

	// 1) LR (first == 1 && second == 0)
	if (first && !second) {
		printf("LR 실행! tmp : %p \n", tmp);
		median = tmp->left;
		tmp->left = median->right;
		tmp->left->left = median;
		median->right = NULL;
		second = 1; // LL 로 변경되었음을 표시 (바로 밑의 LL 회전이 실행 되도록)
	}
	// 2) LL (first == 1 && second == 1)
	if (first && second) {
		printf("LL 실행! tmp : %p \n", tmp);
		median = tmp->left;
		tmp->left = median->right;
		median->right = tmp;
		*p = median;
	}

	// 3) RL
	if (!first && second) {
		printf("RL 실행! tmp : %p \n", tmp);
		median = tmp->right;
		tmp->right = median->left;
		tmp->right->right = median;
		median->left = NULL;
		second = 0;
	}
	// 4) RR
	if (!first && !second) {
		printf("RR 실행! tmp : %p \n", tmp);
		median = tmp->right;
		tmp->right = median->left;
		median->left = tmp;
		*p = median;
	}
}


void preorder(NODE* tmp) { // 전위 순회
	if (!tmp) {
		return;
	}
	printf("%d, ", tmp->data); // N 노드 확인
	printf("높이 : %d \n", height(tmp)); // 노드의 높이 //////////////////////
	printf("밸런스 팩터 : %d \n", balance_factor(tmp)); //////////////////////
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
	add(50, &root);
	add(150, &root);
	add(100, &root);
	add(75, &root);
	add(25, &root);

	add(125, &root);
	add(60, &root);
	add(80, &root);
	add(55, &root);
	add(175, &root);

	add(135, &root);
	add(160, &root);
	add(200, &root);
	add(85, &root);
	add(130, &root);

	add(53, &root);
	add(57, &root);
	add(83, &root);

	preorder(root);
	printf("\n");

}
