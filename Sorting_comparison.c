//201300960 김한용
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertValue(int* arr, int size);
void swap(int* a, int* b);
void shuffleArray(int* arr, int ArraySize);
void printArray(int * arr, int size);
void swap_selec(int* a, int* b);
void selectionSort(int* arr, int size);
void swap_bubble(int* a, int* b);
void bubbleSort(int* arr, int size);
void insertSort(int* arr, int size);
void insertSort2(int* arr, int first, int last, int h);
void shellSort(int* arr, int size);
void mergeSort(int arr[], int p, int r);
void QuickSort(int* arr, int left, int right);
int compare_selec = 0, move_selec = 0;
int compare_bubble = 0,move_bubble = 0;
int compare_insert = 0,move_insert = 0;
int compare_shell = 0,move_shell = 0;
int compare_merge = 0,move_merge = 0;
int compare_quick = 0,move_quick = 0;

#define ArraySize 1000
#define ArraySize_merge 10000

void main(){
	// 배열 정의 및 초기화
	int arr1[1000] = {0, };          
	int arr2[2000] = { 0, };
	int arr3[3000] = { 0, };
	int arr4[4000] = { 0, };
	int arr5[5000] = { 0, };
	int arr6[6000] = { 0, };
	int arr7[7000] = { 0, };
	int arr8[8000] = { 0, };
	int arr9[9000] = { 0, };
	int arr10[10000] = { 0, };
	
	insertValue(arr1, 1000);           // 배열에 값 삽입
	srand((unsigned int)time(NULL));   // 랜덤값 고정을 위한 Seed 설정
	shuffleArray(arr1, 1000);          // 배열 섞기

	insertValue(arr2, 2000);           
	srand((unsigned int)time(NULL));   
	shuffleArray(arr2, 2000);  

	insertValue(arr3, 3000);
	srand((unsigned int)time(NULL));
	shuffleArray(arr3, 3000);

	insertValue(arr4, 4000);
	srand((unsigned int)time(NULL));
	shuffleArray(arr4, 4000);

	insertValue(arr5, 5000);
	srand((unsigned int)time(NULL));
	shuffleArray(arr5, 5000);

	insertValue(arr6, 6000);
	srand((unsigned int)time(NULL));
	shuffleArray(arr6, 6000);

	insertValue(arr7, 7000);
	srand((unsigned int)time(NULL));
	shuffleArray(arr7, 7000);

	insertValue(arr8, 8000);
	srand((unsigned int)time(NULL));
	shuffleArray(arr8, 8000);

	insertValue(arr9, 9000);
	srand((unsigned int)time(NULL));
	shuffleArray(arr9, 9000);

	insertValue(arr10, 10000);
	srand((unsigned int)time(NULL));
	shuffleArray(arr10,10000);
    //////// 여기까지 랜덤값이 삽입된 배열 생성 완료
	///////Selection Sort 시작////////
	printf("Selection Sort \n");
	
	selectionSort(arr1, ArraySize);
	printf("  size=%d compare=%d move=%d \n", ArraySize, compare_selec, move_selec);
	compare_selec = 0, move_selec = 0;

	selectionSort(arr2, ArraySize*2);
	printf("  size=%d compare=%d move=%d \n", ArraySize*2, compare_selec, move_selec);
	compare_selec = 0, move_selec = 0;
	
	selectionSort(arr3, ArraySize*3);
	printf("  size=%d compare=%d move=%d \n", ArraySize*3, compare_selec, move_selec);
	compare_selec = 0, move_selec = 0;

	selectionSort(arr4, ArraySize*4);
	printf("  size=%d compare=%d move=%d \n", ArraySize*4, compare_selec, move_selec);
	compare_selec = 0, move_selec = 0;

	selectionSort(arr5, ArraySize * 5);
	printf("  size=%d compare=%d move=%d \n", ArraySize * 5, compare_selec, move_selec);
	compare_selec = 0, move_selec = 0;

	selectionSort(arr6, ArraySize * 6);
	printf("  size=%d compare=%d move=%d \n", ArraySize * 6, compare_selec, move_selec);
	compare_selec = 0, move_selec = 0;

	selectionSort(arr7, ArraySize * 7);
	printf("  size=%d compare=%d move=%d \n", ArraySize * 7, compare_selec, move_selec);
	compare_selec = 0, move_selec = 0;

	selectionSort(arr8, ArraySize * 8);
	printf("  size=%d compare=%d move=%d \n", ArraySize * 8, compare_selec, move_selec);
	compare_selec = 0, move_selec = 0;

	selectionSort(arr9, ArraySize * 9);
	printf("  size=%d compare=%d move=%d \n", ArraySize * 9, compare_selec, move_selec);
	compare_selec = 0, move_selec = 0;

	selectionSort(arr10, ArraySize * 10);
	printf("  size=%d compare=%d move=%d \n", ArraySize * 10, compare_selec, move_selec);
	compare_selec = 0, move_selec = 0;
	
	////정렬된 배열 다시 섞기
	shuffleArray(arr1, ArraySize);
	shuffleArray(arr2, ArraySize * 2);
	shuffleArray(arr3, ArraySize * 3);
	shuffleArray(arr4, ArraySize * 4);
	shuffleArray(arr5, ArraySize * 5);
	shuffleArray(arr6, ArraySize * 6);
	shuffleArray(arr7, ArraySize * 7);
	shuffleArray(arr8, ArraySize * 8);
	shuffleArray(arr9, ArraySize * 9);
	shuffleArray(arr10, ArraySize * 10);

	///////Bubble Sort 시작////////
	printf("\nBubble Sort \n");
	
	bubbleSort(arr1, ArraySize);
	printf("  size=%d compare=%d move=%d \n", ArraySize , compare_bubble, move_bubble);
	compare_bubble = 0, move_bubble = 0;

	bubbleSort(arr2, ArraySize*2);
	printf("  size=%d compare=%d move=%d \n", ArraySize*2, compare_bubble, move_bubble);
	compare_bubble = 0, move_bubble = 0;

	bubbleSort(arr3, ArraySize * 3);
	printf("  size=%d compare=%d move=%d \n", ArraySize * 3, compare_bubble, move_bubble);
	compare_bubble = 0, move_bubble = 0;

	bubbleSort(arr4, ArraySize * 4);
	printf("  size=%d compare=%d move=%d \n", ArraySize * 4, compare_bubble, move_bubble);
	compare_bubble = 0, move_bubble = 0;

	bubbleSort(arr5, ArraySize * 5);
	printf("  size=%d compare=%d move=%d \n", ArraySize * 5, compare_bubble, move_bubble);
	compare_bubble = 0, move_bubble = 0;

	bubbleSort(arr6, ArraySize * 6);
	printf("  size=%d compare=%d move=%d \n", ArraySize * 6, compare_bubble, move_bubble);
	compare_bubble = 0, move_bubble = 0;

	bubbleSort(arr7, ArraySize * 7);
	printf("  size=%d compare=%d move=%d \n", ArraySize * 7, compare_bubble, move_bubble);
	compare_bubble = 0, move_bubble = 0;

	bubbleSort(arr8, ArraySize * 8);
	printf("  size=%d compare=%d move=%d \n", ArraySize * 8, compare_bubble, move_bubble);
	compare_bubble = 0, move_bubble = 0;

	bubbleSort(arr9, ArraySize * 9);
	printf("  size=%d compare=%d move=%d \n", ArraySize * 9, compare_bubble, move_bubble);
	compare_bubble = 0, move_bubble = 0;

	bubbleSort(arr10, ArraySize * 10);
	printf("  size=%d compare=%d move=%d \n", ArraySize * 10, compare_bubble, move_bubble);
	compare_bubble = 0, move_bubble = 0;
	//////정렬된 배열 다시 섞기
	shuffleArray(arr1, ArraySize);
	shuffleArray(arr2, ArraySize * 2);
	shuffleArray(arr3, ArraySize * 3);
	shuffleArray(arr4, ArraySize * 4);
	shuffleArray(arr5, ArraySize * 5);
	shuffleArray(arr6, ArraySize * 6);
	shuffleArray(arr7, ArraySize * 7);
	shuffleArray(arr8, ArraySize * 8);
	shuffleArray(arr9, ArraySize * 9);
	shuffleArray(arr10, ArraySize * 10);
	///////Insertion Sort 시작////////
	printf("\nInsertion Sort \n");

	insertSort(arr1, ArraySize);
	printf("  size=%d compare=%d move=%d \n", ArraySize, compare_insert, move_insert);
	compare_insert = 0, move_insert = 0;

	insertSort(arr2, ArraySize*2);
	printf("  size=%d compare=%d move=%d \n", ArraySize*2, compare_insert, move_insert);
	compare_insert = 0, move_insert = 0;

	insertSort(arr3, ArraySize * 3);
	printf("  size=%d compare=%d move=%d \n", ArraySize * 3, compare_insert, move_insert);
	compare_insert = 0, move_insert = 0;

	insertSort(arr4, ArraySize * 4);
	printf("  size=%d compare=%d move=%d \n", ArraySize * 4, compare_insert, move_insert);
	compare_insert = 0, move_insert = 0;

	insertSort(arr5, ArraySize * 5);
	printf("  size=%d compare=%d move=%d \n", ArraySize * 5, compare_insert, move_insert);
	compare_insert = 0, move_insert = 0;

	insertSort(arr6, ArraySize * 6);
	printf("  size=%d compare=%d move=%d \n", ArraySize * 6, compare_insert, move_insert);
	compare_insert = 0, move_insert = 0;

	insertSort(arr7, ArraySize * 7);
	printf("  size=%d compare=%d move=%d \n", ArraySize * 7, compare_insert, move_insert);
	compare_insert = 0, move_insert = 0;

	insertSort(arr8, ArraySize * 8);
	printf("  size=%d compare=%d move=%d \n", ArraySize * 8, compare_insert, move_insert);
	compare_insert = 0, move_insert = 0;

	insertSort(arr9, ArraySize * 9);
	printf("  size=%d compare=%d move=%d \n", ArraySize * 9, compare_insert, move_insert);
	compare_insert = 0, move_insert = 0;

	insertSort(arr10, ArraySize * 10);
	printf("  size=%d compare=%d move=%d \n", ArraySize * 10, compare_insert, move_insert);
	compare_insert = 0, move_insert = 0;
	///// 정렬된 배열 다시 섞기
	shuffleArray(arr1, ArraySize);
	shuffleArray(arr2, ArraySize * 2);
	shuffleArray(arr3, ArraySize * 3);
	shuffleArray(arr4, ArraySize * 4);
	shuffleArray(arr5, ArraySize * 5);
	shuffleArray(arr6, ArraySize * 6);
	shuffleArray(arr7, ArraySize * 7);
	shuffleArray(arr8, ArraySize * 8);
	shuffleArray(arr9, ArraySize * 9);
	shuffleArray(arr10, ArraySize * 10);
	///////Shell Sort 시작////////
	printf("\nShell Sort \n");

	shellSort(arr1, ArraySize);
	printf("  size=%d compare=%d move=%d \n", ArraySize, compare_shell, move_shell);
	compare_shell = 0, move_shell = 0;

	shellSort(arr2, ArraySize*2);
	printf("  size=%d compare=%d move=%d \n", ArraySize*2, compare_shell, move_shell);
	compare_shell = 0, move_shell = 0;

	shellSort(arr3, ArraySize * 3);
	printf("  size=%d compare=%d move=%d \n", ArraySize * 3, compare_shell, move_shell);
	compare_shell = 0, move_shell = 0;

	shellSort(arr4, ArraySize * 4);
	printf("  size=%d compare=%d move=%d \n", ArraySize * 4, compare_shell, move_shell);
	compare_shell = 0, move_shell = 0;

	shellSort(arr5, ArraySize * 5);
	printf("  size=%d compare=%d move=%d \n", ArraySize * 5, compare_shell, move_shell);
	compare_shell = 0, move_shell = 0;

	shellSort(arr6, ArraySize * 6);
	printf("  size=%d compare=%d move=%d \n", ArraySize * 6, compare_shell, move_shell);
	compare_shell = 0, move_shell = 0;

	shellSort(arr7, ArraySize * 7);
	printf("  size=%d compare=%d move=%d \n", ArraySize * 7, compare_shell, move_shell);
	compare_shell = 0, move_shell = 0;

	shellSort(arr8, ArraySize * 8);
	printf("  size=%d compare=%d move=%d \n", ArraySize * 8, compare_shell, move_shell);
	compare_shell = 0, move_shell = 0;

	shellSort(arr9, ArraySize * 9);
	printf("  size=%d compare=%d move=%d \n", ArraySize * 9, compare_shell, move_shell);
	compare_shell = 0, move_shell = 0;

	shellSort(arr10, ArraySize * 10);
	printf("  size=%d compare=%d move=%d \n", ArraySize * 10, compare_shell, move_shell);
	compare_shell = 0, move_shell = 0;
	////배열 다시 섞기
	shuffleArray(arr1, ArraySize);
	shuffleArray(arr2, ArraySize * 2);
	shuffleArray(arr3, ArraySize * 3);
	shuffleArray(arr4, ArraySize * 4);
	shuffleArray(arr5, ArraySize * 5);
	shuffleArray(arr6, ArraySize * 6);
	shuffleArray(arr7, ArraySize * 7);
	shuffleArray(arr8, ArraySize * 8);
	shuffleArray(arr9, ArraySize * 9);
	shuffleArray(arr10, ArraySize * 10);
	///////Merge Sort 시작////////
    printf("Merge Sort \n");

	mergeSort(arr1, 0, ArraySize - 1);
	printf("  size=%d compare=%d move=%d \n", ArraySize, compare_merge, move_merge);
	compare_merge = 0, move_merge = 0;

	mergeSort(arr2, 0, ArraySize * 2 - 1);
	printf("  size=%d compare=%d move=%d \n", ArraySize * 2, compare_merge, move_merge);
	compare_merge = 0, move_merge = 0;

	mergeSort(arr3, 0, ArraySize*3 - 1);
	printf("  size=%d compare=%d move=%d \n", ArraySize*3, compare_merge, move_merge);
	compare_merge = 0, move_merge = 0;

	mergeSort(arr4, 0, ArraySize * 4 - 1);
	printf("  size=%d compare=%d move=%d \n", ArraySize * 4, compare_merge, move_merge);
	compare_merge = 0, move_merge = 0;

	mergeSort(arr5, 0, ArraySize * 5 - 1);
	printf("  size=%d compare=%d move=%d \n", ArraySize * 5, compare_merge, move_merge);
	compare_merge = 0, move_merge = 0;

	mergeSort(arr6, 0, ArraySize * 6 - 1);
	printf("  size=%d compare=%d move=%d \n", ArraySize * 6, compare_merge, move_merge);
	compare_merge = 0, move_merge = 0;

	mergeSort(arr7, 0, ArraySize * 7 - 1);
	printf("  size=%d compare=%d move=%d \n", ArraySize * 7, compare_merge, move_merge);
	compare_merge = 0, move_merge = 0;

	mergeSort(arr8, 0, ArraySize * 8 - 1);
	printf("  size=%d compare=%d move=%d \n", ArraySize * 8, compare_merge, move_merge);
	compare_merge = 0, move_merge = 0;

	mergeSort(arr9, 0, ArraySize * 9 - 1);
	printf("  size=%d compare=%d move=%d \n", ArraySize * 9, compare_merge, move_merge);
	compare_merge = 0, move_merge = 0;

	mergeSort(arr10, 0, ArraySize * 10 - 1);
	printf("  size=%d compare=%d move=%d \n", ArraySize * 10, compare_merge, move_merge);
	compare_merge = 0, move_merge = 0;
	////////배열 다시 섞기
	shuffleArray(arr1, ArraySize);
	shuffleArray(arr2, ArraySize * 2);
	shuffleArray(arr3, ArraySize * 3);
	shuffleArray(arr4, ArraySize * 4);
	shuffleArray(arr5, ArraySize * 5);
	shuffleArray(arr6, ArraySize * 6);
	shuffleArray(arr7, ArraySize * 7);
	shuffleArray(arr8, ArraySize * 8);
	shuffleArray(arr9, ArraySize * 9);
	shuffleArray(arr10, ArraySize * 10);
	///////Quick Sort 시작////////
	printf("\nQuick Sort \n");

	QuickSort(arr1, 0, ArraySize - 1);
	printf("  size=%d compare=%d move=%d \n", ArraySize, compare_quick, move_quick);
	compare_quick = 0, move_quick = 0;

	QuickSort(arr2, 0, ArraySize*2 - 1);
	printf("  size=%d compare=%d move=%d \n", ArraySize*2, compare_quick, move_quick);
	compare_quick = 0, move_quick = 0;

	QuickSort(arr3, 0, ArraySize * 3 - 1);
	printf("  size=%d compare=%d move=%d \n", ArraySize * 3, compare_quick, move_quick);
	compare_quick = 0, move_quick = 0;

	QuickSort(arr4, 0, ArraySize * 4 - 1);
	printf("  size=%d compare=%d move=%d \n", ArraySize * 4, compare_quick, move_quick);
	compare_quick = 0, move_quick = 0;

	QuickSort(arr5, 0, ArraySize * 5 - 1);
	printf("  size=%d compare=%d move=%d \n", ArraySize * 5, compare_quick, move_quick);
	compare_quick = 0, move_quick = 0;

	QuickSort(arr6, 0, ArraySize * 6 - 1);
	printf("  size=%d compare=%d move=%d \n", ArraySize * 6, compare_quick, move_quick);
	compare_quick = 0, move_quick = 0;

	QuickSort(arr7, 0, ArraySize * 7 - 1);
	printf("  size=%d compare=%d move=%d \n", ArraySize * 7, compare_quick, move_quick);
	compare_quick = 0, move_quick = 0;

	QuickSort(arr8, 0, ArraySize * 8 - 1);
	printf("  size=%d compare=%d move=%d \n", ArraySize * 8, compare_quick, move_quick);
	compare_quick = 0, move_quick = 0;

	QuickSort(arr9, 0, ArraySize * 9 - 1);
	printf("  size=%d compare=%d move=%d \n", ArraySize * 9, compare_quick, move_quick);
	compare_quick = 0, move_quick = 0;

	QuickSort(arr10, 0, ArraySize * 10 - 1);
	printf("  size=%d compare=%d move=%d \n", ArraySize * 10, compare_quick, move_quick);
	compare_quick = 0, move_quick = 0;
	
	return 0;
}
// 배열에 값 삽입하는 함수
void insertValue(int* arr, int size) {   

	for (int i = 0; i < size; i++) {
		arr[i] = i;             
	}
}
// 배열 출력하는 함수
void printArray(int* arr, int size) {   

	for (int i = 0; i < size; i++) { 
		printf("%d ", arr[i]);
	}printf("\n");
}

