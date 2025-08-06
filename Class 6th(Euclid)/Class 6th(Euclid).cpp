#include<iostream>
using namespace std;

int function(int x, int y)
{
	// 1. 두 개의 자연수 x, y가 있을 때
	//		x와 y를 나눈 나머지를 r이라고 합니다.
	// 
	// 2. r이 0이라면, x와 y의 최대 공약수가 y가 됩니다.
	// 
	// 3. r이 0이 아니라면, x와 y의 최대 공약수는 y와 r의
	//		최대공약수 같기 때문에  x에는 y 그리고 y에는
	//		r을 대입한 후 1번으로 돌아가면 됩니다.
	//
	if (y == 0)
	{
		return x;
	}
	else
	{
		return function(y, x % y);
	}
}

int main()
{
#pragma region 유클리드 호제법
	// 2개의 자연수 또는 정식의 최대 공약수를 구하는 방법으로
	// 두 수가 서로 상대방 수를 나누어서 원하는 수를 알아내는 알고리즘입니다.
	//
	int x = 271;
	int y = 192;
	int result;
	for (int i = 1; i <= x && i <= y; i++)
	{
		if (x % i == 0 && y % i == 0)
		{
			result = i;
		}
	}
	//cout << "최대공약수 : " << result << endl;
	// 풀이를 하자면 i<-이게 최소 공배수의 값이다.
	// x/i와 y/i를 해서 0이 동시에 나오는 값이면 i++을 한다.
	//

#pragma endregion
	cout << function(2, 4) << endl;
	return 0;

}