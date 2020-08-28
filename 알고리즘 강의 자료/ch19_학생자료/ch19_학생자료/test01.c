
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


// AVL Ʈ�� �Լ�
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

	// �����̸� ��� ���� -> �Լ� ����
	if (!tmp) { // tmp == NULL
		*addr = init(data);
		printf("%d ���� �Ϸ�! \n", data);
		check_balance(&root, data); ////////////////////////
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


/*
	height() : ����� �ִ� ���̸� ���Ѵ� ( ������ ���� �� ���� �ܸ� �������� �Ÿ� )
	���� : ���̸� ���ϰ� ���� ���
	���� : ����
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
	balance_factor() : �뷱�� ���͸� ���Ѵ�. ( ���밪�� 1 ������ ��� �������� �Ǵ� )
	���� : �뷱�� ���͸� ���� ���
	���� : �뷱Ʈ ����
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
	// ���� ��尡 �߰��� ���� ���ٸ� �Լ� ����
	if (data == n->data) {
		return;
	}

	// �׷��� ������ (��Ʈ ~ �� �������� ���� �����)�뷱�� ���� ����
	b = balance_factor(n); // �뷱�� ���� ���ϱ� 
	if (abs(b) > 1) { // �ұ��� ���¶�� ( b < -1 || b > 1 )
		rotate(p, b); // ȸ�� ����
	}
	check_balance(data < n->data ? &n->left : &n->right, data);

}
void rotate(NODE** p, int b_factor) {
	printf("ȸ�� ����! \n");
	NODE* tmp = *p;
	int first = b_factor > 0; // 1 : L, 0 : R
	int second = first ? (balance_factor(tmp->left) > 0) : (balance_factor(tmp->right) > 0);
	// L�̸� left�� �뷱�����͸� Ȯ���ϰ� R�̸� right�� �뷱�����͸� Ȯ���Ѵ�.
	// �̶� ���� ����� 1�̸� L, 0�̸� R
	NODE* median; // �߰���

	// 1) LR (first == 1 && second == 0)
	if (first && !second) {
		printf("LR ����! tmp : %p \n", tmp);
		median = tmp->left;
		tmp->left = median->right;
		tmp->left->left = median;
		median->right = NULL;
		second = 1; // LL �� ����Ǿ����� ǥ�� (�ٷ� ���� LL ȸ���� ���� �ǵ���)
	}
	// 2) LL (first == 1 && second == 1)
	if (first && second) {
		printf("LL ����! tmp : %p \n", tmp);
		median = tmp->left;
		tmp->left = median->right;
		median->right = tmp;
		*p = median;
	}

	// 3) RL
	if (!first && second) {
		printf("RL ����! tmp : %p \n", tmp);
		median = tmp->right;
		tmp->right = median->left;
		tmp->right->right = median;
		median->left = NULL;
		second = 0;
	}
	// 4) RR
	if (!first && !second) {
		printf("RR ����! tmp : %p \n", tmp);
		median = tmp->right;
		tmp->right = median->left;
		median->left = tmp;
		*p = median;
	}
}


void preorder(NODE* tmp) { // ���� ��ȸ
	if (!tmp) {
		return;
	}
	printf("%d, ", tmp->data); // N ��� Ȯ��
	printf("���� : %d \n", height(tmp)); // ����� ���� //////////////////////
	printf("�뷱�� ���� : %d \n", balance_factor(tmp)); //////////////////////
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
