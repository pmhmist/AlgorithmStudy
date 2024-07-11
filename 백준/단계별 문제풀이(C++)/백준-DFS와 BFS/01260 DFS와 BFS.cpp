#include <iostream>
#include <algorithm>
#include<queue>
#include<stack>
#include <functional>
#include <vector>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

int arr[1003][1003] = { 0, };
bool visit[1003] = { 0, };
int N, M, V;
int a, b;
queue<int> q;

void dfs(int idx)
{
	visit[idx] = true;
	cout << idx << " ";
	for (int i = 1; i <= N; i++)
	{
		if (arr[idx][i] == 1 && visit[i] == false)
		{
			dfs(i);
		}
	}
}

void bfs(int idx)
{
	q.push(idx);
	visit[idx] = true;
	while (!q.empty())
	{
		idx = q.front();
		q.pop();
		cout << idx << " ";
		for (int i = 1; i <= N; i++)
		{
			if (arr[idx][i] == 1 && visit[i] == false)
			{
				visit[i] = true;
				q.push(i);
			}
		}
	
	}
}


int main()
{
	FAST;
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	dfs(V);

	cout << '\n';

	for (int i = 1; i <= N; i++)
	{
		visit[i] = false;
	}

	bfs(V);

	return 0;
}