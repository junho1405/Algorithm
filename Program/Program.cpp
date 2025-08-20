#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define SIZE 7
int parent[SIZE];

class Kruskal
{

private:
	class Edge
	{
	private:
		int vertexX;
		int vertexY;
		int weight;
	public:
		Edge(int vertexX, int vertexY, int weight)
		{
			this->vertexX = vertexX;
			this->vertexY = vertexY;
			this->weight = weight;
		}

		const int& X() { return vertexX; }
		const int& Y() { return vertexY; }
		const int& Weight() { return weight; }

		const bool& operator < (const Edge& edge)
		{
			return weight < edge.weight;
		}
	};

	vector<Edge> nodeList;
public:
	Kruskal()
	{

	}
	void insert(int vertexX, int vertexY, int weight)
	{
		Edge edge(vertexX, vertexY, weight);
		nodeList.push_back(edge);
	}
	void calculate()
	{
		sort(nodeList.begin(), nodeList.end());
		for ( int  i = 0; i<nodeList.size();i++)
		{
			cout << nodeList[i].X() << " - " << nodeList[i].Y() << " : " << nodeList[i].Weight();
			cout<< endl;
			//cout << nodeList[i].X() << endl;
			//cout << nodeList[i].Y() << endl;
			//cout << nodeList[i].Weight() << endl;
		}	
	}
};

int find(int x)
{
	//배열의 index와 값이 같다면 root node를 발견하였습니다.

	// 부모노드의 변수를 전달하면서, root node를 찾을 때까지
	// 재귀함수를 호출하여 반복합니다.
	if (parent[x] == x)//int x가 배열의 index와 같은지
	{
		return x;
	}
	else
	{
		return parent[x] = find(parent[x]);

	}
}
void Union(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y) return;
	if (x < y)
	{
		parent[y] = x;
	}
	else
	{
		parent[x] = y;
	}
}
int cost(Kruskal& kruskal)
{
	for (int i = 0; i < SIZE; i++)
		parent[i] = i;

	int totalCost = 0;
	return totalCost;
	cout << totalCost;
}

int main()
{
#pragma region 최소 신장 트리
	// 그래프와 모든 정점을 포함하면서 사이클이 존재하지 않는
	// 부분 그래프로, 그래프의 모든 정점을 최소 비용으로 연결하는 트리입니다.
	// 
	// 그래프의 정점의 수가 n개 일 때, 간선의 수는 n-1개 입니다.
	// 
	Kruskal kruskal;
	kruskal.insert(1, 2, 71);
	kruskal.insert(1, 4, 30);
	kruskal.insert(1, 5, 15);
	kruskal.insert(1, 7, 12);
	kruskal.insert(2, 4, 23);
	kruskal.insert(2, 5, 65);
	kruskal.insert(3, 5, 18);
	kruskal.insert(3, 6, 36);
	kruskal.insert(4, 7, 13);
	kruskal.insert(5, 6, 44);
	kruskal.insert(5, 7, 79);

	kruskal.calculate();

#pragma endregion
}