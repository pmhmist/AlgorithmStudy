#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

int dp[31][31];

int main()
{
	FAST;
	int T, N, M;
	cin >> T;

	dp[1][0] = 1;
	dp[1][1] = 1;

	while (T--)
	{
		cin >> N >> M;
		for (int i = 2; i <= M; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				if (j == 0 || j == i)
				{
					dp[i][j] = 1;
				}
				else
				{
					dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
				}
			}
		}
		cout << dp[M][N] << '\n';
		
	}


	return 0;
}