#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace virus
{
	vector<vector<int>> graph(101);
	bool visited[101] = { false };

	int n, m;      // n 컴퓨터수, m(선)의 수
	int count = 0; // 1번 컴퓨터와 연결된 컴퓨터의 수

	void DFS(int node) // 현재 연결된 컴퓨터(Vertex, node)
	{
		for (int i = 0; graph[node].size(); i++)
		{
			int current = graph[node][i];

			if (visited[current]) continue;

			visited[current] = true;
			count++;
			DFS(current);
		}
	}

	void Example01()
	{
		cin >> n >> m;

		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;	  // 컴퓨터, 정점

			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		// 컴퓨터 1 감염
		visited[1] = true;		
		DFS(1);

		cout << count << '\n';
	}
}