# C-language #bubble arrangement
C language code making practicing

// from 5 people, receive 3 each point, which is math, korean, englsih. then arrange it from lower score to higher score.
if the point is over average, mark 'pass' next to it. other wise, mark 'fail' next to it.

#include <stdio.h>

int main()
{
	int math, korean, english;
	int sum;
	int i, j;
	int arr[100];
	int temp;
  int sum_average;

	for (i = 0; i < 5; i++)
	{
		{
			printf("math %d : ", i + 1);
			scanf("%d", &math);

			printf("korean %d : ", i + 1);
			scanf("%d", &korean);

			printf("english %d : ", i + 1);
			scanf("%d", &english);

			sum = math + korean + english;

			printf("sum %d %d \n", i + 1, sum);

			printf("average %d : %d \n", i + 1, sum / 3);
		}
		arr[i + 1] = sum / 3;
	}

	for (i = 0; i<5; i++)
	{
		printf("평균값 : %d \n", arr[i + 1]);
	}

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (arr[j + 1] >= arr[j + 2])
			{
				temp = arr[j + 1];
				arr[j + 1] = arr[j + 2];
				arr[j + 2] = temp;
			}
		}
	}
	for (i = 0; i < 5; i++)
	{
		printf("arr[%d] : %d \n", i + 1, arr[i + 1]);
	}
  sum_average = (arr[1] + arr[2] + arr[3] + arr[4] + arr[5]) / 5;
	for (i = 0; i < 5; i++)
	{
		if (sum_average <= arr[i + 1])
		{
			printf("pass \n");
		}
		else
			printf("fail \n");
	}

	return 0;
}
