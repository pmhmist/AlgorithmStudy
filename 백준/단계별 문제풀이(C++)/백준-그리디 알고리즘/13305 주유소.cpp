#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

long long dis[100001];
long long stop[100001];
long long ans = 0;
long long price = 2000000000;

int main()
{
	FAST;
	int N;
	cin >> N;

	for (int i = 0; i < N - 1; i++)
	{
		cin >> dis[i];
	}

	for (int i = 0; i < N; i++)
	{
		cin >> stop[i];
		price = min(price, stop[i]);
		if (i != N - 1)
		{
			ans += price * dis[i];
		}
	}

	cout << ans;
	return 0;

}