#include <iostream>

#include "Sort.h"
#include "InputReference.h"
#include "Pow.h"
#include "DivideAndConquer.h"

int main()
{
	std::cout << "Hello World!" << std::endl;

	BubbleExample();
	SelectionExample();
	InsertSortExample();
	CountSort();
	InputExample();

	std::cout << std::endl;
	std::cout << "a의 제곱수 구하기 :" << " ";
	std::cout <<Pow(3, 5);

	std::cout << "병합 정렬 " << std::endl;
	
	int list[8] = {7, 6, 5, 8, 3, 5, 9 , 1 };

	MergeSort(list, 0, 7);

	for (int i = 0; i < 8; i++)
	{
		std::cout << list[i] << " ";
	}

	std::cout << "퀵 선택" << std::endl;

	srand(time(0));

	std::vector<int> someVec = { 10, 5 , 8, 2, 7 , 4 };

	//std::cout << QuickSelect(someVec, 2);

	QuickSort(someVec, 0, someVec.size() - 1);

	for (int num : someVec)
	{
		std::cout << num << " ";
	}

}