#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);


int main()
{
	FAST;
	int N;
	int ans = 0;
	int arr[1001];

	cin >> N;

	for (int i = 0; i <N; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + N);

	for (int j = N; j >= 1; j-- )
	{
		ans += j * arr[N - j];
	}

	cout << ans;

	return 0;

}