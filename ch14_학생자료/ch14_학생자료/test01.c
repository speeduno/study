#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0


typedef struct node {
	int data;
	struct node* next;
	struct node* prev;
}NODE;

NODE* head = NULL;
NODE* tail = NULL;

NODE* init(int data);
int add(int data);
void peek();
void reverse_peek();
int search(int data);
int remove(int data);
int insert(int data, int index);

NODE* init(int data) {
	NODE* tmp = (NODE*)malloc(sizeof(NODE));
	tmp->data = data;
	tmp->next = NULL;
	tmp->prev = NULL;
	return tmp;
}
int add(int data) {
	NODE* tmp = init(data);

	// ù ��� �߰����
	if (head == NULL && tail == NULL) {	
		head = tail = tmp;
		return TRUE;
	}

	// �׷��� ������. tail�� �� ��带 ���
	// 1. ���� tail�� �� ����� prev�� ����
	tmp->prev = tail;
	
	// 2. ���� tail�� next�� �� ��� ����
	tail->next = tmp;

	// 2. tail�� �� ��� ���
	tail = tmp;
	return TRUE;
}
void peek() {
	NODE* tmp = head;
	printf("������ : ");
	while (tmp) {
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}
void reverse_peek() {
	NODE* tmp = tail;
	printf("������ : ");
	while (tmp) {
		printf("%d ", tmp->data);
		tmp = tmp->prev;
	}
	printf("\n");
}

int search(int data) {
	int cnt = 1;
	int flag = FALSE;
	NODE* tmp = head;
	while (tmp) {
		if (data == tmp->data) {
			flag = TRUE;
			break;
		}
		cnt++;
		tmp = tmp->next;
	}
	return flag ? cnt : 0;
}
int remove(int data) {
	NODE* tmp = head;
	NODE* target = NULL; 
	int flag = FALSE;
	while (tmp) {
		if (tmp->data == data) { // ������ ��带 ã����
			flag = TRUE;
			target = tmp;

			if (!target->prev) { // ������ ��尡 ���� ù ����� ���
				head = target->next;
			}
			else {// �׷��� ������ ������ ����� prev�� next�� ����
				target->prev->next = target->next;
			}

			if (!target->next) { // ������ ��尡 ���� ������ ����� ���
				tail = target->prev;
			}
			else { // �׷��� ������ ������ ����� next�� prev�� ����
				target->next->prev = target->prev;
			}

			free(target); // ���� ����
			break;
		}
		tmp = tmp->next;
	}
	return flag;
}
int insert(int data, int index) {
	int i;
	NODE* tmp = head;
	NODE* node = NULL; 
	for (i = 1; i < index; ++i) {
		if (!tmp)
			return FALSE;
		tmp = tmp->next;
	}

	// ���� ���ų� �� �������� �����ϴ� ���
	if (tmp == NULL) {
		add(data); // �Ϲ� add�� ������ ������ ����
		return TRUE;
	}

	node = init(data);

	// �� �� 
	if (tmp == head) {
		head = node;
		node->next = tmp;
		tmp->prev = node;
	}
	
	// �߰�
	else {
		node->next = tmp;
		node->prev = tmp->prev;
		tmp->prev->next = node;
		tmp->prev = node;
	}
	return TRUE;
}
void main() {
	int select;
	int data;
	int index;
	while (TRUE) {
		peek();
		reverse_peek();
		printf("1. ��� �߰� \n");
		printf("2. ��� �˻� \n");
		printf("3. ��� ���� \n");
		printf("4. ��� ���� \n");
		printf("5. ���� \n");
		printf("�Է� : "); 
		scanf_s("%d", &select);
		switch (select) {
		case 1: // ��� �߰�
			printf("�߰��� ������ :");
			scanf_s("%d", &data);
			printf("%s\n", add(data) ? "�߰� �Ϸ�!" : "�߰� ����!");
			break;
		case 2: // ��� �˻�
			printf("�˻��� ������ :");
			scanf_s("%d", &data);
			index = search(data);
			if (index)
				printf("%d(��)�� %d���� �ֽ��ϴ�.\n", data, index);
			else
				printf("�̵�� ��� \n");
			break;
		case 3: // ��� ����
			printf("������ ������ :");
			scanf_s("%d", &data);
			printf("%s\n", remove(data) ? "���� �Ϸ�!" : "���� ����!");
			break;
		case 4: // ��� ����
			printf("�� ������ :");
			scanf_s("%d", &data);
			printf("������ ��ġ : ");
			scanf_s("%d", &index);
			printf("%s\n", insert(data, index) ? "���� �Ϸ�!" : "���� ����!");
			break;
		case 5:
			printf("���α׷��� �����մϴ�. \n");
			exit(0);
		default:
			printf("�߸��� �Է��Դϴ�. \n");
		}

		system("pause");
		system("cls");
	}
}