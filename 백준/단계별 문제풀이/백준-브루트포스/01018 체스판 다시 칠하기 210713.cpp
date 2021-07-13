#include <iostream>
#include <string>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);


int main()
{
	FAST;
	int M, N, ans;
	ans = 3000;
	cin >> M >> N;
	char** chess = new char* [M];
	for (int i = 0; i < M; i++)
	{
		chess[i] = new char[N];
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> chess[i][j];
		}
	}

	int temp = 0;

	for (int i = 0; i< M-7; i++)
	{
		for (int j = 0; j< N-7; j++)
		{
			temp = 0;
			for (int a = i; a <= i + 7; a++)
			{
				for (int b = j; b <= j + 7; b++)
				{
					if (a % 2 == 0 && b % 2 == 0)
					{
						if (chess[a][b] != 'W')
						{
							temp++;
						}
					}
					if (a % 2 == 1 && b % 2 == 0)
					{
						if (chess[a][b] != 'B')
						{
							temp++;
						}

					}
					if (a % 2 == 0 && b % 2 == 1)
					{
						if (chess[a][b] != 'B')
						{
							temp++;
						}
					}
					if (a % 2 == 1 && b % 2 == 1)
					{
						if (chess[a][b] != 'W')
						{
							temp++;
						}
					}
				}
			}
			if (temp > 64 - temp)
			{
				temp = 64 - temp;
			}
			if (ans > temp)
			{
				ans = temp;
			}
		}
	}


	cout << ans;

	
	for (int i = 0; i < M; i++)
	{
		delete[] chess[i];
	}

	return 0;
}


