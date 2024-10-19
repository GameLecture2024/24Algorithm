#include "InputReference.h"

#include <iostream>


void InputExample()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	// 의미 : stdio.h - iosteram을 동기화 해준다.
	// 버퍼 <- iostream, stdio.h

	// std::cout << "MY Name : "
	// std:: cin >>     
	// std::endl; "\n"
	// 버퍼 공간에서 cin 데이터 (자동으로 저장). 0.0n초

	std::cout << "My ";
	printf("Name");


	//  std::endl;   '\n'
	// std::endl; ->   std::cout << 'n' << std::flush;   버퍼 공간을 비워라.
	// Hello World! -13char
	// buffer 최대 max 1만
	// 769 Hello World! 출력 std::flush 1번 실행
	// 769 std::endl;         std::flsuh 769번 실행  (0.01초)
	// 10만 입력
	// O(n) <- (n^2)
}
