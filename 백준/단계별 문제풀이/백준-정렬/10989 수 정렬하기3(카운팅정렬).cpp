#include <iostream>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

int arr[10001] = { 0, };

int main()
{
	FAST;
	int N, temp;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		arr[temp] += 1;

	}
	for (int i = 0; i < 10001; i++)
	{
		if (arr[i] != 0)
		{
			for (int j = 0; j < arr[i]; j++)
			{
				cout << i << '\n';
			}

		}

	}



	return 0;
}