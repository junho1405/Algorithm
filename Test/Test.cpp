#include<iostream>
using namespace std;


int main()
{
#pragma region 시물레이터 알고리즘
	// 현실에 있는 어떤 경우(현상)을 코드화시켜서 해결하는 것
	// 요약 : 현실의 무언가를 시스템 적으로 구현하는 것
    // 만든것 메이플 원하는 템 사는데 걸릴 예상시간
    int meso;     
    int goal;        

    cout << "1주일에 버는 메소 입력 억단위: ";
    cin >> meso;
    cout << "목표 금액 (억단위): ";
    cin >> goal;

    int savings = 0;
    int months = 0;

    while (savings < goal) {
        months++;
        savings += meso;
        cout << months << "주차차: " << savings << "억메소\n";
    }

    cout << "목표 " << goal << "억메소을 모으는데 걸린 시간: "
        << months << "주일\n";
    return 0;



#pragma endregion

}