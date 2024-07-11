#include <iostream>
#include <algorithm>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

long long dp[101][11] = { 0, };

int main()
{
	FAST;
	int N;
	long long ans = 0;
	cin >> N;

	for (int i = 1; i <= 9; i++)
	{
		dp[1][i] = 1;
	}
	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (j == 0)
			{
				dp[i][j] = dp[i - 1][1];
			}
			if (j == 9)
			{
				dp[i][j] = dp[i - 1][8];
			}
			else
			{
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) %1000000000;
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		ans += dp[N][i];
	}
	cout << ans % 1000000000;
}