// 배열을 섞기 위한 함수
void shuffleArray(int* arr, int size) { 

	for (int i = 0; i < size; i++) {
		swap(&arr[i], &arr[(rand() % (size - i)) + i]);
	}
}
// shuffleArray를 위한 swap 함수
void swap(int* a, int* b){  

	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;

}
// Select Sort를 위한 swap 함수
void swap_selec(int* a, int* b) {  

	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	move_selec += 2;

}
// 선택 정렬 수행
void selectionSort(int* arr, int size) {  

	for (int i = 0; i < size - 1; i++) { 
		int min = i;

		for (int j = i + 1; j < size; j++) {
			compare_selec += 1;
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		swap_selec(&arr[i], &arr[min]);
	}
}
// bubbleSort를 위한 swap 함수
void swap_bubble(int* a, int* b) {  

	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	move_bubble += 2;

}
// 버블 정렬 수행 함수
void bubbleSort(int* arr, int size) {   

	for (int i = 0; i < size - 1; i++) {

		for (int j = 0; j < size - (i+1);j++) {
			compare_bubble += 1;
			if (arr[j] > arr[j + 1]) {
				swap_bubble(&arr[j], &arr[j + 1]);
			}
		}
	}
}
// 삽입 정렬 수행 함수
void insertSort(int* arr, int size) {  

	int j, key;

	for (int i = 1 ; i < size ; i ++ ){
		key = arr[i];

		for (j = i ; j > 0; j--) {
			compare_insert += 1;
			if (key < arr[j - 1]) {
				arr[j] = arr[j - 1];
				move_insert += 1;
			}
			else
				break;
		}
		arr[j] = key;
		move_insert += 1;
	}
}
///shellSort 함수
void shellSort (int* arr, int size) {

	int h, i;

	for (h = size / 2; h > 0; h = h / 2) {
		for (i = 0; i < h; i++) {
			insertSort2(arr, i, size - 1, h);
		}
	}
}
// 쉘정렬을 위한 삽입 정렬 수행
void insertSort2(int* arr, int first, int last, int h) {  
	
	int j, key;

	for (int i = first+h; i <= last; i += h) {
		key = arr[i];

		for (j = i; j  >  first ; j -= h) {
			compare_shell += 1;
			if (key < arr[j - h]) {
				arr[j] = arr[j - h];
				move_shell += 1;
			}
			else
				break;
		}
		arr[j] = key;
		move_shell += 1;
	}
}
// Merge Sort를 위한 merge 함수
void merge(int* arr, int first, int mid, int last) {

	int i = first, j = mid + 1, k = first;
	int tmp[ArraySize_merge];

	while (i <= mid && j <= last) {
		compare_merge += 1;
		if (arr[i] <= arr[j]) {
			tmp[k++] = arr[i++];
			move_merge += 1;
		}
		else {
			tmp[k++] = arr[j++];
			move_merge += 1;
		}
	}
	//한쪽이 끝날때까지 정렬
	//남은 값들은 이미 정렬됐으므로 순서대로 이어서 넣어줌.
	while (i <= mid) {
		tmp[k++] = arr[i++];
		move_merge += 1;
	}
	while (j <= last) {
		tmp[k++] = arr[j++];
		move_merge += 1;
	}
	//합친 값을 원래 배열에 다시 넣어줌
	for (int i = first; i <= last; i++) {
		arr[i] = tmp[i];
		move_merge += 1;
	}
}
// MergeSort 수행 함수
void mergeSort(int* arr, int first, int last) {
	
	if (first < last) {	
		int mid = (first + last) / 2;
		mergeSort(arr, first, mid);//전반부 정렬
		mergeSort(arr, mid + 1, last);//후반부 정렬
		merge(arr, first, mid, last);//합병
	}
}
// quick Sort를 위한 a,b 스왑 함수
void Swap(int* arr, int a, int b) { 

	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
	move_quick += 2;
}
// Quick Sort를 위해 Partion을 나누는 함수 
int Partition(int* arr, int left, int right) {

	int pivot = arr[left]; // 피벗의 위치는 가장 왼쪽에서 시작
	int low = left + 1;
	int high = right;
	// 교차되기 전까지 반복한다 
	while (low <= high) 
	{    // 피벗보다 큰 값을 찾는 과정
		while (pivot >= arr[low] && low <= right)  
		{
			low++; // low를 오른쪽으로 이동 
			move_quick += 1;
		}// 피벗보다 작은 값을 찾는 과정
		while (pivot <= arr[high] && high >= (left + 1))  
		{
			high--; // high를 왼쪽으로 이동
			move_quick += 1;
		}//교차되지 않은 상태이면 스왑 과정 실행
		if (low <= high)  
		{ //low와 high를 스왑 
			Swap(arr, low, high);
		}
	}

	Swap(arr, left, high); 
	return high;  

}
//QuickSort 수행 함수
void QuickSort(int* arr, int left, int right)
{
	compare_quick += 1;

	if (left <= right)
	{
		int pivot = Partition(arr, left, right); // 둘로 나누어서
		QuickSort(arr, left, pivot - 1); // 왼쪽 영역을 정렬한다.
		QuickSort(arr, pivot + 1, right); // 오른쪽 영역을 정렬한다.
	}
}
