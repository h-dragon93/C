#include <stdio.h>
#define MAX_LENGTH 100

// 배열의 이름을 지어 출력하고 입력받은 배열의 원소를 첫 원소부터 len길이만큼 출력하는 함수
void printArray(char *name, int a[], int len)
{
	int i;

	printf("%s[%d] = ", name, len);
	printf("{");
	for (i = 0; i<len; i++)
	{
		if (i == (len - 1)) printf("%d", a[i]);           //마지막 원소는 뒤에 ,를 붙이지 않도록 조건 분기
		else printf("%d,", a[i]);
	}
	printf("}");
	printf("\n");
}

// 배열과 배열의 크기, 원소를 삽입할 위치, 삽입할 값을 입력받아 해당 배열에 원소를 삽입하는 함수. 삽입 후 배열의 길이를 반환
int insertElem(int a[], int size, int index, int value)
{
	if (index <= size)                                //원소를 삽입할 위치가 배열의 범위에 있는 경우 삽입 정상 실행
	{
		int i;
		for (i = size; i>index; i--)
		{
			a[i] = a[i - 1];
		}
		a[index] = value;                           //배열의 삽입할 위치에 값을 할당(삽입)

		return size + 1;
	}
	else return size;                               //원소를 삽입할 위치가 배열의 범위를 벗어나는 경우 삽입을 수행하지 않고 입력받은 배열의 길이를 그대로 반환
}

// 배열과 배열의 크기, 삭제할 원소의 위치를 입력받아 해당 위치의 원소를 삭제하는 함수. 삭제 후 배열의 길이를 반환
int deleteElem(int a[], int size, int index)
{
	if (index<size)                                 //원소를 삽입할 위치가 배열의 범위에 있는 경우 삭제   정상 실행
	{
		int i;
		for (i = index; i<size; i++)
		{
			a[i] = a[i + 1];
		}
		return size - 1;
	}

	else return size;                               //원소를 삭제할 위치가 배열의 범위를 벗어나는 경우 삭제를 수행하지 않고 입력받은 배열의 길이를 그대로 반환
}


int main(void) {
	int list[MAX_LENGTH];
	int size = 5;
	int i;

	for (i = 0; i < size; i++) {
		list[i] = 10 + i * 10;
	}


	printf("HW 1. Insert & Delete Element\n");
	printArray("list", list, size);
	size = insertElem(list, size, 3, 200);
	printArray("list", list, size);
	size = insertElem(list, size, 0, 300);
	printArray("list", list, size);
	size = deleteElem(list, size, 3);
	printArray("list", list, size);
	size = deleteElem(list, size, 0);
	printArray("list", list, size);

	return 0;
}
