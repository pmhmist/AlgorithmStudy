#include <iostream>
#include <cmath>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);
int main()
{
	FAST;
	int N, judge, ans;
	ans = 0;
	judge = 0;
	cin >> N;
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++)
	{
		judge = 0;
		if (arr[i] == 1)
		{
			continue;
		}
		else
		{
			for (int j = 1; j <= arr[i]; j++)
			{
				if (arr[i] % j == 0)
				{
					judge++;
				}

			}

			if (judge == 2)
			{
				ans += 1;
			}

		}
	}

	cout << ans;

	delete[] arr;
	return 0;
}


