#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

int dp[1001][1001];

int main()
{
	FAST;
	int N, K;
	cin >> N >> K;
	dp[1][0] = 1;
	dp[1][1] = 1;

	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j <= K; j++)
		{
			if (j == 0 || j == i)
			{
				dp[i][j] = 1;
			}
			else
			{
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
			}
			
		}

	}

	cout << dp[N][K];

	return 0;
}