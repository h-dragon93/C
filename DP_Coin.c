// 201300960 김한용
#include <stdio.h>
#include <limits.h>

void main() {
	int coin_number; // 동전 종류
	int coin_type[101]; // 동전의 액면가
	int n; //거스름돈 액수
	int C[101]; // DP 저장

	//Prompt
	printf("Coin Change Dynamic-Programming 201300960 김한용\n\n");

	//동전 종류 입력
	printf("동전의 종류: ");
	scanf("%d", &coin_number);

	//동전 액면가 입력
	printf("동전의 액면가(내림차순): ");
	for (int i = 1; i <= coin_number; i++) {
		scanf("%d", &coin_type[i]);
	}

	//거스름돈 액수 입력
	printf("거스름돈 액수: ");
	scanf("%d", &n);
	printf("\n");

	// DP를 위한 무한대값 설정(초기화)
	for (int i = 1; i <= n; i++) {
		C[i] = INT_MAX;
	}C[0] = 0;

	//DP 알고리즘 실행
	for (int j = 1; j <= n; j++) {
		for (int i = 1; i <= coin_number; i++)
			if ((coin_type[i] <= j) && (C[j - coin_type[i]] + 1 < C[j]))
				C[j] = C[j - coin_type[i]] + 1;
	}

	//출력 양식(0~20, 21~40, 41~60, 61~80, 81~100)
	printf("j = ");
	for (int i = 1; i <= n; i++) {
		printf("%4d", i);
		if (i == n) {
			printf("\nC = ");
			break;
		}
		if (i == 20) {
			printf("\nC = ");
			break;
		}
	}
	for (int j = 1; j <= n; j++) {
		printf("%4d", C[j]);
		if (j == 20) {
			break;
		}
	}
	for (int i = 21; i <= n; i++) {
		if (i == 21) {
			printf("\n\nj = ");
		}
		printf("%4d", i);
		if (i == n) {
			printf("\nC = ");
			break;
		}
		if (i % 20 == 0) {
			printf("\nC = ");
			break;
		}
	}
	for (int j = 21; j <= n; j++) {
		printf("%4d", C[j]);
		if (j % 20 == 0) {
			break;
		}
	}
	for (int i = 41; i <= n; i++) {
		if (i == 41) {
			printf("\n\nj = ");
		}
		printf("%4d", i);
		if (i == n) {
			printf("\nC = ");
			break;
		}
		if (i % 20 == 0) {
			printf("\nC = ");
			break;
		}
	}
	for (int j = 41; j <= n; j++) {
		printf("%4d", C[j]);
		if (j % 20 == 0) {
			break;
		}
	}
	for (int i = 61; i <= n; i++) {
		if (i == 61) {
			printf("\n\nj = ");
		}
		printf("%4d", i);
		if (i == n) {
			printf("\nC = ");
			break;
		}
		if (i % 20 == 0) {
			printf("\nC = ");
			break;
			}
	}
	for (int j = 61; j <= n; j++) {
		printf("%4d", C[j]);
		if (j % 20 == 0) {
			break;
		}
	}
	for (int i = 81; i <= n; i++) {
		if (i == 81) {
			printf("\n\nj = ");
		}
		printf("%4d", i);
		if (i == n) {
			printf("\nC = ");
			break;
		}
	}
	for (int j = 81; j <= n; j++) {
		printf("%4d", C[j]);
	}printf("\n"); printf("\n");

	//거스름돈 동전의 최소 개수 출력
	printf("거스름돈 동전의 최소 개수 = %d \n\n", C[n]);

}
