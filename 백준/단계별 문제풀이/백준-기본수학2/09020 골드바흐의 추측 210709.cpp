#include <iostream>
#include <cmath>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);
int main()
{
	FAST;
	int T, n, root, min, max, difference;
	int arr[10001];
	cin >> T;

	for (int i = 1; i <= 10000; i++)
	{
		arr[i] = i;
	}
	arr[1] = 0;
	root = (int)sqrt((double)10001);
	for (int i = 2; i <= root; i++)
	{
		if (arr[i] != 0)
		{
			for (int j = i + i; j < 10001; j += i)
			{
				arr[j] = 0;
			}
		}
	}

	for (int i = 0; i < T; i++)
	{
		min = 0;
		max = 0;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			if (arr[i] != 0)
			{
				if (arr[n - i] != 0 && i <= n - i)
				{
					min = arr[i];
					max = arr[n - i];
				}

			}

		}
		cout << min << " " << max << '\n';
	}
	return 0;
}


