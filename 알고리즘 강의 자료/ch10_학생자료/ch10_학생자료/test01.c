#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define NONBLOCKED 0	// �ո� ��
#define BLOCKED 1		// ��
#define PATH 2			// �´� ��
#define VISITED 3		// �湮��

#define WIDTH 8			// �̷��� �ʺ�
#define HEIGHT 8		// �̷��� ����


int maze[WIDTH][HEIGHT] = {
	0, 0, 0, 1, 1, 0, 1, 0,
	1, 1, 0, 0, 0, 0, 1, 0,
	0, 1, 0, 1, 1, 0, 0, 0,
	0, 0, 0, 0, 0, 1, 1, 1,
	1, 1, 0, 1, 0, 1, 0, 0,
	0, 0, 0, 1, 1, 1, 1, 0,
	0, 1, 0, 0, 0, 0, 0, 0,
	0, 1, 1, 1, 0, 1, 1, 0
};

int visited[WIDTH][HEIGHT] = { 0, };

const int ENTRY_ROW = 0;
const int ENTRY_COL = 7;

const int GOAL_ROW = 2;
const int GOAL_COL = 0;

void trace() {
	int i, j;
	int tmp_map[WIDTH][HEIGHT] = { 0 };

	for (i = 0; i < HEIGHT; ++i) {
		for (j = 0; j < WIDTH; ++j) {
			if (maze[i][j] == BLOCKED) {
				printf("��");
			}
			else if (maze[i][j] == PATH) {
				printf("��");
			}
			else {
				printf("��");
			}
		}
		printf("\n");
	}
}

// �������� ����� �����ߴٸ� --> TRUE (1)
// ���� �������� �ƴ� ĭ�̶�� --> FALSE (0)
int push(int r, int c) {
	
	// �̹� �湮�ߴ� ĭ�̴�?
	if (visited[r][c] == VISITED) {
		return FALSE;
	}

	// �湮������ ǥ��
	visited[r][c] = VISITED;
	
	// ���̴�?
	if (maze[r][c] == BLOCKED) {
		return FALSE;
	}



	int tmp = maze[r][c];  // ���� ĭ�� ���� ������ ����
	maze[r][c] = PATH; // �ϴ� '���'���� ǥ��

	// �������� �����ߴ�?
	if (r == GOAL_ROW && c == GOAL_COL) {
		return TRUE;
	}


	// ���� ĭ����  push() �����(���ȣ��)
	if (c > 0 && push(r, c - 1)) {
		return TRUE;
	}
	// ���� ĭ����  push() �����(���ȣ��)
	if (r > 0 && push(r - 1, c)) {
		return TRUE;
	}
	// ������ ĭ����  push() �����(���ȣ��)
	if (c < WIDTH-1 && push(r, c + 1)) {
		return TRUE;
	}
	// �Ʒ��� ĭ����  push() �����(���ȣ��)
	if (r < HEIGHT-1 && push(r + 1, c)) {
		return TRUE;
	}

	maze[r][c] = tmp;

	return FALSE;
}

void main() {
	push(ENTRY_ROW, ENTRY_COL);
	trace();
}