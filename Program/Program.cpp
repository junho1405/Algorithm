#include<iostream>
using namespace std;

void sieve(int n)
{
	//소수를 구하되 x라는 값이 있다고치면
	// 배열n에서 x의 배수는 모두 0으로 만드는 방식
	int* list = new int[n+1];
	for (int i = 0; i < n; i++)
	{
		list[i] = 1;//배열초기화
	}
	//0,1은 소수아님
	list[0] = 0;
	list[1] = 0;

	
}

int main()
{
#pragma region 에라토스테네스의 체
	// 소수를 출력하는 알고리즘
	//int  n = 50;
	//int  j = 0;
	//for (int i = 2; i <= n; i++)
	//{
	//	for (j = 2; j < i; j++)
	//	{
	//		if(i % j == 0)
	//		{
	//			break;
	//		}
	//	}
	//	if (i == j)
	//	{
	//		cout << i << endl;
	//	}
	//}
#pragma endregion
	int n = 16;
	sieve(n);
	return 0;
}