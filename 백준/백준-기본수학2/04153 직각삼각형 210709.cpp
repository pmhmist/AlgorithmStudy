#include <iostream>
#include<algorithm>
#include <cmath>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);
int main()
{
	FAST;
	int a, b, c;
	while (1)
	{
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0)
		{
			break;
		}
		if (a > b && a > c)
		{
			if (a * a == b * b + c * c)
			{
				cout << "right" << '\n';
			}
			else
			{
				cout << "wrong" << '\n';
			}
		}
		else if (b > a && b > c)
		{
			if (b * b == a * a + c * c)
			{
				cout << "right" << '\n';
			}
			else
			{
				cout << "wrong" << '\n';
			}
		}
		else if (c > a && c > b)
		{
			if (c * c == b * b + a * a)
			{
				cout << "right" << '\n';
			}
			else
			{
				cout << "wrong" << '\n';
			}
		}
		else
		{
			cout << "wrong" << '\n';
		}


	}

	return 0;
}


