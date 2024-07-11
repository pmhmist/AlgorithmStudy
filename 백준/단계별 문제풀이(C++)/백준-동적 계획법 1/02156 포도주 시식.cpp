#include <iostream>
#include <algorithm>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

int grape[10001];

int main()
{
	FAST;
	int N;
	int dp[10001] = { 0, };
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> grape[i];
		if (i == 1)
		{
			dp[i] = grape[i];
		}
		if (i == 2)
		{
			dp[i] = dp[i - 1] + grape[i];
		}
	}

	for (int i = 3; i <= N; i++)
	{
		dp[i] = max(dp[i - 2] + grape[i], max(dp[i - 3] + grape[i - 1] + grape[i],dp[i-1]));
		
	}

	cout << dp[N] << '\n';
}