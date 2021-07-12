#include <iostream>
#include <string>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);


int main()
{
	FAST;
	int N;
	int tall[50];
	int weight[50];
	int ans[50];
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> tall[i] >> weight[i];
		ans[i] = 1;

	}

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (tall[i] > tall[j] && weight[i] > weight[j])
			{
				ans[j] += 1;
			}
			else if (tall[i] < tall[j] && weight[i] < weight[j])
			{
				ans[i] += 1;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		cout << ans[i] << " ";
	}

	return 0;
}


