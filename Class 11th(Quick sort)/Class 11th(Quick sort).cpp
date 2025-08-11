#include<iostream>
using namespace std;

void quick_sort(int list[], int start, int end)
{
	if (start >= end) return;
	// pivot 변수의 값을 설정합니다.
	int pivot = start;//0
	// left 변수의 값을 설정합니다.
	int left = start + 1;//1
	// right 변수의 값을 설정합니다.
	int right = end;//7

	// left가 right보다 커질 때 까지 반복합니다.
	while (left <= right)
	{
		while (left <= end && list[pivot] >= list[left])
		{
			left++;// left값을 증가시킵니다.
		}
		while (right > start && list[pivot] <= list[right])
		{
			right--;//right의 값을 감소시킵니다.
		}
		if (right < left)
		{
			std::swap(list[pivot], list[right]);
		}
		else
		{
			std::swap(list[left], list[right]);
		}
	}

	// pivot을 기준으로 나누어진 두 배열에 대해
	// 재귀적으로 쭉 정렬을 호출합니다.
	// 
	quick_sort(list, start, right - 1);
	quick_sort(list, right + 1, end);
}
int main()
{
#pragma region 퀵정렬
	// 기준점을 흭득한 다음 기준점을 기준으로 배열을 나누고 한 쪽에는
	// 기준점보다 작은 값들이 위치하게 한 다음 다른 한 쪽에는 기준점보다 
	// 큰 값들이 위치하도록 정리합니다.
	// 
	// 그리고 나누어진 하위 배열에 대해 재귀적으로 퀵 정렬을 호출하여
	// 모든 배열이 기본 배열이 될 때까지 반복하면서 정렬하는 알고리즘입니다.
	// 
	// pivot값보다 left 값이 작으면 오른쪽으로 이동
	// pivot값보다 right값이 크면 왼쪽으로 이동
	// 
	// left와 right가 엇갈리지 않았다면
	// left<->right(swap)
	// 
	int list[] = { 5,3,8,4,1,6,2,7 };
	int size = sizeof(list) / sizeof(list[0]);
	quick_sort(list, 0, size - 1);

	for (const auto& element : list)
	{
		cout << element << " ";
	}
	return 0;
#pragma endregion
}
