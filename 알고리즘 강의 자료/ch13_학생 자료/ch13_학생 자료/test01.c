#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

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

	// 1. �� ��� ����
	NODE* new_node = init(new_data);


	// 2. [0]�� ����?
	if (index == 0) {
		new_node->next = head;
		head = new_node;
		return TRUE;
	}

	// 3. �׷��� ������.. Ž�� 
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

	//    �߸��� ��ġ�� ��� ������ �� ��带 ����
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
	// parent : ������ ����� �� ��� ��, next�� �ּ� 
	//          head�� �ּ� 
	//			==> ������ ����� �ּҰ� �־��� ���� �ּ�
	if (*parent == NULL) {
		return FALSE;
	}

	if ((*parent)->data == data) { // ���� ����
		NODE* target = *parent;
		*parent = target->next;
		free(target);
		return TRUE;
	}

	remove(&(*parent)->next, data); // ���� ��带 ������� remove() ���ȣ��
}

void main() {
	add(&head, 10);
	add(&head, 20);
	add(&head, 30);
	add(&head, 40);
	add(&head, 50);

	/*if (update(20, 200)) {  // 20 �� 200���� ����
		printf("���� �Ϸ�! \n");
	}
	else {
		printf("���� ���� \n");
	}*/

	/* insert V.1
	if (insert(10, 100)) { // [2]���� 100�� ���� ==? 10 20 100 30 40 50
		printf("���� �Ϸ�! \n");
	}
	else {
		printf("���� ���� \n");
	}
	*/

	/* insert V.2
	if (insert(&head, 0, 100)) { // [0]���� 100�� ���� ==? 100 10 20 30 40 50
		printf("���� �Ϸ�! \n");
	}
	else {
		printf("���� ���� \n");
	}*/
	if (remove(&head, 40)) { // 40�� ����
		printf("���� �Ϸ�! \n");
	}
	else {
		printf("���� ���� \n");
	}
	peek();
}

/*
	F10 : �ڵ� �� �� �� �� ���� (�Լ�--> ���� ���� X --> ���ϰ��� ����)
	F11 : �ڵ� �� �� �� �� ���� (�Լ�--> ���� ���� 0)
	F7 : ����� ����
*/

