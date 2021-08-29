#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);


int main()
{
	FAST;
	int N, k, ans;
	ans = -2;
	cin >> N >> k;

	int left = 1; int right = k;

	while (left <= right)
	{
		int check = 0;
		int mid = (left + right) / 2;
		for (int i = 1; i <= N; i++)
		{
			check += min(mid / i, N);
		}
		if (check < k)
		{
			left = mid + 1;
		}
		else
		{
			ans = mid;
			right = mid - 1;
		}
	}


	cout << ans << '\n';
	return 0;
}