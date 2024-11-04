// 프림알고리즘(Prim's algorithm)예제1

#include <iostream>
using namespace std;

#define marked 		-1 		// 방문여부 확인, 싸이클이 형성되지 않게하기위한 값
#define NODE_NUM	7 		// 노드(정점)의 수
#define INF 		9999	//무한대값

//* ★
// 가중치가 작은값이 있을 때 그 값으로 갱신해주시요
// (★ // 문제 2-1) 주어진 그래프를 기준으로 4행부터 인접행렬을 완성하시오.(5점)
//*/

int primData[NODE_NUM][NODE_NUM] =
{
	{ 0,   67,	INF, 28,  17,  INF, 12 },
	{ 67,  0,	INF, 24,  62,  INF, INF},
	{ INF, INF, 0,   INF, 20,  37,  INF},
	{ 28,  24,  INF, 0,   INF, INF, 13 },
	{ 17,  62,  20,  INF, 0,   45,  28 },	// ★ // 데이터 수정
	{ INF, INF, 37,  INF, 45,  0,   INF},		// ★ // 데이터 수정
	{ 12,  INF,	INF, 13,  28,  INF, 0  }  // ★ // 데이터 수정
}; // 인접 행렬

void PRIM(int n, int distance[NODE_NUM][NODE_NUM]);// 함수의 정의 변경


int main()
{
	// 아래의 수험번호, 성명 수정하여 입력해야 함
	system("mode con cols=80 lines=30 | title KOCCA [Problem 2]");
	printf("■ [문제2] 모범답안 \n■ 수험번호: 수험번호 기재 \n■ 성    명: 성명 기재\n");
	printf("\n■  Prim Algorithm ■ \n");

	cout << "==Prim's algorithm MST(Minimum Spanning Tree)==" << endl;
	PRIM(NODE_NUM, primData);

	scanf_s("%d");
}


void PRIM(int n, int distance[NODE_NUM][NODE_NUM])
{
	int nNodeNum, nCheckPrimNode, nCheckCycleNdoe, nCntPrimNode, primNode[NODE_NUM];
	int nMinDist[NODE_NUM], nNewMin;
	int nSumWeight = 0;

	for (nNodeNum = 1; nNodeNum < n; nNodeNum++) {
		nMinDist[nNodeNum] = distance[0][nNodeNum]; 	// 시작점
		primNode[nNodeNum] = 0; 						//시작 초기값 0번째 정점
	}

	for (nNodeNum = 1; nNodeNum < n; nNodeNum++) {
		nCntPrimNode = 1; 								// 프림카운팅 노드(정점) 1
		nNewMin = nMinDist[1];

		for (nCheckPrimNode = 2; nCheckPrimNode < n; nCheckPrimNode++)
			if (nMinDist[nCheckPrimNode] < nNewMin) {
				//* ★ // 문제 2-2) 아래의 지시에 맞게 코드를 작성하시요. (10점)
				// 가중치가 작은값이 있을 때 그 값으로 갱신
				// ( ★ 코드 추가 작성할 부분)
				nNewMin = nMinDist[nCheckPrimNode];
				// 해당 정점노드를 프림연결노드(정점)로 갱신
				nCntPrimNode = nCheckPrimNode;
			}
	
		cout << nCntPrimNode << " 번 노드의 가중치(edge):" << " ";
		cout << nNewMin; 								// 가중치=최소비용=최단거리=최소시간
		cout << "\n";

		nSumWeight = nSumWeight + nNewMin; 				// 가중치 합계

		primNode[nCntPrimNode] = marked;				//방문하면 -1로 처리, 싸이클이 형성되지 않게 하기위해서
		nMinDist[nCntPrimNode] = INF; 					//초기값으로 가중치 무한대값 9999 대입

		for (nCheckCycleNdoe = 1; nCheckCycleNdoe < n; nCheckCycleNdoe++) {
			//* ★ // 문제 2-3) 아래의 지시에 맞게 코드를 작성하시요. (5점)
			// 인접한 노드 중에서 사이클이 형성되지 않고 가중치 갱신하도록 ★ 빈곳을 완성하시오.
			if ((primNode[nCheckCycleNdoe] != marked) 
				&&
				(distance[nCheckCycleNdoe][nCntPrimNode] < nMinDist[nCheckCycleNdoe])
				) 
			{
				// 최소값으로 가중치 갱신하시오.
				// ( ★ 코드 추가 작성할 부분)
				nMinDist[nCheckCycleNdoe] = distance[nCntPrimNode][nCheckCycleNdoe];
				// 최소값을 가진 가중치의 정점(노드)
				primNode[nCheckCycleNdoe] = nCntPrimNode;		
			}
		}
	}
	cout << "\n 가중치 합= " << nSumWeight;
}

