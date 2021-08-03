#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

long long arr[101] = { 1,1,1,2,2,3,4,5,7,9, };

long long solve(int cal)
{
	if (cal <= 10)
	{
		return arr[cal - 1];
	}
	else
	{
		for (int i = 11; i <= cal; i++)
		{
			arr[i-1] = arr[i - 2] + arr[i - 6];
		}
		return arr[cal-1];

	}

}
int main()
{
	FAST;
	int T, N;
	cin >> T;
	while (T--)
	{
		cin >> N;
		cout << solve(N) << '\n';
	}

	return 0;
}