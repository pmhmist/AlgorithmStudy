#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

int dp[31][31];

int main()
{
	FAST;
	int T, n;
	string s1, s2;
	cin >> T;

	dp[1][0] = 1;
	dp[1][1] = 1;

	while (T--)
	{
		cin >> n;
		map<string, int> m;
		for (int i = 0; i < n; i++)
		{
			cin >> s1 >> s2;
			if (m.find(s2) == m.end())
			{
				m.insert({ s2, 1 });
			}
			else
			{
				m[s2]++;
			}
		}

		int ans = 1;
		for (auto i : m)
		{
			ans *= i.second + 1;
		}
		ans -= 1;
		cout << ans << '\n';
	}

	
	return 0;
}