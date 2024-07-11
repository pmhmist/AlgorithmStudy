#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);
int num;
int arr[12];
int cal[4];
int ansmin = 100000001;
int ansmax = -100000001;



void dfs(int op, int idx)
{
	if (idx == num)
	{
		if (ansmax < op)
		{
			ansmax = op;
		}
		if (ansmin > op)
		{
			ansmin = op;
		}
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (cal[i] > 0)
		{
			cal[i]--;
			if (i == 0)
			{
				dfs(op + arr[idx], idx + 1);
			}
			if (i == 1)
			{
				dfs(op - arr[idx], idx + 1);
			}
			if (i == 2)
			{
				dfs(op * arr[idx], idx + 1);
			}
			if (i == 3)
			{
				dfs(op / arr[idx], idx + 1);
			}
			cal[i]++;
		}
	}
}

int main()
{
	FAST;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < 4; i++)
	{
		cin >> cal[i];
	}

	dfs(arr[0], 1);

	cout << ansmax << '\n';
	cout << ansmin;


	return 0;
}