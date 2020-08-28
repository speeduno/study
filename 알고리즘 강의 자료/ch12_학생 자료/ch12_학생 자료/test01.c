#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}NODE;

NODE* head = NULL;

// ��� ���� �Լ� : init()
NODE* init(int data) {
	NODE* n = (NODE*)malloc(sizeof(NODE));
	n->data = data;
	n->next = NULL;
	return n;
}

// ��� ���� + ���� �Լ� : add()
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
	F10 : �ڵ� �� �� �� �� ���� (�Լ�--> ���� ���� X --> ���ϰ��� ����)
	F11 : �ڵ� �� �� �� �� ���� (�Լ�--> ���� ���� 0)
	F7 : ����� ����
*/

