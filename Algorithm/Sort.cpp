#include "Sort.h"
#include <algorithm>
#include <iostream>

void bubbleSort(int list[], int n)
{
	// i�� �ݺ�

	for (int i = n - 1; i > 0; i--)	   // n����Ŭ ����, ��ü�� -1
	{
		for (int j = 0; j < i; j++)	   // i����Ŭ ����ŭ �ݺ� (���� ���� �� ���� ����)
		{
			if (list[j] > list[j + 1])
				std::swap(list[j], list[j + 1]);
		}
	}
	
	// for (int i = 1; i < n; i++)  ���� ���� ����

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
	// n����Ŭ
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
	// �ּҰ��� ã�Ƽ�, least �ε����� swap�� �ض�
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

