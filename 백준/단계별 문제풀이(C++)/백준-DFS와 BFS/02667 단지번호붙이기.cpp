#include <iostream>
#include <algorithm>
#include<queue>
#include<stack>
#include <vector>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

int arr[26][26] = { 0, };
bool visit[26][26] = { 0, };
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
vector<int> v;
int N;
int temp;
void dfs(int a, int b)
{
	temp++;
	visit[a][b] = true;
	for (int i = 0; i < 4; i++)
	{
		int calx = a + dx[i];
		int caly = b + dy[i];
		if (calx >= N || caly >= N || calx < 0 || caly < 0)
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
	cin >> N;
	string in;

	for (int i = 0; i < N; i++)
	{
		cin >> in;
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = in[j] - '0';
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] == 1 && visit[i][j] == false)
			{
				temp = 0;
				dfs(i, j);
				v.push_back(temp);
			}
		}
	}

	sort(v.begin(), v.end());

	cout << v.size() << '\n';

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << '\n';
	}

	return 0;
}