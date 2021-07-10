#include <iostream>
#include <algorithm>

using namespace std;

#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

int main()
{
	FAST;
	int N,judge;
	cin >> N;
	judge = N;
	N = (N / 3) + 1;
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = 10000;
	}

	int count = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (3 * i + 5 * j == judge)
			{
				arr[count] = i + j;
				count++;
			}

		}
	}
	int min = 20000;
	for (int i = 0; i < N; i++)
	{
		if (min > arr[i])
		{
			min = arr[i];
		}
	}

	if (min == 10000)
	{
		cout << -1;
	}
	else
	{
		cout << min;
	}

	delete[] arr;
	return 0;
}



