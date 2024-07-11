#include <iostream>
#include <algorithm>
#include<queue>
#include <functional>
#include <vector>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

int main()
{
	FAST;
	int N, temp;
	cin >> N;
	priority_queue<int, vector<int>> pq1;
	priority_queue<int, vector<int>, greater<int>> pq2;
	while (N--)
	{
		cin >> temp;

		if (pq1.empty())
		{
			pq1.push(temp);
		}
		else if (pq1.size() == pq2.size())
		{
			pq1.push(temp);
		}
		else
		{
			pq2.push(temp);
		}

		if (!pq1.empty() && !pq2.empty())
		{
			int check1 = pq1.top();
			int check2 = pq2.top();

			if (check1 > check2)
			{
				pq1.pop();
				pq1.push(check2);
				pq2.pop();
				pq2.push(check1);
			}

		}

		cout << pq1.top() << '\n';

	}
	return 0;
}