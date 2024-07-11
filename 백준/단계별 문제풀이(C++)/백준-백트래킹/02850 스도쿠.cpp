#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);
int N = 0;
int sam[9][9];
vector<pair<int, int>> total;
bool judge = false;

bool check(pair<int, int> t)
{
	for (int i = 0; i < 9; i++)
	{
		if (sam[t.first][i] == sam[t.first][t.second] && i != t.second)
		{
			return false;
		}
		if (sam[i][t.second] == sam[t.first][t.second] && i != t.first)
		{
			return false;
		}

	}
	int sqa = (t.first / 3) * 3;
	int sqb = (t.second / 3) * 3;
	for (int i = sqa; i < sqa + 3; i++)
	{
		for (int j = sqb; j < sqb + 3; j++)
		{
			if (sam[i][j] == sam[t.first][t.second])
			{
				if (i != t.first && j != t.second)
				{
					return false;
				}
			}
		}
	}
	return true;
}

void dfs(int idx)
{
	if (idx == N)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << sam[i][j] << " ";
			}
			cout << '\n';
		}
			judge = true;
			return;
	}

	for (int k = 1; k <= 9; k++)
	{
		sam[total[idx].first][total[idx].second] = k;
		if (check(total[idx]))
		{
			dfs(idx+1);
		}
		if (judge)
		{
			return;
		}

	}
	sam[total[idx].first][total[idx].second] = 0;
	return;
}
int main()
{
	FAST;
	pair<int, int> zeroes;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> sam[i][j];
			if (sam[i][j] == 0)
			{
				N++;
				zeroes.first = i;
				zeroes.second = j;
				total.push_back(zeroes);
			}
		}
	}
	
	dfs(0);

	return 0;
}