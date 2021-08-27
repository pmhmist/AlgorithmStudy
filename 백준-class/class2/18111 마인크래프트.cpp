#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

int arr[503][503];
int main()
{
	FAST;
	int N, M, B, time, height;
	time = 1000000000;
	height = 0;
	cin >> N >> M >> B;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int h = 0; h <= 256; h++)
	{
		int temptime = 0;
		int count = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (h > arr[i][j])
				{
					temptime = temptime + (h - arr[i][j]);
					count += (h - arr[i][j]);
				}
				else if (h < arr[i][j])
				{
					temptime = temptime + (2 * (arr[i][j] - h));
					count -= (arr[i][j] - h);
				}
			}
		}

		if (count <= B)
		{
			if (time > temptime)
			{
				time = min(time, temptime);
				height = h;
			}
			if (time == temptime)
			{
				height = max(h, height);
			}
		}
	}

	
	
	cout << time << " " << height;
	return 0;
}