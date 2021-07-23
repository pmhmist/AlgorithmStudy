#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

int main()
{
	FAST;
	int t, size;
	string s;
	cin >> t;
	while (t--)
	{
		cin >> s;
		size = s.size();
		int left = 0;
		int right = size - 1;
		char check = size + 'a' - 1;
		bool flag = true;

		while (check >= 'a' && left <= right)
		{
			if (s[left] == check)
			{
				check--;
				left++;
			}
			else if (s[right] == check)
			{
				check--;
				right--;
			}
			else
			{
				flag = false;
				break;
			}

		}

		if (flag)
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


