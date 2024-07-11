#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);
int N;
int arr[20][20];
int ans = 999999999;
bool check[20] = {};

void dfs(int idx,int num)
{
	vector<int> start;
	vector<int> link;
	int startsc = 0;
	int linksc = 0;
	if (num == N / 2)
	{
		for (int i = 0; i < N; i++)
		{
			if (check[i])
			{
				start.push_back(i);
			}
			else
			{
				link.push_back(i);
			}

		}

		for (int i = 0; i < N / 2; i++)
		{
			for (int j = 0; j < N / 2; j++)
			{
				startsc += arr[start[i]][start[j]];
				linksc += arr[link[i]][link[j]];
			}
		}

		if (ans > abs(startsc - linksc))
		{
			ans = abs(startsc - linksc);
		}
		return;
	}
	for (int i = idx; i < N; i++)
	{
		if (check[i])
		{
			continue;
		}
		else
		{
			check[i] = true;
			dfs(i,num+1);
			check[i] = false;

		}
	}
}

int main()
{
	FAST;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}
	dfs(0, 0);
	cout << ans;
	return 0;
}