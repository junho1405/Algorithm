#include<iostream>
using namespace std;

int main()
{
#pragma region 선택정렬
	// 주어진 리스트 중에 최소값을 찾은 다음 특정한 위치에서
	// 결과를 교체하는 방식으로 정렬하는 알고리즘입니다.
	//

	//min에 일단 박고 min보다 작으면 그 값이 min이된다.
	//array[i] = min<<이거 쓰면될듯
	int array[] = { 6,4,8,9,0,2,7,3,1 };
	int size = sizeof(array) / sizeof(array[0]);

	for (int i = 0; i < size - 1; i++)
	{
		int min = array[i];
		int index = i;
		for (int j = i + 1; j < size; j++)
		{
			if (min > array[j])
			{
				min = array[j];
				index = j;
			}
		}
		std::swap(array[i], array[index]);
	}
	//for (int i = 0; i < size-1; i++)
	//{
	//	int min =i;//일단 가장작은 배애ㅕㄹ을 array[i(0)]으로 스타팅
	//	for (int j = i+1; j < size; j++)//array[j]는 array[i+1]이다.
	//	{
	//		if (array[j] < array[min])//만약 array[i]가 array[j]보다 크다면
	//		{
	//			min = j; //최소값은 array[j]가 된다.
	//			//이렇게하면 min은 최소값의 배열 순서를 저장한채로 for문을 나감
	//		}
	//	}
	//	std::swap(array[i], array[min]);//가장 작은 수의 값을 가진 min을 array[min]으로 바꿔 array[i]와 바꿈
	//
	//}
#pragma endregion
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << endl;
	}
}