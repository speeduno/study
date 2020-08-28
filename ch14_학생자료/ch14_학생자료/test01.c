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

	// 첫 노드 추가라면
	if (head == NULL && tail == NULL) {	
		head = tail = tmp;
		return TRUE;
	}

	// 그렇지 않으면. tail에 새 노드를 등록
	// 1. 현재 tail을 새 노드의 prev에 저장
	tmp->prev = tail;
	
	// 2. 현재 tail의 next에 새 노드 저장
	tail->next = tmp;

	// 2. tail에 새 노드 등록
	tail = tmp;
	return TRUE;
}
void peek() {
	NODE* tmp = head;
	printf("순방향 : ");
	while (tmp) {
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}
void reverse_peek() {
	NODE* tmp = tail;
	printf("역방향 : ");
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
		if (tmp->data == data) { // 삭제할 노드를 찾으면
			flag = TRUE;
			target = tmp;

			if (!target->prev) { // 삭제할 노드가 가장 첫 노드인 경우
				head = target->next;
			}
			else {// 그렇지 않으면 삭제할 노드의 prev와 next를 연결
				target->prev->next = target->next;
			}

			if (!target->next) { // 삭제할 노드가 가장 마지막 노드인 경우
				tail = target->prev;
			}
			else { // 그렇지 않으면 삭제할 노드의 next와 prev를 연결
				target->next->prev = target->prev;
			}

			free(target); // 삭제 실행
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

	// 최초 노드거나 맨 마지막에 삽입하는 경우
	if (tmp == NULL) {
		add(data); // 일반 add와 동일한 로직을 적용
		return TRUE;
	}

	node = init(data);

	// 맨 앞 
	if (tmp == head) {
		head = node;
		node->next = tmp;
		tmp->prev = node;
	}
	
	// 중간
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
		printf("1. 노드 추가 \n");
		printf("2. 노드 검색 \n");
		printf("3. 노드 삭제 \n");
		printf("4. 노드 삽입 \n");
		printf("5. 종료 \n");
		printf("입력 : "); 
		scanf_s("%d", &select);
		switch (select) {
		case 1: // 노드 추가
			printf("추가할 데이터 :");
			scanf_s("%d", &data);
			printf("%s\n", add(data) ? "추가 완료!" : "추가 실패!");
			break;
		case 2: // 노드 검색
			printf("검색할 데이터 :");
			scanf_s("%d", &data);
			index = search(data);
			if (index)
				printf("%d(은)는 %d번에 있습니다.\n", data, index);
			else
				printf("미등록 노드 \n");
			break;
		case 3: // 노드 삭제
			printf("삭제할 데이터 :");
			scanf_s("%d", &data);
			printf("%s\n", remove(data) ? "삭제 완료!" : "삭제 실패!");
			break;
		case 4: // 노드 삽입
			printf("새 데이터 :");
			scanf_s("%d", &data);
			printf("삽입할 위치 : ");
			scanf_s("%d", &index);
			printf("%s\n", insert(data, index) ? "삽입 완료!" : "삽입 실패!");
			break;
		case 5:
			printf("프로그램을 종료합니다. \n");
			exit(0);
		default:
			printf("잘못된 입력입니다. \n");
		}

		system("pause");
		system("cls");
	}
}