#include <iostream>
#include <algorithm>
#include<queue>
#include<stack>
#include <vector>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

int N, M;
string sam;
int arr[103][103];
bool visit[103][103] = { 0, };
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void bfs(int a, int b)
{
	queue <pair<int, int>> q;
	q.push({ a,b });
	visit[a][b] = true;
	while (!q.empty())
	{
		a = q.front().first;
		b = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = a + dx[i];
			int ny = b + dy[i];
			if (nx >= N || nx < 0 || ny >= M || ny < 0)
			{
				continue;
			}
			else
			{
				if (arr[nx][ny] == 1 && visit[nx][ny] == false)
				{
					q.push({ nx,ny });
					visit[nx][ny] = true;
					arr[nx][ny] = arr[a][b] + 1;
				}

			}
		}
	}

}
int main()
{
	FAST;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> sam;
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = sam[j] - '0';
		}
	}

	bfs(0, 0);

	cout << arr[N - 1][M - 1];

	return 0;
}