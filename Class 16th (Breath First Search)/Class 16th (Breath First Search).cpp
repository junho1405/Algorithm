#include <iostream>
#include<queue>
#include <vector>
using namespace std;
#define SIZE 8

class Graph
{
private:
	queue<int> queue;

	bool visited[SIZE];
	vector<int> adjacencyList[SIZE];

public:
	Graph()
	{
		for (int i = 0; i < SIZE; i++)
		{
			visited[i] = false;
		}

	}

	void insert(int i, int j)
	{
		adjacencyList[i].push_back(j);
		adjacencyList[j].push_back(i);
	}
	void search(int start)
	{
		//정점넣기
		queue.push(start);
		//방문표시
		visited[start] = true;
		while (!queue.empty())
		{
			int current = queue.front();
			queue.pop();
			cout << current << " ";

			for (int i = 0; i < adjacencyList[current].size(); i++)
			{
				int next = adjacencyList[current][i];
				if (visited[next] == false)
				{
					queue.push(next);
					visited[next] = true;
				}
			}
		}
	}
};

int main()
{
#pragma region 너비 우선 탐색(Breath First Search)
	// 시작 정점을 방문한 후 시작 정점에 인접한
	// 모든 정점들을 우선적으로 방문하는 탐색입니다.

	Graph graph;
	graph.insert(1, 2);
	graph.insert(1, 3);
	graph.insert(2, 4);
	graph.insert(2, 5);
	graph.insert(3, 6);
	graph.insert(3, 7);

	graph.search(1);

	// 더 이상 방문하지 않는정점이 없을 때까지 방문하지 않은
	// 모든 정점들에 대해서 너비 우선 탐색을 적용합니다.
	//
#pragma endregion
	return 0;
}