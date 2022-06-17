#include <iostream>
#include <string>
#include <numeric>
#include <queue>
#include <stack>
#include <vector>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);



int main()
{
	cout << fixed;
	cout.precision(8);

	int T;
	cin >> T;
	while (T--)
	{
		int a, b, cost[1001];
		double ans = 200;
		double temp = 0;
		double mid = 0;

		cin >> a >> b;

		for (int i = 0; i < a; i++)
		{
			cin >> cost[i];
		}

		for (int i = 0; i < a; i++)
		{
			temp = 0;
			for (int j = i; j < a; j++)
			{
				temp += cost[j];
				if (j - i >= b - 1)
				{
					mid = temp / (j - i + 1);
					if (ans > mid)
					{
						ans = mid;
					}

				}

			}

		}

		cout << ans << '\n';

	}





}