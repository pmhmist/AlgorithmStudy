#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);
#define MOD 1000000007;

long long n;
long long ans[2][2] = { {1,0},{0,1} };
long long temp[2][2] = { {1,1},{1,0} };
long long check[2][2];

void solve(long long a[2][2], long long b[2][2])
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			long long temp = 0;
			for (int k = 0; k < 2; k++)
			{
				temp += (a[i][k] * b[k][j]) % MOD;
			}
			temp = temp % MOD;
			check[i][j] = temp;
		}
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			a[i][j] = check[i][j];
		}
	}

}

int main()
{
	FAST;
	cin >> n;

	while (n > 0)
	{
		if (n % 2 == 1)
		{
			solve(ans, temp);
		}
		solve(temp, temp);
		n = n / 2;
	}

	cout << ans[0][1] << '\n';
	return 0;
}