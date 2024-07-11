#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

int arr[200001];
int main()
{
	FAST;
	int N, C, ans;
	cin >> N >> C;
	ans = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	int left = 1;
	int right = arr[N - 1] - arr[0];

	while (left <= right)
	{
		int mid = (right + left) / 2;
		int temp = arr[0];
		int count = 1;
		for (int i = 0; i < N; i++)
		{
			if (arr[i] - temp >= mid)
			{
				count++;
				temp = arr[i];
			}
		}
		if (count >= C)
		{
			left = mid + 1;
			ans = max(ans, mid);
		}
		else
		{
			right = mid - 1;
		}
	}

	cout << ans;

	return 0;
}