#include <iostream>

int main()
{
#pragma region 시간 복잡도
    // 컴퓨터 프로그램의 입력 값과 연산 수행 시간의
    // 상관 관계를 나타내는 척도입니다.
    //

#pragma region O(1) 상수기반
    // 입력 크기와 상관 없이 일정한 시간 복잡도를
    // 가지는 시간입니다.
    // ex) 배열의 요소 접급(해쉬/벡터 푸쉬백)
    //

#pragma endregion
#pragma region O(log n) 로그 시간
    // 데이터의 크기에 따라 실행 시간이 로그 함수의 형태로 
    // 증가하는 시간 복잡도입니다.
    // ex) 이진탐색
    //
#pragma endregion
#pragma region O(n)선형 시간
    // 입력에 따라 걸리는 시간이 선형적으로 증가되는
    // 시간 복잡도입니다.
    // ex)순차 탐색(for문)
    //
#pragma endregion
#pragma region  O(n²)제곱시간 
    // 입력되는 데이터를 기준으로 n²만큼의 시간이
    // 증가하는 시간 복잡도입니다.
    // ex)중첩 반복문
    //
#pragma endregion
#pragma region 공간복잡도
    // 프로그램 실행과 완료에 얼마나 많은 공간이
    // 필요한 지 나타내는 척도입니다.
    //

#pragma region 고정공간
    // 입력 크기와 상관없이 항상 일정한 크기의
    // 공간을 사용하는 형태입니다.
    // ex)배열
    //
#pragma endregion
#pragma region 가변공간
    // 입력크기에 따라 변화는 메모리 공간입니다.
    // ex)동적배열(활당),재귀 호출 시 사용되는 스택공간입니다.
    //
#pragma endregion
#pragma region 점근적 표기법
    // 상수 개수와 중요하지 않은 항목을 제거하여
    // 표기하는 방법입니다.
    // f(n) = n²+n = 300
    // 높은 수가 낮은 차수에 붙어있어도 n이 무한대로 갈 수
    // 있기 때문에 제일 높은 치수가 됩니다.
    //
#pragma endregion


#pragma endregion



#pragma endregion

    std::cout << "Hello World!\n";
}

