//==============================
// hw08-graphTraversal.c
// 알고리즘 과제 8.그래프 순회
// 한국외국어대학교 김한용
//==============================

#include <stdio.h>
#define  MAX_VERTICES  26
#include <stdlib.h>
typedef struct _Graph {
	int nVertices;      // 정점의 개수
	int nEdges;         // 간선의 개수
	int vertex[MAX_VERTICES];
	// 그래프에 존재하는 vertex를 구분
	// ex) vertex[0] = 1 --> 정점 A 있음
	//     vertex[1] = 1 --> 정점 B 있음
	//     vertex[4] = 0 --> 정점 E 없음
	int edge[MAX_VERTICES][MAX_VERTICES];
	// 그래프에 존재하는 edge의 weight 값
	// ex) edge[0][1] = 4  --> 간선 <A, B>의 weight는 4
	//     edge[1][3] = 13 --> 간선 <B, D>의 weight는 13
	//     edge[2][1] = 0  --> 정점 C에서 B로 향하는 간선 없음
} Graph;

// 그래프 초기화
void initGraph(Graph *g){

	g->nVertices = 0;
	g->nEdges = 0;

	for (int i = 0; i < MAX_VERTICES; i++) {
		g->vertex[i] = 0;
		for (int j = 0; j < MAX_VERTICES; j++)
			g->edge[i][j] = 0;
	}
}
// 정점 삽입
int insertVertex(Graph* g, char v){
	
	int for_char_index = v - 'A';
	
	// 정점의 개수가 27 이상이면 프로그램 종료
	if ((g->nVertices) + 1 > MAX_VERTICES) {
		printf("Vertex 초과\n");
		exit(0);
	}
	 //존재하는 정점을 입력하면 프로그램 종료
	for (int i = 0; i < g->nVertices; i++) {
		if ((g->vertex[for_char_index])) {
			printf("%c Vertex는 이미 존재합니다\n", v);
			exit(0);
		}
	}

	g->nVertices++;
	g->vertex[for_char_index] = 1;

	return -1; // SUCCESS
}

// 간선 삽입
int insertEdge(Graph *g, char v1, char v2, int weight){

	int for_char_index_v1 = v1 - 'A';
	int for_char_index_v2 = v2 - 'A';
	
	//가중치 예외 처리
	if (weight < 0) {
		printf("음수 가중치가 입력됐습니다.\n", v1, v2);
		exit(0);
	}
	//정점이 모두 존재하면 양방향을 연결
	if ((g->vertex[for_char_index_v1]) && (g->vertex[for_char_index_v2])) {
		g->edge[for_char_index_v1][for_char_index_v2] = weight;
		g->edge[for_char_index_v2][for_char_index_v1] = weight;
	}
	else {
		printf("존재하지 않는 Vertex를 연결\n");
		exit(0);
	}
	return -1; // SUCCESS
}

// 그래프 출력 
void printGraph(Graph *g)
{

	int for_print_last = 0;
	int num_edge = 0;
	int count = 0;
	int self_edge = 0;
	// 정점 출력
	// 출력 형식을 위해 매 출력마다 vertex 개수와 for_print_last를 비교
	printf("V(G) = {");
	for (int i = 0; i < MAX_VERTICES; i++) {
		if (g->vertex[i]) {
			printf(" %c", 'A' + i);
			for_print_last++;
			if (g->nVertices > for_print_last) {
				printf(",");
			}
			else 
			    printf("");
		}
	}printf(" }\n");
	// 간선 출력
	// 출력 양식을 위해 우선 간선의 개수를 카운트한다
	printf("E(G) = {");
	for (int i = 0; i < MAX_VERTICES; i++) {
		for (int j = 0; j < MAX_VERTICES; j++) {
			if ((g->edge[i][j])) {
				
				if (i != j)
					num_edge++;
				
				else if (i == j)
					self_edge++;
			}
		}
	}
	// 무방향 그래프이므로 대각선 우측 상단과 자신에게 연결된 간선만 카운트 한다
	num_edge = (num_edge / 2) + self_edge;
	// 본격적인 간선 출력 양식
	for ( int i = 0; i < MAX_VERTICES; i++) {
		for ( int j = 0; j < MAX_VERTICES; j++) {
			if ((g->edge[i][j])) {
				if (i <= j) {
					count++;
					printf(" (%c,%c)", 'A' + i, 'A' + j);
					if (count < num_edge) {
						printf(",");
					}
					else {
						printf(" }\n");
					}
				}
			}
		}
	}
}


