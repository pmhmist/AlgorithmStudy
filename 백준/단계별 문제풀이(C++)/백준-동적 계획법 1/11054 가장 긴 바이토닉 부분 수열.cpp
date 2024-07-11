#include <iostream>
#include <algorithm>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);


int main()
{
	FAST;
	int N;
	int arr[1001];
	int dp[1001];
	int ddp[1001];
	int result = 0;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= N; i++)
	{
		dp[i] = 1;
		for (int j = i - 1; j >= 1; j--)
		{
			if (arr[i] > arr[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	for (int i = N; i >= 1; i--)
	{
		ddp[i] = 1;
		for (int j = i+1; j <= N; j++)
		{
			if (arr[i] > arr[j])
			{
				ddp[i] = max(ddp[i], ddp[j] + 1);
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		result = max(result, dp[i] + ddp[i]-1);
	}

	cout << result;
	return 0;
}