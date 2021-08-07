#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

int dp[101][100001] = { 0, };
int W[101];
int V[101];

int main()
{
	FAST;
	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		cin >> W[i] >> V[i];
	}


	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			dp[i][j] = dp[i - 1][j];
			if (j - W[i] >= 0)
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][j - W[i]] + V[i]);
			}
		}
	}
	
	cout << dp[N][K];

	return 0;

}