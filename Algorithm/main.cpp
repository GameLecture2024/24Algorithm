#include <iostream>
#include "timeChecker.h"
#include "Sort.h"
#include "InputReference.h"
#include "Pow.h"
#include "DivideAndConquer.h"
#include "DynamicProgramming.h"
#include "BackTracking.h"
#include "array2D.h"
#include "graph.h"
#include "MST.h"
#include "AStar.h"
#include "Regular Expression.h"

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

	system("cls");

	std::cout << "재귀 방식 : 피보나치 수열" << std::endl;

	int count = 10;

	std::cout << "피보나치 수 결과:" << Fibonacci(count) << std::endl;
	std::cout << "피보나치 수 시간:" << measureExecutionTime(Fibonacci, count) << "ms" << std::endl;

	std::cout << "동적 계획법 방식 : 피보나치 수열" << std::endl;

	std::cout << "피보나치 수 결과:" << Fibonacci_DP(count) << std::endl;
	std::cout << "피보나치 수 시간:" << measureExecutionTime(Fibonacci_DP, count) << "ms" << std::endl;


	std::cout << "계단 오르기 문제 (메모이제이션)" << std::endl;

	std::vector<int> stairs = { 10, 20, 15 , 25, 10 ,20 , 80 };

	std::cout << "계단의 수가 (" << stairs.size() << ")인 최대 값 : " << StairCount(stairs) << std::endl;

	std::cout << "순열" << endl;
	Permutation::Case01();
	std::cout << "조합" << endl;
	Combine::Case02();

	system("cls");
	//Board::Case1();
	//Board::Case2();
	//Board::Case3();
	//GraphVec::Print();
	//InputGraph::Show();
	InputWeight::Show();
	InputWeight::Show2();
	InputGraph::Show001();

	system("cls");
	FoundPath::GetBoard();
	Express();
}