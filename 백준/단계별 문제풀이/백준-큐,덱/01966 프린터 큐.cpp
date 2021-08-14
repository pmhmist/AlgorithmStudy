#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);


int main()
{
	FAST;
	int t,n,m, temp;

	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		
		queue<pair<int, int>> q;
		priority_queue<int> pq;

		for (int i = 0; i < n; i++)
		{
			cin >> temp;
			q.push(make_pair (i, temp));
			pq.push(temp);
		}

		int count = 0;

		while (!q.empty())
		{
			if (pq.top() <= q.front().second)
			{
				count++;
				if (q.front().first == m)
				{
					cout << count << '\n';
					break;
				}
				pq.pop();
				q.pop();
			}
			else
			{
				q.push(make_pair(q.front().first, q.front().second));
				q.pop();
			}
		}

	}
	return 0;
}