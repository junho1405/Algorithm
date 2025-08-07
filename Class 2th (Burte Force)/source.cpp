#include<iostream>

using namespace std;
int main()
{
#pragma region 완전탐색
	// 가능한 모든 경우의 수를 탐색하면서
	// 결과를 찾아내는 알고리즘입니다.
	//

	//배열로 풀것
	int pass[] = { 6,1,7 };
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 10; k++)
			{
				if (pass[0] == i && pass[1] == j && pass[2] == k)
				{
					cout << "password [" << i << "] [" << j << "] [" << k << "]" << endl;
					return 0;
				}
			}
		}
	}

	//for (int i = 0; i < pass_size; i++)
	//{
	//	if (i != pass)
	//	{
	//		cout << i << "는패스워드가 아닙니다." << endl;
	//	}
	//	else 
	//	{
	//		cout << "패스워드는" << i << "였습니다." << endl;
	//		break;
	//	}
	//	//if(i != 617) cout << "패스워드는 " << i << "가 아닙니다." << "시행횟수" << i << endl;
	//	//else (i == 617) cout << "패스워드는 617 이었습니다." << "시행횟수" << i << endl;
	//		//return;
	//}

#pragma endregion

}