#include <iostream>
using namespace std;

void perpect(int x)
{
	int value = 1;
	for (int i = 2; i <= x / 2; i++)
	{
		if (x % i == 0)
		{
			value += i;
		}
	}

}

int main()
{
	//문제 
	// 완전수 구하기
	// 예시 : 6,28...
	// X의 약수 다 구하고 약수 다 더해서 X가 나오는 값만 출력


	int x = 6;

}
