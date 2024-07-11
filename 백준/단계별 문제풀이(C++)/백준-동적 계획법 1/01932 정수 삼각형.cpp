#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);


int arr[501][501] = { 0, };

int main()
{
	FAST;
	int N;
	int temp[501];
	int ans = -1;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> temp[j];
		}

		for (int j = 1; j <= i; j++)
		{
			if (j == 1)
			{
				arr[i][j] = arr[i - 1][j] + temp[j];
			}
			else if (j == i && i != 1)
			{
				arr[i][j] = arr[i - 1][j - 1] + temp[j];
			}
			else
			{
				arr[i][j] = max (arr[i - 1][j - 1] , arr[i - 1][j]) + temp[j];
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (ans < arr[N][i])
		{
			ans = arr[N][i];
		}
	}
	cout << ans;
	
	return 0;
}