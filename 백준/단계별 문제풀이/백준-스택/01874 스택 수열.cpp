#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

int arr[100001];

int main()
{
	FAST;
	stack<int> S;
	int n, t, max;
	max = 1;
	string ans;
	ans = "";
	cin >> n;
	while (n--)
	{
		cin >> t;
		if (max <= t)
		{
			for (int i = max; i <= t; i++)
			{
				S.push(i);
				ans += "+";
			}
			S.pop();
			ans += "-";
			max = t+1;
		}
		else
		{
			if (t != S.top())
			{
				cout << "NO" << '\n';
				exit(0);
			}
			else
			{
				S.pop();
				ans += "-";
			}

		}
	}

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << '\n';
	}
	

	return 0;
}