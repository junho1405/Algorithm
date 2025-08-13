#include <iostream>
using namespace std;

int main()
{
#pragma region 탐욕법
	// 최적의 해를 구하는 데에 사용되는 근사적인 방법으로 여러 경우 중
	// 하나를 검색해야 할 때마다 그 순간에 최적이라고 생각되는 것을 선택해
	// 나가는 방식으로 진행하여 최종적인 해답을 구하는 알고리즘입니다.
	// 
	// 1. 탐욕 선택 속성
	// 각 단계에서 '최적의 선택'을 할 수 했을 때 전체 문제에 대한
	// 최적의 해를 구할 수 있는 경우입니다.
	// 
	// 2.최적 부분 구조
	// 전체 문제의 최적의 해가 '부분 문제의 최적의 해로 구성' 될
	// 수 있는 경우입니다.
	// 
	// 탐욕 알고리즘으로 문제를 해결하는 방법
	// 
	// 1. 선택절차
	// 현제 상태에서의 최적의 해답을 선택합니다.
	// 
	// 2. 적절성 감사(Feasibility Check)
	// 선택된 해가 문제의 조건을 만족하는지 검사합니다.
	// 
	// 3. 해답검사(Solution Check)
	// 원래의 문제가 해결되었는지 검사하고, 해결되지 않았다면
	// 선택절차로 돌아가 위의 과정을 반복합니다.
	// 
	int price = 1370;
	int count = 0;

	while (price >= 10)
	{
		if (price >= 1000)
		{
			price -= 1000;;
			count++;
		}
		else if (price >= 500)
		{
			price -= 500;
			count++;
		}
		else if (price >= 100)
		{
			price -= 100;
			count++;
		}
		else if (price >= 50)
		{
			price -= 50;
			count++;
		}
		else if (price >= 10)
		{
			price -= 10;
			count++;
		}
	}
	//while (price >= 10000)
	//{
	//	price -= 10000;
	//	count++;
	//	count10000++;
	//}
	//while (price >= 5000)
	//{
	//	price -= 5000;
	//	count++;
	//	count5000++;
	//}
	//while(price >= 1000)
	//{
	//	price -= 1000;
	//	count++;
	//	count1000++;
	//}
	//while (price >= 500)
	//{
	//	price -= 500;
	//	count++;
	//	count500++;
	//}
	//while (price >= 100)
	//{
	//	price -= 100;
	//	count++;
	//	count100++;
	//}
	//while (price >= 50)
	//{
	//	price -= 50;
	//	count++;
	//	count50++;
	//}
	//while (price >= 10)
	//{
	//	price -= 10;
	//	count++;
	//	count10++;
	//
	//}
	//cout << "10000원 : " << count10000 << endl;
	//cout << "5000원 : " << count5000 << endl;
	//cout << "1000원 : " << count1000 << endl;
	//cout << "500원 : " << count500 << endl;
	//cout << "100원 : " << count100 << endl;
	//cout << "50원 : " << count50 << endl;
	//cout << "10원 : " << count10 << endl;
	cout << "거슬러준 갯수 : " << count << endl;

#pragma endregion
	return 0;
}