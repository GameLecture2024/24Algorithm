#include "Sort.h"
#include <algorithm>
#include <iostream>

void bubbleSort(int list[], int n)
{
	// i번 반복

	for (int i = n - 1; i > 0; i--)	   // n사이클 진행, 전체의 -1
	{
		for (int j = 0; j < i; j++)	   // i사이클 수만큼 반복 (제일 작은 수 가장 왼쪽)
		{
			if (list[j] > list[j + 1])
				std::swap(list[j], list[j + 1]);
		}
	}
	
	// for (int i = 1; i < n; i++)  버블 정렬 구현

}

void BubbleExample()
{
	int list[] = { 7, 5, 3, 6, 9 };

	bubbleSort(list, 5);

	for (int i = 0; i < 5; i++)
	{
		std::cout << list[i] << " ";
	}

	std::cout << std::endl;
}

void selectionSort(int list[], int n)
{
	// n사이클
	int least;

	for (int i = 0; i < n; i++)
	{
		least = i;

		for (int j = i + 1; j<n; j++)
		{
			if (list[j] < list[least])
			{
				least = j;
			}
		}

		if (least != i)
		{
			std::swap(list[i], list[least]);
		}

	}
	// 최소값을 찾아서, least 인덱스와 swap을 해라
}

void SelectionExample()
{
	int list[] = { 7, 5, 3, 6, 9 };

	selectionSort(list, 5);

	for (int i = 0; i < 5; i++)
	{
		std::cout << list[i] << " ";
	}
}

