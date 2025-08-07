#include<iostream>
using namespace std;

//int find(int list[], int target, int left , int right)
//{
//	int mid = (left + right) / 2;
//	
//		cout << "target은" << target << "입니다." << endl;
//		cout << "중간배열은" << mid << "입니다." << endl;
//		cout << "중간배열의 값은" << list[mid] << "입니다." << endl;
//		if (left > right)
//		{
//			cout << "찾는 숫자없음" << endl;
//		}
//	if(list[mid] == target)
//	{
//		cout << "찾았습니다. target은" << target << "입니다." << endl;
//	}
//	if (list[mid] < target)
//	{
//		cout << "target이 더 큽니다. 배열을 반으로 나눠 오른쪽으로 갑니다.\n 재귀함수 작동 \n\n";
//		return find(list, target, right,mid-1);
//
//	}
//	if (list[mid] > target)
//	{
//		cout << "target이 더 작습니다. 배열을 반으로 나눠 왼쪽으로 갑니다.\n 재귀함수 작동 \n\n";
//		return find(list, target, mid-1, left);
//	}
//	else
//	{
//		cout << "해당하는 숫자"<< target <<"는 없습니다." << endl;
//	}
//	return 0;
//}

void search(int list[], int key, int size)
{
	int left = 0;
	int right = size - 1;
	while (left <= right)
	{
		int pivot = (left + right) / 2;
		if (list[pivot] == key)
		{
			cout << "key found :" << list[pivot] << endl;

			return;
		}
		else if(list[pivot]>key)
		{
			right = pivot;
		}
		else
		{
			left = pivot;
		}
	}
}
int main()
{
#pragma region  이분탐색
	//탐색 범위를 반으로 나누어 찾는 값을 포함하는 범위를
	// 좁혀나가는 방식으로 동작하는 알고리즘입니다.
	// 
	// 오름차순 정렬로 한 상태로 할것
	// 1. 찾으려는 배열의 중간값을 구한다.
	// 2. 중간값이 찾으려는 수보다 크냐 작냐로 범위를 축소
	// 3. 반복해서 값 찾기
	// 4. 만약 값이 없으면 없다고 출력하기
	// 
#pragma endregion

	int list[] = { 5,6,11 };
	int size = sizeof(list) / sizeof(list[0]);
	search (list,6, size);
}