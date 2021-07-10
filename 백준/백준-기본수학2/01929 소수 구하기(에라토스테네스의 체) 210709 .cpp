#include <iostream>
#include <cmath>
// 모범답인 구글링 해서 익히기
using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);
int main()
{
	FAST;
	int M, N;
	int cal;
	cin >> M >> N;
	for (int i = M; i <= N; i++)
	{
		bool judge = true;
		cal = (int)sqrt((double)i);
		if (i == 1)
		{
			continue;
		}
		else if (i == 2 || i == 3)
		{
			cout << i << '\n';
			continue;
		}
		else
		{
			for (int j = 2; j <= cal; j++)
			{
				if (i % j == 0)
				{
					judge = false;
				}
			}
			if (judge == true)
			{
				cout << i << '\n';
			}
		}

	}
	return 0;
}


