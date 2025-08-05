#include<iostream>
using namespace std;

int main()
{

#pragma region 삽입정렬
	// 데이터를 하나씩 확인하면서 이미 정렬된 부분과 비교하여
	// 자신의 위치를 찾아 삽입하는 방식으로 정렬하는 알고리즘입니다.
	// 시간 복잡도는 제곱
	//
	int list[] = { 4,9,6,8,1,3 };
	int size = sizeof(list) / sizeof(list[0]);
	int key = 0;
	int j = 0;

	for (int i = 0; i < size; i++)
	{
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--)
		{
			list[j + 1] = list[j];
		}
		list[j + 1] = key;
	}
	for (const auto& element : list)
	{
		cout << element << "\n";
	}

	//for (int i = 1; i < size; i++)//정렬대상선택
	//{
	//	int key = list[i];
	//	for (int j = i - 1; j >= 0 ; j--)//key의 삽입위치 찾기
	//	{
	//		if (list[j] > key)
	//		{
	//			list[j + 1] = list[j];
	//		}
	//		else break;
	//	list[j] = key;
	//	}
	//
	//}
	//for (int i = 0; i < size; i++)
	//{
	//	cout << list[i] << endl;
	//}
#pragma endregion
}