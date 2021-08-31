#include <iostream>
#include <algorithm>
#include<queue>
#include <cmath>
#include <vector>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);


int main()
{
	FAST;
	priority_queue<int> q;
	int n,temp;
	cin >> n;
	while (n--)
	{
		cin >> temp;
		if(temp==0)
		{
			if (q.empty())
			{
				cout << 0 << '\n';
			}
			else
			{
				cout << q.top() << '\n';
				q.pop();
			}
		}
		else
		{
			q.push(temp);
		}
	}

	return 0;
}