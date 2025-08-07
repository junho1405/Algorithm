#include<iostream>
using namespace std;

void sieve(int n)
{
	int* container = new int[n + 1];
	for (int i = 0; i <= n; i++)
	{
		container[i] = i;
	}
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (container[i] == 0)
		{
			continue;
		}
		for (int j = i * 2; j <= n; j += i)
		{
			container[j] = 0;
		}
	}
	for (int i = 2; i <= n; i++)
	{
		if (container[i] != 0)
		{
			cout << container[i] << " ";
		}
	}
	delete[] container;

	//소수를 구하되 x라는 값이 있다고치면
	// 배열n에서 x의 배수는 모두 0으로 만드는 방식

	// 어떻게?
	// i를 얻고 i*i는 모두 i의 배수니 소수가 될 수 없다.

	//int* list = new int[n+1];
	//
	//for (int i = 0; i <= n; i++)
	//{
	//	list[i] = 1;
	//}
	////0,1은 소수아님
	//list[0] = 0;
	//list[1] = 0;
	//for (int i = 2; i * i <= n; i++)
	//{
	//	if (list[i] == 1)
	//	{
	//		for (int j = i * i; j <= n; j += i)
	//		{
	//			list[j] = 0;
	//		}
	//	}
	//}
	//for (int i = 2; i <= n; i++)
	//{
	//	if (list[i] == 1)
	//	{
	//		cout << i << endl;
	//	}
	//}
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
	sieve(79);
	return 0;
}