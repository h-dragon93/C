// 201300960 김한용
#include <stdio.h>

int main(int argc, char argv[]) {
	
	int coin_type[10] = { 0, }; // 동전의 종류
	int coin_count[10] = { 0, }; // 동전 종류별 사용 횟수
	int coin_number; // 동전의 개수
	int change;  // 거스름돈
	int coin_count_sum=0; // 전체 동전의 개수

	printf("Coin Change Greedy 201300960 김한용\n");
	// 동전 종류 개수 입력
	printf("동전의 종류(최대 10): ");
	scanf("%d", &coin_number);
	// 동전 액면가 입력
	printf("동전의 액면가(내림차순): ");
	for (int i = 0; i < coin_number; i++) {
			scanf(" %d", &coin_type[i]);
	}
	// 거스름돈 입력
	printf("거스름돈 액수: ");
	scanf("%d", &change);
	// 그리디 알고리즘으로 거스름돈 계산하고 거스름돈 출력
	for (int j = 0; j <coin_number; j++) {

		while (change >= coin_type[j]) {
			change -= coin_type[j];
			coin_count[j]++;

			printf("  (%d)", coin_type[j]);
		}
	}printf("\n");
	// 동전의 개수 출력
	printf("거스름 동전의 개수 = ");
	for (int k = 0; k < coin_number; k++) {
		coin_count_sum += coin_count[k];
	}
	printf("%d \n", coin_count_sum);
	
	return 0;
}
