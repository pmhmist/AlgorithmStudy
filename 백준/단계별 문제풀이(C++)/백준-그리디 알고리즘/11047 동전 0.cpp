#include <iostream>
#include <algorithm>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

int main()
{
	FAST;
	int N, K;
	int count;
	int arr[11];
	cin >> N >> K;
	count = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	for (int i = N; i >= 1; i--)
	{
		if (K == 0)
		{
			break;
		}

		if (K < arr[i])
		{
			continue;
		}
		else
		{
			count += K / arr[i];
			if (arr[i] * (K / arr[i] == K))
			{
				K = 0;
			}
			else
			{
				K = K % arr[i];
			}

		}

	}

	cout << count;

	return 0;

}