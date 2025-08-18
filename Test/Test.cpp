#include <iostream>
#include<vector>
using namespace std;

//맵 (4*4)
#define SIZE 4
const int map_X = 4;
const int map_Y = 4;
//0이 통과 1이 벽

int map[map_X][map_Y]
{ 
	{ 1,0,1,1 },
	{ 1,0,1,0 },
	{ 1,1,1,1 },
	{ 0,0,0,1 }
};
//왔던곳 확인
bool visited[map_X][map_Y];
// 상하좌우순으로 움직임
// 움직여서 벽이면 다음 방향으로 진행 
// 
// 이게다 돌아다녀보고 목적지에 도달할 수 있으면 true를 출력해야함<<<중요
// 동서남북을 어떻게 표현? 
// 그래프생각하자
// {0,0}에서 시작
// 위의 지도기준으로 설명하면
//{ 0, 0 } { 0, 1 } { 0, 2 } { 0, 3 }
//{ 1, 0 } { 1, 1 } { 1, 2 } { 1, 3 }
//{ 2, 0 } { 2, 1 } { 2, 2 } { 2, 3 }
//{ 3, 0 } { 3, 1 } { 3, 2 } { 3, 3 }

//목적지설정
int targetX=4;
int targetY=4;
//유저위치
int userX = 0;
int userY = 0;

// class로 안하고 바로 void로 해도 될듯?
void dfs(int x, int y)
{
	//목적지를 찾았는가?

	if (x == targetX && y == targetY)
	{
		cout << "true" << endl;
		return;
	}
	else
	{
		cout << "false" << endl;
		return ;
	}
	//돌아다니는 for문(재귀)
	cout <<"테스트" << x << endl;
	for (int i = 0; i < SIZE; i++)
	{
		dfs(userX, userY);//user의 좌표를 찍어야하는데 어떻게?
	}
}
int main()
{
	//해결못한거
	//위치값동서남북어캐함
	//지금상황 탐색을 안함
	//왜냐? : 매개변수값이 안변함.
	cout << "4,4일경우" << endl;
	dfs(4, 4);
	cout << "0,0일경우" << endl;
	dfs(0, 0);
	cout << "탐색기능 구현실패" << endl;
}