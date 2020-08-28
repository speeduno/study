#include <stdio.h>
#include <stdlib.h>

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

void main() {
	add(&head, 10);
	add(&head, 20);
	add(&head, 30);
	peek();
}

/*
	F10 : 코드 한 줄 한 줄 실행 (함수--> 내부 진입 X --> 리턴값만 받음)
	F11 : 코드 한 줄 한 줄 실행 (함수--> 내부 진입 0)
	F7 : 디버깅 종료
*/

