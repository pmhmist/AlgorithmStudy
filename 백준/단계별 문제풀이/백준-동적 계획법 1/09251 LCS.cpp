#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);


int dp[1001][1001] = { 0, };

int main()
{
	FAST;
	string a, b;
	int size1, size2;
	int ans = 0;
	cin >> a >> b;
	size1 = a.length();
	size2 = b.length();


	for (int i = 1; i <= size1; i++)
	{
		for (int j = 1; j <= size2; j++)
		{
			if (a[i - 1] == b[j - 1])
			{
				dp[i][j] = dp[i-1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << dp[size1][size2];
	return 0;
}