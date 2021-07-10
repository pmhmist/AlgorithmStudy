#include <iostream>


using namespace std;

#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

int main()
{
	FAST;
	int T, k, n;
	cin >> T;
	int arr[15][15] = { 0 };
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (i == 0)
			{
				arr[i][j] = j+1;
			}
			else
			{
				for (int t = 0; t <= j; t++)
				{
					arr[i][j] += arr[i-1][t];
				}
			}
		}

	}

	for (int i = 0; i < T; i++)
	{
		cin >> k >> n;
		cout << arr[k][n-1] << '\n';
	}

	

	return 0;
}



