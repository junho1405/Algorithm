#include<iostream>
using namespace std;

void counting(int count[], int size)
{
	// count의 모든 배열을 불러오고 그 배열들 간의 비교 카운팅
	// 필요한거 list에 있는 배열종류/몇갠지 셀것

	// 힌트
	// 계수의 최대값구하기
	// 계수저장 배열만들기
	// 등장횟수 카운트
	// 결과출력
	//  

	//최대값(완료)
	//배열의 크기를 구하기 위해서임
	//그럼 max를 토대로 새로운 배열을 만든다?
	int max = count[0];
	for (int i = 0; i < size; i++)
	{
		if (count[i] > max) max = count[i];
		int* container = new int[max + 1] {0};
	}
	// 계수저장하기

	for (int i = 0; i < size; i++)
	{
		int j = count[i];//배열의종류 불러옴

	}
}
int main()
{
#pragma region 계수정렬
	// 데이터의 값을 비교하지 않고 각 원소에 데이터가 몇 개
	// 있는 지 개수를 세어 지정한 다음 정렬하는 알고리즘입니다.
	// 

#pragma endregion

	int list[] = { 1,1,2,2,2,3,4,5 };
	int size = sizeof(list) / sizeof(list[0]);
	counting(list, size);

	return 0;
}