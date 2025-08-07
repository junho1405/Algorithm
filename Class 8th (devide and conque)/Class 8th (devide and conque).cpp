#include<iostream>
using namespace std;

int max(int list[], int left, int right)
{
	//지금은 { 20,15,99,1 }이 넘어온상태
	//배열의 0번1번(20,15)를 좌로 2번3번(99,1)을 우로 
	// 지금은 총 4개니깐 번호는 3(0~3)
	// 재귀호출할것
	// 사이즈넘겨받았으니 왼쪽은 
	if (left == right)
	{
		return list[left];
	}
	else
	{
		int leftmax = max(list, left, (left + right) / 2);
		int rightmax = max(list, (left + right) / 2 + 1, right);
		if (leftmax < rightmax)
		{
			return rightmax;
		}
		else
		{
			return leftmax;
		}
	}

	return 0;
}

int main()
{
#pragma region 분할정보알고리즘
	// 주어진 2개 이상의 부분으로 문제를 나눈 뒤 각 부분
	// 문제에 대한 답을 재귀 호출을 이용하여 계산한 다음,
	// 그 답으로부터 전체 문제의 답을 계산해내는 알고리즘입니다.

	// 분할(Divide) : 주어진 문제를 두 개 혹은 그 이상의 형식으로 문제를
	// 더 이상 나누어서 문제가 필요없을 때까지 계속 분할합니다.

	// 통합 (Combine) : 나누어서 해결한 문제들을 통합해서 원래 문제의 해답을 생성합니다.
	// 

	int list[] = { 20,74,152,141, 15,99,1 };
	int size = sizeof(list) / sizeof(list[0]);
	cout << max(list, 0, size - 1) << endl;
#pragma endregion
	return 0;
}