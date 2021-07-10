#include <iostream>
#include <cmath>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);
int main()
{
	FAST;
	int n = 1;
	int count = 0;
	int root;
	bool judge;
	while (1)
	{
		count = 0;
		cin >> n;
		if (n == 0)
		{
			break;
		}
		for (int i = n + 1; i <= 2 * n; i++)
		{
			judge = true;
			root = (int)sqrt((double)i);
			if (i == 2 || i == 3)
			{
				count++;
			}
			else
			{
				for (int j = 2; j <= root; j++)
				{
					if (i % j == 0)
					{
						judge = false;
						break;
					}
				}
				if (judge == true)
				{
					count++;
				}
			}
		}

		cout << count << '\n';
	}
	return 0;
}


