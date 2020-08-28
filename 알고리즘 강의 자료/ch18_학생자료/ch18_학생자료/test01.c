/*
	< ���� Ž�� Ʈ���� ����, ��ȸ >
	1. ���� 
		- ��Ʈ���� ������ ����
		- �θ� ��庸�� ���� ��� ����, Ŭ ��� �����ʿ� �߰�
		- ���� �ڽ��� ���� �ڸ��� �ٸ� ��尡 ������ ��� �� ��带 �θ� ���� �����Ͽ� ��
		- ������ �Ϸ� �� ������ �ݺ� 
		- �ߺ��� ���Ұ� �ִ� ��� ������ ���� ����

	2. ��ȸ 
		- ��� ȣ���� ���� ����
		- ����Ž��(preorder) : �ڽ��� ���� ���� ��ȸ�� �� ����, ������ ������ �ڼ� ��带 Ž�� 
								( N - L - R )
		  ����Ž��(inorder) : ����, �ڽ�, ������ ������ ��ȸ ( L - N - R )
		  ����Ž��(postorder) : ����, ������, �ڽ� ������ ��ȸ ( L - R - N )
*/

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define TRUE 1
#define FALSE 0

typedef struct node {
	int data;
	struct node* left;  // ���� �ڽĳ���� �ּ�
	struct node* right; // ������ �ڽĳ���� �ּ�
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

	// �����̸� ��� ���� -> �Լ� ����
	if (!tmp) { // tmp == NULL
		*addr = init(data);
		printf("%d ���� �Ϸ�! \n", data);
	}
	// data�� ���� ��� -> ���� �ڽ�����
	else if (data < tmp->data) {
		add(data, &tmp->left);
	}
	// data�� Ŭ ��� -> ������ �ڽ�����
	else if (data > tmp->data) {
		add(data, &tmp->right);
	}
	// data�� ���� ��� -> ���� X, �Լ� ����
	else {
		printf("�ߺ� ���Ҵ� ������ �� �����ϴ�. \n");
	}
}

void preorder(NODE* tmp) { // ���� ��ȸ
	if (!tmp) {
		return;
	}
	printf("%d ", tmp->data); // N ��� Ȯ��
	preorder(tmp->left); // L ���� �̵�
	preorder(tmp->right); // R ������ �̵�
}
void inorder(NODE* tmp) { // ���� ��ȸ
	if (!tmp) {
		return;
	}
	inorder(tmp->left);
	printf("%d ", tmp->data);
	inorder(tmp->right);
}
void postorder(NODE* tmp) { // ���� ��ȸ
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
		printf("%dȸ° Ȯ����.. \n", ++cnt);
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
		printf("������ �����Ͱ� �����ϴ�. \n");
	}

	// tmp�� ������ ����?
	else if (tmp->data == data) {
		// *p : tmp(������ ���)�� ����Ǿ��ִ� ��
		// ( tmp�� ��Ʈ��� : root / �Ϲ� ����� : �ڽ��� �����ִ� �θ��� ���� right Ȥ�� left )

		// �ڽ� ��尡 2����?
		if (tmp->left && tmp->right) {
			// �İ��� ��� ���� (���� �ڼ� ��� �� ���� ū ��)
			NODE* heir = tmp->left;
			while (heir->right) {
				heir = heir->right;
			}

			// �İ��� ����� ������ ����
			tmp->data = heir->data;

			// �İ��� ��� ����
			delete(heir->data, &tmp->left);
		}

		// �ڽ� ��尡 ���� 1����?
		else if (tmp->left) {
			*p = tmp->left; // �θ�� �ڽ��� ����
			printf("%d ���� �Ϸ�! \n", tmp->data);
			free(tmp);
		}
		// �ڽ� ��尡 ������ 1���ų�, �ڽ��� 0����?
		else {
			*p = tmp->right; // �θ�� �ڽ��� ����
			printf("%d ���� �Ϸ�! \n", tmp->data);
			free(tmp);
		}
		
	}

	// data�� tmp ���� �۴�?
	else if (data < tmp->data) {
		delete(data, &tmp->left);
	}
	// data�� tmp ���� ũ��?
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

	printf("���� : ");
	preorder(root);
	printf("\n");

	printf("���� : ");
	inorder(root);
	printf("\n");

	printf("���� : ");
	postorder(root);
	printf("\n");

	/*if (search(55)) {
		printf("�ֽ��ϴ�! \n");
	}
	else {
		printf("�����ϴ�! \n");
	}*/

	delete(75, &root);
	printf("���� : ");
	preorder(root);
	printf("\n");
}
