#include <iostream>
#include <algorithm>
#include <deque>


using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);


int main()
{
	FAST;
	int N, temp;
	string sam;
	deque <int> dq;

	cin >> N;

	while (N--)
	{
		cin >> sam;
		if (sam == "push_front")
		{
			cin >> temp;
			dq.push_front(temp);
		}
		if (sam == "push_back")
		{
			cin >> temp;
			dq.push_back(temp);
		}
		if (sam == "pop_front")
		{
			if (dq.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		if (sam == "pop_back")
		{
			if (dq.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}
		if (sam == "size")
		{
			cout << dq.size() << '\n';
		}
		if (sam == "empty")
		{
			if (dq.empty())
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
			if (dq.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << dq.front() << '\n';
			}
		}
		if (sam == "back")
		{
			if (dq.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << dq.back() << '\n';
			}
		}
	}
	return 0;
}