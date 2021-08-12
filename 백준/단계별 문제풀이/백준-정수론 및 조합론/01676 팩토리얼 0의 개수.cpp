#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);


int main()
{
	FAST;

	int N;
	int temp, ans;
	cin >> N;
	temp = 0;
	ans = 0;
	for (int i = N; i >= 1; i--)
	{
		if (i % 5 == 0)
		{
			temp = i;
			while (1)
			{
				if (temp % 5 == 0)
				{
					ans += 1;
					temp = temp / 5;
				}
				else
				{
					break;
				}
			}
		}
	}

	cout << ans;

	return 0;
}