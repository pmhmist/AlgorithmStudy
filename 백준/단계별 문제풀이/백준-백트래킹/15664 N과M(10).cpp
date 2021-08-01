#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);
int N, M;
int arr[9] = { 0, };
vector <int> v;
bool visited[9] = { 0, };
void dfs(int idx, int judge)
{
	if (idx == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	int check = -1;
	for (int i = judge; i < N; i++)
	{
		if (!visited[i] && v[i] != check)
		{
			visited[i] = true;
			arr[idx] = v[i];
			check = arr[idx];
			dfs(idx + 1,i + 1);
			visited[i] = false;
		}
	}

}

int main()
{
	FAST;
	int temp;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(),v.end());
	dfs(0,0);

	return 0;
}