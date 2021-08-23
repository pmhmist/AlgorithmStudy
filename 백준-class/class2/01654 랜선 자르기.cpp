#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

long long arr[10001];


int main()
{
	FAST;
	long long K, N;
	cin >> K >> N;
	long long left = 1;
	long long right = 0;
	long long ans = 0;

	for (int i = 0; i < K; i++)
	{
		cin >> arr[i];
		right = max(right, arr[i]);
	}

	while (left <= right)
	{
		long long mid = (left + right) / 2;
		long long count = 0;
		for (int i = 0; i < K; i++)
		{
			count += arr[i] / mid;
		}
		if (count < N)
		{
			right = mid - 1;
		}
		else
		{
			if (ans < mid)
			{
				ans = mid;
			}
			left = mid + 1;
		}

	}

	cout << ans;
	return 0;
}