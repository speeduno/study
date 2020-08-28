#include <stdio.h>

#define MAX 8

int arr[MAX] = { 0 };
int head = -1;
int tail = -1;

// ������ �߰� 
void enqueue(int data) {

	// head�� tail ���� 1ĭ �ռ���? (�����Ͱ� �� á��?)
	if (head == (tail + 1) % MAX) {
		printf("�����Ͱ� �� á���ϴ�.(overflow) \n");
		return;
	}

	// ���� ������ �����̴�?
	if (head == -1 && tail == -1) {
		head = tail = 0;
	}

	// �ƴϸ� tail�� 1 ����
	else {
		tail = (tail + 1) % MAX;
	}

	// ������ �߰� 
	arr[tail] = data;
}

// ������ ���� 
void dequeue() {

	// ó���� �����Ͱ� 1���� ���ٸ�?
	if (head == -1 && tail == -1) {
		printf("ó�� �� ������ ���� (underflow) \n");
		return;
	}

	// ������ ���� 
	arr[head] = 0;

	// ������ �����͸� ó���ϴ� �Ŵ�?
	if (head == tail) {
		head = tail = -1;
	}
	else {
		head = (head + 1) % MAX;
	}
	
}

void peek_queue() {
	int i;
	printf("head : %d   tail : %d \n", head, tail);
	for (i = 0; i < MAX; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void main() {
	peek_queue();

	dequeue();
	peek_queue();

	enqueue(10);
	peek_queue();

	enqueue(20);
	peek_queue();

	enqueue(30);
	peek_queue();

	enqueue(40);
	peek_queue();

	enqueue(50);
	peek_queue();

	enqueue(60);
	peek_queue();

	enqueue(70);
	peek_queue();

	enqueue(80);
	peek_queue();
	
	enqueue(90);
	peek_queue();

	dequeue();
	peek_queue();

	enqueue(100);
	peek_queue();

	dequeue();
	peek_queue();

	dequeue();
	peek_queue();

	enqueue(110);
	peek_queue();

	enqueue(120);
	peek_queue();
}