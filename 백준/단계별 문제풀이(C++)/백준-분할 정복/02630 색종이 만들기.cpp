#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

int arr[129][129];
int blue = 0;
int white = 0;

void solve(int y, int x, int size)
{
	int color = arr[y][x];

	for (int i = y; i < y + size; i++)
	{
		for (int j = x; j < x + size; j++)
		{
			if (arr[i][j] != color)
			{
				solve(y, x , size / 2);
				solve(y, x + (size / 2), size / 2);
				solve(y + (size / 2), x, size / 2);
				solve(y + (size / 2), x + (size / 2), size / 2);
				return;
			}
		}
	}

	if (color == 1)
	{
		blue++;
	}
	else
	{
		white++;
	}

}

int main()
{
	FAST;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}

	solve(0, 0, N);
	cout << white << '\n';
	cout << blue;

	return 0;

}