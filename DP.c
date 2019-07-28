// 201300960 김한용
#include <stdio.h>
#include <limits.h>

int main(int argc, char argv[]) {
	
	int matrice_num; // 입력 받을 행렬의 수
	int matrice_type[100000] = { 0, }; // 입력 받을 행렬 초기화
	int C[100][100] = { 0, }; // DP 알고리즘이 적용될 2차원 행렬 초기화
	int j, temp;

	// 프롬프트 출력
	printf("Chained Matrix Multiplications 201300960 김한용\n\n");

	// 행렬 수 입력
	printf("# of Matrices : ");
	scanf(" %d", &matrice_num);
	printf("Enter ");

	// 출력 양식
	for (int i = 0; i <= 1; i++) {
		printf("d%d ", i);
	} printf(" ... ");
	for (int i = matrice_num; i <= matrice_num; i++) {
		printf("d%d ", i);
	} printf(": ");

	// 행렬 입력 받기
	for (int i = 0; i <= matrice_num; i++) {
		scanf("%d", &matrice_type[i]);
	}printf("\n");

	// 입력받은 행렬 출력, Problem is
	printf("Problem is ");
	for (int i = 0; i < matrice_num; i++) {
		printf("[%d:%d]", matrice_type[i], matrice_type[i + 1]);
		if (i < matrice_num - 1)
			printf("x");
	}printf("\n"); printf("\n");

	// DP 알고리즘 적용
	for (int L = 1; L < matrice_num + 1; L++) {
		for (int i = 1; i <= matrice_num + 1 - L; i++) {
			j = i + L;
			C[i][j] = INT_MAX; // integer 변수의 최대값
			for (int k = i; k <= j - 1; k++) {
				temp = C[i][k] + matrice_type[i - 1] * matrice_type[k] * matrice_type[j] + C[k + 1][j];
				//printf("%d\n", temp);
				if (temp < C[i][j])
					C[i][j] = temp;
			}
		}
	}

	// DP 출력 양식에 맞게 결과 출력
	printf("   C    ");
	for (int i = 1; i < matrice_num + 1; i++) {
		printf("  [ %d ]  ", i);
	}printf("\n");

	for (int i = 1; i < matrice_num + 1; i++) {
		printf(" [ %d ]", i);
		for (int j = 1; j < matrice_num + 1; j++) {
			printf("  %7d", C[i][j]);
		}
		printf("\n");
	}printf("\n");

	// 최적해 출력
	printf("Final soultion is %d", C[1][matrice_num]);
	printf("\n"); printf("\n");

	return 0;
}
