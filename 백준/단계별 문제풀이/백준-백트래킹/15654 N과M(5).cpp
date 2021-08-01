#include <iostream>
#include <algorithm>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

int N, M;
int arr[9] = { 0, };
int value[9] = { 0, };
bool visited[9] = { 0, };
void dfs(int com)
{
	if (com == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (visited[i])
		{
			continue;
		}
		else
		{
			visited[i] = true;
			arr[com] = value[i];
			dfs(com + 1);
			visited[i] = false;
		}
	}

}

int main()
{
	FAST;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> value[i];
	}
	sort(value, value + N);
	dfs(0);

	return 0;
}