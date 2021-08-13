#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

int main()
{
	FAST;
	int T;
	string sam;
	cin >> T;
	while (T--)
	{
		stack<char> s;
		cin >> sam;
		bool judge = true;

		for (int i = 0; i < sam.size(); i++)
		{
			if (sam[i] == '(')
			{
				s.push(sam[i]);
			}
			else
			{
				if (s.empty())
				{
					judge = false;
					break;
				}
				else
				{
					s.pop();
				}
			}
		}
		if (!s.empty())
		{
			judge = false;
		}
		if (judge)
		{
			cout << "YES" << '\n';
		}
		else
		{
			cout << "NO" << '\n';
		}

	}

	return 0;
}