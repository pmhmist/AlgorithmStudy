#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

long long arr[1000001];

int main()
{
	FAST;
	long long N,M;
	long long right = 0;
	long long left = 0;
	long long mid;
	long long check;
	long long ans = 0;

	cin >> N >> M;

	for (long long i = 0; i < N; i++)
	{
		cin >> arr[i];
		right = max(right, arr[i]);
	}

	while (left <= right)
	{
		mid = (left + right) / 2;
		check = 0;
		for (long long i = 0; i < N; i++)
		{
			if (arr[i] > mid)
			{
				check += arr[i] - mid;
			}
		}

		if (check < M)
		{
			right = mid - 1;
		}
		else
		{
			ans = max(ans, mid);
			left = mid + 1;
		}

	}
	
	cout << ans;

	return 0;
}