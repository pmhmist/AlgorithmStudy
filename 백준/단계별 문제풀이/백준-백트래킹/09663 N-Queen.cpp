#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);
int N;
int answer = 0;
int arr[15] = { 30, };
bool visited[15] = { 0, };

bool test(int idx)
{
	for (int i = 0; i < idx; i++)
	{
		if (abs(idx - i) == abs(arr[idx] - arr[i]))
		{
			return false;
		}
	}
	return true;
}
void dfs(int idx)
{
	if (idx == N)
	{
		answer++;
	}
	for (int i = 0; i < N; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			arr[idx] = i;
			if (test(idx))
			{
				dfs(idx + 1);
			}
			visited[i] = false;
		}
	}

}

int main()
{
	FAST;
	cin >> N;
	dfs(0);
	cout << answer;

	return 0;
}