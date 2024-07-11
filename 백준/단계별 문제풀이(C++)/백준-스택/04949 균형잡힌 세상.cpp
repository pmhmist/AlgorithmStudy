#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

int main()
{
	FAST;
	string sam;
	string temp;
	int size;
	while (1)
	{
		getline(cin, sam);
		if (sam == ".")
		{
			break;
		}
		stack<char> S1;

		size = sam.size();
		bool judge = true;

		for (int i = 0; i < size; i++)
		{
			if (sam[i] == '(')
			{
				S1.push(sam[i]);
			}
			if (sam[i] == '[')
			{
				S1.push(sam[i]);
			}
			if (sam[i] == ')')
			{
				if (S1.empty())
				{
					judge = false;
					break;
				}
				else
				{
					if (S1.top() != '(')
					{
						judge = false;
						break;
					}
					S1.pop();
				}
			}
			if (sam[i] == ']')
			{
				if (S1.empty())
				{
					judge = false;
					break;
				}
				else
				{
					if (S1.top() != '[')
					{
						judge = false;
						break;
					}
					S1.pop();
				}
			}
		}

		if (judge)
		{
			if (S1.empty())
			{
				cout << "yes" << '\n';
			}
			else
			{
				cout << "no" << '\n';
			}
		}
		else
		{
			cout << "no" << '\n';
		}

	}
	return 0;
}