#include <iostream>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

int N, M;
int arr[9] = { 0, };
bool visited[9] = { 0, };

void dfs(int check)
{
	if (check == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++)
	{
			visited[i] = true;
			arr[check] = i;
			dfs(check + 1);
			visited[i] = false;	
	}


}

int main()
{
	FAST;
	cin >> N >> M;
	dfs(0);
	return 0;
}