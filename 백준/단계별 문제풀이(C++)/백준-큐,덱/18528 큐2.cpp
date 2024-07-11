#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);


int main()
{
	FAST;
	int N;
	string sam;
	int temp;
	queue <int> q;

	cin >> N;
	while (N--)
	{
		cin >> sam;
		if (sam == "push")
		{
			cin >> temp;
			q.push(temp);
		}
		if (sam == "pop")
		{
			if (q.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << q.front() << '\n';
				q.pop();

			}
		}
		if (sam == "size")
		{
			cout << q.size() << '\n';
		}
		if (sam == "empty")
		{
			if (q.empty())
			{
				cout << 1 << '\n';
			}
			else
			{
				cout << 0 << '\n';
			}
		}
		if (sam == "front")
		{
			if (q.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << q.front() << '\n';
			}
		}

		if (sam == "back")
		{
			if (q.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << q.back() << '\n';
			}
		}

	}
	return 0;
}