#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);
long long N, B;
long long arr[6][6];
long long temp[6][6];
long long ans[6][6];

void solve(long long a[6][6], long long b[6][6])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			temp[i][j] = 0;
			for (int k = 0; k < N; k++)
			{
				temp[i][j] += (a[i][k] * b[k][j]);
			}
			temp[i][j] = temp[i][j] % 1000;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			a[i][j] = temp[i][j];
		}
	}


}

int main()
{
	FAST;

	cin >> N >> B;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
		ans[i][i] = 1;
	}

	while (B > 0)
	{
		if (B % 2 == 1)
		{
			solve(ans, arr);
		}
		solve(arr, arr);
		B = B/ 2;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << ans[i][j] << " ";
		}
		cout << '\n';
	}

	return 0;
}