// 방문 이력 관리
int visited[MAX_VERTICES];

// stack 자료구조
int stack[MAX_VERTICES];
int top;

#define   INIT_STACK()   { top = -1; }
#define   IS_EMPTY()      (top == -1)
#define   PUSH(v)         { stack[++top] = v; }
#define   POP()         (stack[top--])

// queue 자료구조
int queue[MAX_VERTICES];
int front, rear;

#define   INIT_QUEUE()   { front = rear = -1; }
#define   ENQUEUE(v)      { queue[++front] = v; }
#define   DEQUEUE()      ((front > rear) ? queue[++rear] : -1)

// 깊이 우선 탐색(DFS: depth first search)
void depthFirstSearch(Graph * g, int v){

	printf("Depth First Search   :");
	// 모든 방문 -> false
	for (int i = 0; i < MAX_VERTICES; i++) 
		visited[i] = 0; 
	
	PUSH(v);
	while (!(IS_EMPTY())) {
		v = POP();
		if (!visited[v]) {
			visited[v] = 1;  // 방문 -> true
			printf(" %c", v + 'A');
			for (int i = MAX_VERTICES - 1; i >= 0; i--) {
				if ((g->edge[v][i] == 1) && (visited[i] == 0)) 
					PUSH(i);
			}
		}
	}
	INIT_STACK();
}

// 너비 우선 탐색(BFS: breadth first search) 
void breadthFirstSearch(Graph * g, int v){

	printf("\nBreadth First Search :");
	printf(" %c", 'A' + v);
	for (int i = 0; i < MAX_VERTICES; i++) 
		visited[i] = 0;
	
	visited[v] = 1;
	ENQUEUE(v);

	while (front != rear) {
		v = DEQUEUE();
		for (int i = 0; i < MAX_VERTICES; i++) {
			if (!visited[i] && (g->edge[v][i])) {
				ENQUEUE(i);
				visited[i] = 1;
				printf(" %c", 'A' + i);
			}
		}
	}
	printf("\n");
	
	INIT_QUEUE();
}

void main()
{
	Graph  G;

	printf("배열로 그래프 구현 201300960 김한용\n\n");

	initGraph(&G);

	insertVertex(&G, 'A');
	insertVertex(&G, 'C');
	insertVertex(&G, 'D');
	insertVertex(&G, 'F');
	insertVertex(&G, 'I');
	insertVertex(&G, 'J');
	insertVertex(&G, 'Z');
	insertVertex(&G, 'Y');

	insertEdge(&G, 'A', 'C', 1);
	insertEdge(&G, 'A', 'F', 1);
	insertEdge(&G, 'A', 'Y', 1);
	insertEdge(&G, 'D', 'J', 1);
	insertEdge(&G, 'D', 'Z', 1);
	insertEdge(&G, 'I', 'Z', 1);
	insertEdge(&G, 'C', 'D', 1);
	insertEdge(&G, 'F', 'D', 1);


	printGraph(&G);
	depthFirstSearch(&G, 0);
	breadthFirstSearch(&G, 0);
	

}

/*insertVertex(&G, 'I');
insertVertex(&G, 'J');
insertVertex(&G, 'K');
insertVertex(&G, 'L');
insertVertex(&G, 'M');
insertVertex(&G, 'N');
insertVertex(&G, 'O');
insertVertex(&G, 'P');
insertVertex(&G, 'Q');
insertVertex(&G, 'R');
insertVertex(&G, 'S');
insertVertex(&G, 'T');*/
// DFS - A B D G E C F
// BFS - A B C D E G F
