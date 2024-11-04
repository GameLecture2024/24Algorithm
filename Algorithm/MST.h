#pragma once

// 최소 신장 트리 (minimum spanning tree)

#include <iostream>
#include <vector>
#include <algorithm>

#define INF 9999

using namespace std;

namespace InputWeight
{
	vector<pair<pair<int,int>, int>> edges;	 // edges. first (a,b) second : weight

	void Show()
	{
		// a-b 10 make_pair<a,b>  [i].first, [i].second
		edges.push_back({{1,2}, 10 });
		edges.push_back({{1,3}, 15 });
		edges.push_back({{2,3}, 5 });
		edges.push_back({{2,4}, 5 });
		edges.push_back({{3,4}, 25 });

		for (const auto& edge : edges)
		{
			cout << "Edge : (" << edge.first.first << "," << edge.first.second << "), weight :"
				               << edge.second << endl;
		}
		cout << '\n';
	}

	class Edge
	{
	private:
		int node[2]; // node[0] : a, node[1] : b
		int distance;
	public:
		Edge(int node1, int node2, int _distance)
		{
			node[0] = node1;
			node[1] = node2;
			distance = _distance;
		}

		int first_node()  const  { return this->node[0];  }
		int second_node() const  { return this->node[1];  }
		int getDistance() const  { return this->distance; }

		// 연산자 오버로딩

		bool operator < (Edge& edge)
		{
			return this->distance < edge.distance;
		}

	};

	void Show2()
	{
		vector<Edge> edges;

		edges.push_back(Edge(1, 2, 10));
		edges.push_back(Edge(1, 3, 15));
		edges.push_back(Edge(2, 3, 5));
		edges.push_back(Edge(2, 4, 18));
		edges.push_back(Edge(3, 4, 25));

		for (const auto& edge : edges)
		{
			cout << "Edge : (" << edge.first_node() << "," << edge.second_node() << "), weight :"
				<< edge.getDistance() << endl;
		}

		sort(edges.begin(), edges.end());
		cout << endl;

		for (const auto& edge : edges)
		{
			cout << "Edge : (" << edge.first_node() << "," << edge.second_node() << "), weight :"
				<< edge.getDistance() << endl;
		}
	}

}

namespace InputGraph
{
	// 그래프를 코드로 표현하는 방법

	// 1. Matrix  2. 



	void Show001()
	{
		int size = 7;

		int graph[7][7] =
		{
			{ 0,   67,	INF, 28,  17,  INF, 12 },
			{ 67,  0,	INF, 24,  62,  INF, INF},
			{ INF, INF, 0,   INF, 20,  37,  INF},
			{ 28,  24,  INF, 0,   INF, INF, 13 },
			{ INF,  INF,  INF,  INF, 0,   INF,  INF },	// ★ // 데이터 수정
			{ INF, INF, INF,  INF, INF,  0,   INF},		// ★ // 데이터 수정
			{ INF,  INF,	INF, INF,  INF,  INF, 0  }  // ★ // 데이터 수정
		};
		

		


		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				cout << graph[i][j] << ' ';
			}
			cout << '\n';
		}
	}

}


namespace Union_Find
{
	// 서로소 문제

	int getParent(int arr[], int x) // 그래프를 주어졌을 때 루트노드(부모)	
	{
		if (x = arr[x]) return x;

		return getParent(arr, arr[x]);
	}

	void UnionParent(int arr[], int a, int b) // 두개의 그래프를 하나로 합친다.
	{
		a = getParent(arr, a);
		b = getParent(arr, b);

		if (a < b) arr[b] = a;
		else
		{
			arr[a] = b;
		}
	}

	bool findParent(int arr[], int a , int b)  // 같은지 아닌지
	{
		a = getParent(arr, a);
		b = getParent(arr, b);

		if (a == b)
			return true;
		else
			return false;	
	}

}