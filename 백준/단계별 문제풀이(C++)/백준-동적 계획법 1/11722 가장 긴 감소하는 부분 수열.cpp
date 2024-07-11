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
	int lis = 0;
	int result = 0;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= N; i++)
	{
		dp[i] = 1;
		for (int j = 1; j < i; j++)
		{
			if (arr[i] < arr[j] && dp[i]<dp[j]+1)
			{
				dp[i] = dp[j] + 1;
			}
		}
		result = max(result, dp[i]);

	}

	cout << result;
	return 0;
}