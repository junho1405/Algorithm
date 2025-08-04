#include<iostream>
using namespace std;

int main()
{
#pragma region 거품정렬
	// 서로 인접한 두 원소를 비교하여 정렬하는 알고리즘입니다.
	//
#pragma endregion

	int array[] = { 5,7,3,1,4 };
	int size = sizeof(array) / sizeof(array[0]);
	//cout << size;
	for (int i = 0; i < size-1; i++)// array[]의 배열 수-1 만큼 반복
	{
		for (int j = 0; j < (size - i)-1; j++)//큰 값이 오른쪽으로 갈때까지 반복
		{
			if (array[j] > array[j+1])//크기비교하기
			{
			//int x = array[j];
			//array[j] = array[j + 1];
			//array[j + 1] = x;
				//std::swap(array[j], array[j] + 1);
				std::swap(array[j], array[j + 1]);
			}
		}
	}
	for (int i = 0; i < size ; i++)
	{
		cout << array[i] << endl;
	}
}