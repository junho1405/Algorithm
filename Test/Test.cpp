#include<iostream>
using namespace std;

struct Vector2 {
    float x, y;
};
int main()
{
#pragma region 시물레이터 알고리즘
	// 현실에 있는 어떤 경우(현상)을 코드화시켜서 해결하는 것
	// 요약 : 현실의 무언가를 시스템 적으로 구현하는 것
    Vector2 position = { 0.0f, 10.0f };   // 초기 위치 (x=0, y=10)
    Vector2 velocity = { 0.0f, 0.0f };    // 초기 속도
    const float gravity = -9.8f;         // 중력 가속도
    const float deltaTime = 0.016f;      // 60 FPS 기준 시간 간격

    for (int i = 0; i < 100; ++i) {     // 100 프레임 시뮬레이션
        velocity.y += gravity * deltaTime;         // 속도에 중력 적용
        position.y += velocity.y * deltaTime;      // 위치 업데이트

        // 땅에 닿으면 위치와 속도 조정
        if (position.y < 0.0f) {
            position.y = 0.0f;
            velocity.y = 0.0f;
        }

        std::cout << "Frame " << i << ": 위치 Y = " << position.y << std::endl;
    }

    return 0;



#pragma endregion

}