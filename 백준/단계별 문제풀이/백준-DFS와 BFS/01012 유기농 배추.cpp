#include <iostream>
#include <algorithm>
#include<queue>
#include<stack>
#include <vector>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

int arr[52][52];
bool visit[52][52];
int M, N, K;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void reroll()
{
	for (int i = 0; i < 52; i++)
	{
		for (int j = 0; j < 52; j++)
		{
			arr[i][j] = 0;
			visit[i][j] = false;
		}
	}

}

void dfs(int a, int b)
{
	visit[a][b] = true;
	for (int i = 0; i < 4; i++)
	{
		int calx = a + dx[i];
		int caly = b + dy[i];

		if (calx >= N || caly >= M || calx < 0 || caly < 0)
		{
			continue;
		}

		if (arr[calx][caly] == 1 && visit[calx][caly] == false)
		{
			dfs(calx, caly);
		}

	}

}

int main()
{
	FAST;
	int T;
	int a, b;
	cin >> T;
	while (T--)
	{
		cin >> M >> N >> K;
		reroll();
		for (int i = 0; i < K; i++)
		{
			cin >> a >> b;
			arr[b][a] = 1;
		}
		int ans = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (arr[i][j] == 1 && visit[i][j] == false)
				{
					dfs(i, j);
					ans++;
				}

			}
		}
		cout << ans << '\n';

	}

	return 0;
}