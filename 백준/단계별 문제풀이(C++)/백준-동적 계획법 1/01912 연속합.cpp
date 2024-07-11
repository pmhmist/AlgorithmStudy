#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

int arr[100001];
int dp[100001] = { -2000000000,0, };
int ans = -2000000000;

int main()
{
	FAST;
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++)
	{
		dp[i] = arr[i];
		dp[i] = max(dp[i - 1] + dp[i], dp[i]);
	}

	for (int i = 1; i <= n; i++)
	{
		ans = max(ans, dp[i]);
	}

	cout << ans;

	return 0;

}