#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

int arr1[101][101];
int arr2[101][101];
int ans[101][101] = { 0,  };

int main()
{
	FAST;
	int N, M, K;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr1[i][j];
		}
	}

	cin >> M >> K;

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < K; j++)
		{
			cin >> arr2[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
		{
			for (int q = 0; q < M; q++)
			{
				ans[i][j] += arr1[i][q] * arr2[q][j];
			}
			cout << ans[i][j] << " ";
		}
		cout << '\n';
	}

	return 0;
}