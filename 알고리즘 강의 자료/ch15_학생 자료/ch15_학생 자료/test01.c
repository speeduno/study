#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define MAX 10

typedef struct node {
	int data;
	struct node* next;
}NODE;

NODE* table[MAX];

NODE* init(int data) {
	NODE* tmp = (NODE*)malloc(sizeof(NODE));
	tmp->next = NULL;
	tmp->data = data;
	return tmp;
}
int hash(int data) {
	return data % MAX;
}
int chain(int data) {
	int index = hash(data);
	if (!table[index]) {
		table[index] = init(data);
	}
	else {
		NODE* tmp = table[index];
		while (tmp->next) {
			tmp = tmp->next;
		}
		tmp->next = init(data);
	}
}
int peek() {
	for (int i = 0; i < MAX; ++i) {
		printf("table[%d] : ", i);
		NODE* tmp = table[i];
		while (tmp) {
			printf("%d ", tmp->data);
			tmp = tmp->next;
		}
		printf("\n");
	}
}
int search(int data) {
	int index = hash(data);
	NODE* tmp = table[index];
	while (tmp) {
		if (tmp->data == data) {
			return index;
		}
		tmp = tmp->next;
	}
	return -1;
}
void main() {
	int select;
	int data;
	int index;
	while (TRUE) {
		peek();
		printf("1. ��� �߰� \n");
		printf("2. ��� �˻� \n");
		printf("3. ���� \n");
		printf("�Է� : ");
		scanf_s("%d", &select);
		switch (select) {
		case 1: // ��� �߰�
			printf("�߰��� ������ :");
			scanf_s("%d", &data);
			chain(data);
			printf("�߰� �Ϸ�!\n");
			break;
		case 2: // ��� �˻�

			printf("�˻��� ������ :");
			scanf_s("%d", &data);
			if ((index = search(data)) != -1) {
				printf("%d(��)�� %d�� �ֽ��ϴ�. \n", data, index);
			}
			else {
				printf("�̵�� ���� \n");
			}
			break;
		case 3:
			printf("���α׷��� �����մϴ�. \n");
			exit(0);
		default:
			printf("�߸��� �Է��Դϴ�. \n");
		}

		system("pause");
		system("cls");
	}
}