//==============================
// hw09-최단거리 탐색
// 알고리즘 과제 9.다익스트라 Shortest Path
// 한국외국어대학교 융복합 소프트웨어 전공 201300960 김한용
//==============================

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define  MAX_VERTICES 26
#define Loop 32767

int D[MAX_VERTICES]; // 최단 거리 파악 배열
int D_visit_check[MAX_VERTICES]; // 방문 여부 체크 배열

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
void initGraph(Graph *g) {

	g->nVertices = 0;
	g->nEdges = 0;

	for (int i = 0; i < MAX_VERTICES; i++) {
		g->vertex[i] = 0;
		for (int j = 0; j < MAX_VERTICES; j++)
			g->edge[i][j] = 0;
	}
}
// 정점 삽입
int insertVertex(Graph* g, char v) {

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
int insertEdge(Graph *g, char v1, char v2, int weight) {

	int for_char_index_v1 = v1 - 'A';
	int for_char_index_v2 = v2 - 'A';

	//가중치 예외 처리
	if (weight < 0) {
		printf("음수 가중치가 입력됐습니다.\n");
		exit(0);
	}
	//정점이 모두 존재하면 양방향을 연결
	if ((g->vertex[for_char_index_v1]) && (g->vertex[for_char_index_v2])) {
		g->edge[for_char_index_v1][for_char_index_v2] = weight;
		g->edge[for_char_index_v2][for_char_index_v1] = weight;
		g->nEdges++; //이번 과제는 가중치를 더해야 하기 때문에 추가
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
	// 무방향 그래프이므로 대각선 우측 상단과 자신에게 연결된 간선만 카운트.
	num_edge = (num_edge / 2) + self_edge;
	// 본격적인 간선 출력 양식
	for (int i = 0; i < MAX_VERTICES; i++) {
		for (int j = 0; j < MAX_VERTICES; j++) {
			if ((g->edge[i][j]) && g->edge[i][j] != Loop) {
				if (i <= j) {
					count++;
					printf(" (%c,%c)", 'A' + i, 'A' + j);
					if (count < num_edge ) {
						printf(",");
					}
					
				}
			}
		}
	}printf(" }\n");
}

// D 배열에서 최단 거리 정보를 알고 있는 노드들중 
// 가장 거리가 짧은 노드의 인덱스를 return하는 함수
int minDistance(int D[], int D_visited[]) {
	
	int min = INT_MAX;
	int min_idx = -1;
	D[0] = 0;

	for (int i = 0; i < MAX_VERTICES; i++) {
		if (D_visited[i] == 0 && D[i] < min ) {
			min = D[i];
			min_idx = i;
		}
	}
	return min_idx;
}
// 과제의 핵심 요구사항인 다익스트라 최단거리 알고리즘 함수
void ShortestPath(Graph *g, int s){

	int min_idx;

	// 방문 상태와 edge 가중치 초기화
	for (int i = 0; i < MAX_VERTICES; i++) {

		D[i] = g->edge[s][i];
		D_visit_check[i] = 0;
	}
	// 초기화 완료 후 정점 방문 
	D_visit_check[s] = 1;
	D[s] = 1;

	// MAX_VERTICES - 1번 루프를 수행함으로써 s 노드를 제외한 모든 노드를 계산
	// min dix는 최소값의 인덱스를 minDistance로 부터 return 받아 저장.
	for (int i = 0; i < MAX_VERTICES - 1; i++){
		
		min_idx = minDistance(D, D_visit_check);
		// 최소값 인덱스 위치의 배열은 방문 체크. 
		D_visit_check[min_idx] = 1;
		// 그래프 상의 모든 노드를 탐색하며 주변 노드의 정보를 갱신.
		// 아직 처리가 되지 않은 노드이면서 (무한 루프에 빠질 수 있기 때문)
		//  (D[idx]) + 정점 w의 거리가 기존의 거리보다 짧다면 그 정보를 갱신 
		for (int k = 0; k < MAX_VERTICES; k++){	

			if (D_visit_check[k] == 0){
				if (g->edge[min_idx][k] != 0 && (D[min_idx] + g->edge[min_idx][k] < D[k])) {
					D[k] = D[min_idx] + g->edge[min_idx][k];
				}
			}
		}
	}

	// 시작점에서 그 정점까지의 최단 거리 출력
	printf("\n\n");
	for (int i = 0; i<MAX_VERTICES; i++) {
		if (D[i] != Loop)
			printf("D[%c] = %d\n", i + 65, D[i]); //아스키 코드 사용
	}
}
// 배열 D를 ∞로 초기화 시키는 함수. i==j인 경우는 0으로 확정.
void graph_array_Loop_init(Graph *g) {

	for (int i = 0; i<MAX_VERTICES; i++) {
		for (int j = 0; j<MAX_VERTICES; j++) {
			if (i == j) {
				g->edge[i][j] = 0;
			}
			else {
				g->edge[i][j] = Loop;
			}
		}
	}
}

void main()
{
	Graph  G;

	printf("최단거리 탐색 201300960 김한용\n\n");

	initGraph(&G);
	graph_array_Loop_init(&G);

	//테스트 케이스 1 과제 안내에 수록된 예시로 테스트
	insertVertex(&G, 'A');
	insertVertex(&G, 'B');
	insertVertex(&G, 'C');
	insertVertex(&G, 'D');
	insertVertex(&G, 'E');
	insertVertex(&G, 'F');
	insertVertex(&G, 'G');
	insertVertex(&G, 'H');
	insertVertex(&G, 'I');
	insertVertex(&G, 'J');

	insertEdge(&G, 'A', 'B', 15);
	insertEdge(&G, 'A', 'D', 12);
	insertEdge(&G, 'B', 'C', 21);
	insertEdge(&G, 'B', 'G', 7);
	insertEdge(&G, 'C', 'H', 25);
	insertEdge(&G, 'D', 'E', 4);
	insertEdge(&G, 'D', 'F', 10);
	insertEdge(&G, 'E', 'F', 3);
	insertEdge(&G, 'E', 'I', 13);
	insertEdge(&G, 'F', 'G', 10);
	insertEdge(&G, 'G', 'H', 19);
	insertEdge(&G, 'G', 'J', 9);
	insertEdge(&G, 'H', 'J', 6);
	insertEdge(&G, 'I', 'J', 15);
	/*
	출력 결과가 과제 안내에 수록된 결과와 일치
	D[A] = 0
	D[B] = 15
	D[C] = 36
	D[D] = 12
	D[E] = 16
	D[F] = 19
	D[G] = 22
	D[H] = 37
	D[I] = 29
	D[J] = 31
	*/

	/*
	테스트 케이스2 강의노트 Kruskal 알고리즘의 예2 그래프로 테스트

	insertVertex(&G, 'A');
	insertVertex(&G, 'B');
	insertVertex(&G, 'C');
	insertVertex(&G, 'D');
	insertVertex(&G, 'E');
	insertVertex(&G, 'F');
	insertVertex(&G, 'G');
	insertVertex(&G, 'H');
	insertVertex(&G, 'I');
	
	insertEdge(&G, 'A', 'B', 4);
	insertEdge(&G, 'A', 'H', 8);
	insertEdge(&G, 'B', 'C', 8);
	insertEdge(&G, 'B', 'H', 11);
	insertEdge(&G, 'C', 'D', 7);
	insertEdge(&G, 'C', 'I', 2);
	insertEdge(&G, 'C', 'F', 4);
	insertEdge(&G, 'D', 'F', 14);
	insertEdge(&G, 'D', 'E', 9);
	insertEdge(&G, 'F', 'E', 10);
	insertEdge(&G, 'G', 'H', 1);
	insertEdge(&G, 'G', 'F', 2);
	insertEdge(&G, 'G', 'I', 6);
	insertEdge(&G, 'H', 'I', 7);	

	출력 결과값
	D[A] = 0
	D[B] = 4
	D[C] = 12
	D[D] = 19
	D[E] = 21
	D[F] = 11
	D[G] = 9
	D[H] = 8
	D[I] = 14
	*/

	/*
	테스트 케이스 3 강의 노트에 제시된 그래프의 가중치를 변경하여 테스트
	insertVertex(&G, 'A');
	insertVertex(&G, 'B');
	insertVertex(&G, 'C');
	insertVertex(&G, 'D');
	insertVertex(&G, 'E');
	insertVertex(&G, 'F');
	insertVertex(&G, 'G');
	insertVertex(&G, 'H');
	insertVertex(&G, 'I');

	insertEdge(&G, 'A', 'B', 3);
	insertEdge(&G, 'A', 'H', 4);
	insertEdge(&G, 'B', 'C', 8);
	insertEdge(&G, 'B', 'H', 1);
	insertEdge(&G, 'C', 'D', 7);
	insertEdge(&G, 'C', 'I', 6);
	insertEdge(&G, 'C', 'F', 9);
	insertEdge(&G, 'D', 'F', 15);
	insertEdge(&G, 'D', 'E', 7);
	insertEdge(&G, 'F', 'E', 8);
	insertEdge(&G, 'G', 'H', 9);
	insertEdge(&G, 'G', 'F', 12);
	insertEdge(&G, 'G', 'I', 4);
	insertEdge(&G, 'H', 'I', 8);

	D[A] = 0
	D[B] = 3
	D[C] = 11
	D[D] = 18
	D[E] = 25
	D[F] = 20
	D[G] = 13
	D[H] = 4
	D[I] = 12
	*/

	printGraph(&G);
	ShortestPath(&G, 0);

}
