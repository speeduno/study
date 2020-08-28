#include <stdio.h>

#define MAX 8

int arr[MAX] = { 0 };
int head = -1;
int tail = -1;

// 데이터 추가 
void enqueue(int data) {

	// head가 tail 보다 1칸 앞서니? (데이터가 꽉 찼니?)
	if (head == (tail + 1) % MAX) {
		printf("데이터가 꽉 찼습니다.(overflow) \n");
		return;
	}

	// 최초 데이터 저장이니?
	if (head == -1 && tail == -1) {
		head = tail = 0;
	}

	// 아니면 tail만 1 증가
	else {
		tail = (tail + 1) % MAX;
	}

	// 데이터 추가 
	arr[tail] = data;
}

// 데이터 삭제 
void dequeue() {

	// 처리할 데이터가 1개도 없다면?
	if (head == -1 && tail == -1) {
		printf("처리 할 데이터 없음 (underflow) \n");
		return;
	}

	// 데이터 삭제 
	arr[head] = 0;

	// 마지막 데이터를 처리하는 거니?
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