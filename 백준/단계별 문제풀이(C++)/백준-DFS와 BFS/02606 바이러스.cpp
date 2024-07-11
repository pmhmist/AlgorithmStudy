#include <iostream>
#include <algorithm>
#include<queue>
#include<stack>
#include <functional>
#include <vector>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

int arr[103][103] = { 0, };
bool visit[103] = { 0, };
int N, M;
int ans = 0;

void dfs(int idx)
{
	visit[idx] = true;
	for (int i = 1; i <= N; i++)
	{
		if (arr[idx][i] == 1 && visit[i] == false)
		{
			visit[i] = true;
			if (i != 1)
			{
				ans++;
			}
			dfs(i);
		}
	}

}

int main()
{
	FAST;
	cin >> N >> M;
	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	dfs(1);

	cout << ans << '\n';

	return 0;
}