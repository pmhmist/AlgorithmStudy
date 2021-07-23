#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

int main()
{
	FAST;
	int t;
	cin >> t;
	int k, n, m;
	int a[301] = { 0 };
	int b[301] = { 0 };
	int ans[800] = { 0 };
	while (t--)
	{
		cin >> k >> n >> m;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for (int i = 0; i < m; i++)
		{
			cin >> b[i];
		}
		int check = k;
		int tempa = 0;
		int tempb = 0;

		for (int i = 0; i < n + m; i++)
		{

			if (tempa < n)
			{
				if (a[tempa] <= check)
				{
					ans[i] = a[tempa];
					if (ans[i] == 0)
					{
						check++;
					}
					tempa++;
					continue;
				}
			}
			
			if (tempb < m)
			{
				if (b[tempb] <= check)
				{
					ans[i] = b[tempb];
					if (ans[i] == 0)
					{
						check++;
					}
					tempb++;
					continue;
				}

			}
			else
			{
				break;
			}

		}

		if (n == tempa && m == tempb )
		{
			for (int i = 0; i < n + m; i++)
			{
				cout << ans[i] << " ";
			}
		}
		else
		{
			cout << "-1" << '\n';
		}

	}

	return 0;
}


