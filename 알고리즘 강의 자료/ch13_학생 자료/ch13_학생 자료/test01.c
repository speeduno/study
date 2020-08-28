#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct node {
	int data;
	struct node* next;
}NODE;

NODE* head = NULL;

// 노드 생성 함수 : init()
NODE* init(int data) {
	NODE* n = (NODE*)malloc(sizeof(NODE));
	n->data = data;
	n->next = NULL;
	return n;
}

// 노드 생성 + 연결 함수 : add()
void add(NODE** head_ptr, int data) {

	if (*head_ptr == NULL) {
		*head_ptr = init(data);
		return;
	}
	
	add(&(*head_ptr)->next, data);
}

void peek() {
	NODE* tmp = head;
	while (tmp) {
		printf("%d \n", tmp->data);
		tmp = tmp->next;
	}
}

int update(int old_data, int new_data) {
	NODE* tmp = head;
	while (tmp) {
		if (tmp->data == old_data) {
			tmp->data = new_data;
			return TRUE;
		}
		tmp = tmp->next;
	}
	return FALSE;
}
/* insert v1
int insert(int index, int new_data) {

	// 1. 새 노드 삽입
	NODE* new_node = init(new_data);


	// 2. [0]에 삽입?
	if (index == 0) {
		new_node->next = head;
		head = new_node;
		return TRUE;
	}

	// 3. 그렇지 않으면.. 탐색 
	int cnt = 0;
	NODE* tmp = head;
	while (tmp) {

		if (cnt + 1 == index) {
			new_node->next = tmp->next;
			tmp->next = new_node;
			return TRUE;
		}

		++cnt;
		tmp = tmp->next;
	}

	//    잘못된 위치인 경우 만들어둔 새 노드를 해제
	free(new_node);
	return FALSE; 
}
*/

// insert v2
int insert(NODE** p, int index, int new_data) {
	// p : 0x1000
	// index : 0
	// new_data : 100
	// cnt : 0
	int cnt = 0;
	while (cnt != index && *p != NULL) {
		p = &(*p)->next;
		cnt++;
	}
	if (cnt == index) {
		// new_node = 0x500
		NODE* new_node = init(new_data);
		new_node->next = *p;
		*p = new_node;
		return TRUE;
	}
	return FALSE;
}

int remove(NODE** parent, int data) {
	// parent : 삭제할 노드의 앞 노드 중, next의 주소 
	//          head의 주소 
	//			==> 삭제할 노드의 주소가 있었던 곳의 주소
	if (*parent == NULL) {
		return FALSE;
	}

	if ((*parent)->data == data) { // 삭제 실행
		NODE* target = *parent;
		*parent = target->next;
		free(target);
		return TRUE;
	}

	remove(&(*parent)->next, data); // 다음 노드를 대상으로 remove() 재귀호출
}

void main() {
	add(&head, 10);
	add(&head, 20);
	add(&head, 30);
	add(&head, 40);
	add(&head, 50);

	/*if (update(20, 200)) {  // 20 을 200으로 수정
		printf("수정 완료! \n");
	}
	else {
		printf("수정 실패 \n");
	}*/

	/* insert V.1
	if (insert(10, 100)) { // [2]번에 100을 삽입 ==? 10 20 100 30 40 50
		printf("삽입 완료! \n");
	}
	else {
		printf("삽입 실패 \n");
	}
	*/

	/* insert V.2
	if (insert(&head, 0, 100)) { // [0]번에 100을 삽입 ==? 100 10 20 30 40 50
		printf("삽입 완료! \n");
	}
	else {
		printf("삽입 실패 \n");
	}*/
	if (remove(&head, 40)) { // 40을 삭제
		printf("삭제 완료! \n");
	}
	else {
		printf("삭제 실패 \n");
	}
	peek();
}

/*
	F10 : 코드 한 줄 한 줄 실행 (함수--> 내부 진입 X --> 리턴값만 받음)
	F11 : 코드 한 줄 한 줄 실행 (함수--> 내부 진입 0)
	F7 : 디버깅 종료
*/

