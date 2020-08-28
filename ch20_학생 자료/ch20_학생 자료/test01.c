#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAX 9


typedef struct node {
	char vertex;
	struct node* edge_arr[MAX];
	int visited;
}NODE;


typedef struct linked_list {
	NODE* data;
	struct linked_list* next;
}LIST;




NODE* init_node(char ch) {
	NODE* tmp = (NODE*)malloc(sizeof(NODE));
	if (tmp == NULL) {
		return;
	}
	memset(tmp, NULL, sizeof(NODE));
	tmp->vertex = ch;
}

void add_edge(NODE* src, NODE* dest) {
	int i = -1;
	while (src->edge_arr[++i]);
	src->edge_arr[i] = dest;
}

void show_edges(NODE* node) {
	int i;
	printf("%c의 간선들은 ", node->vertex);
	
	for (i = 0; node->edge_arr[i] != NULL; ++i) {
		printf("%c ", node->edge_arr[i]->vertex);
	}

	if (i == 0) 
		printf("없습니다. \n");
	else 
		printf("입니다. \n");
}


LIST* init_list(NODE* data) {
	LIST* tmp = (LIST*)malloc(sizeof(LIST));
	memset(tmp, NULL, sizeof(LIST));
	tmp->data = data;
	return tmp;
}



LIST* path_list = NULL;
int search(LIST** top, NODE* src, NODE* dest) {
	int cnt = 0;
	if (!src) {
		return FALSE;
	}
	if (src->visited) {
		return FALSE;
	}
	printf("현재 확인 중인 정점 : %c \n", src->vertex);
	*top = init_list(src);

	if (src->vertex == dest->vertex) {
		printf("찾았습니다! \n");
		LIST* tmp = path_list;
		printf("경로 : ");
		while (tmp) {
			printf("%c ", tmp->data->vertex);
			tmp = tmp->next;
		}
		printf("\n");
		return TRUE;
	}
	
	int i;
	src->visited = TRUE;

	for (i = 0; i < MAX; ++i) {

		NODE* n = src->edge_arr[i];
		if (!n) {
			break;
		}
		if (n->visited) {
			continue;
		}
		search(&(*top)->next, src->edge_arr[i], dest);
		
	}
	src->visited = FALSE;
}


void main() {
	// 보기 편하게 하기 위함
	NODE* a = init_node('A');
	NODE* b = init_node('B');
	NODE* c = init_node('C');
	NODE* d = init_node('D');
	NODE* e = init_node('E');
	NODE* f = init_node('F');
	NODE* g = init_node('G');
	NODE* h = init_node('H');
	NODE* i = init_node('I');

	// 정점은 총 8개
	NODE* v[MAX] = { a, b, c, d, e, f, g, h, i };
	int idx;

	add_edge(a, b);
	add_edge(a, c);

	add_edge(b, c);
	add_edge(b, f);

	add_edge(c, d);
	add_edge(c, e);
	add_edge(c, f);
	add_edge(c, h);

	add_edge(d, a);
	add_edge(d, c);
	add_edge(d, i);

	add_edge(e, f);
	add_edge(e, g);
	add_edge(e, h);

	add_edge(f, e);

	add_edge(i, h);


	for (idx = 0; idx < MAX; ++idx) {
		show_edges(v[idx]);
	}

	printf("------------------A ~ E 찾기 ------------------\n");
	search(&path_list, a, e);
	printf("------------------D ~ H 찾기 ------------------\n");
	search(&path_list, d, h);
}