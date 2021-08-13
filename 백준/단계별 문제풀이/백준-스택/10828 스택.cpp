#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

int main()
{
	FAST;
	int N;
	cin >> N;
	stack<int> s;
	int temp;
	string check;
	while (N--)
	{
		cin >> check;
		if (check == "push")
		{
			cin >> temp;
			s.push(temp);
		}
		if (check == "pop")
		{
			if (s.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << s.top() << '\n';
				s.pop();
			}
			
		}
		if (check == "size")
		{
			cout << s.size() << '\n';
		}
		if (check == "empty")
		{
			if (s.empty())
			{
				cout << 1 << '\n';
			}
			else
			{
				cout << 0 << '\n';
			}
		}
		if (check == "top")
		{
			if (s.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << s.top() << '\n';
			}

		}


	}
	return 0;
}