#include <iostream>
#include <cmath>
// 모범답인 구글링 해서 익히기
using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);
int main()
{
	FAST;
	int M, N;
	cin >> M >> N;
	int sum = 0;
	int min = 10000;
	int cal = 0;

	for (int i = M; i <= N; i++)
	{
		cal = 0;
		for (int j = 1; j <= i; j++)
		{
			if (i % j == 0)
			{
				cal++;
			}
		}
		if (cal == 2)
		{
			sum += i;
			if (min > i)
			{
				min = i;
			}
		}
	
	}
	if (sum == 0)
	{
		cout << -1;
	}
	else
	{
		cout << sum << '\n' << min << '\n';
	}
	return 0;
}


