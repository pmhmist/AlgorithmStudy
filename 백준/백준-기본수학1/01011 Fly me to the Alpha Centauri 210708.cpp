#include <iostream>
#include <cmath>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);
int main()
{
	FAST;
	long long T;
	long long x, y, distance;
	long long cal = 1;
	long long mid = 0;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> x >> y;
		cal = 1;
		distance = y - x;
		while (1)
		{
			if (cal * cal > distance)
			{
				break;
			}
			cal++;
		}
		cal -= 1;
		distance = distance - cal * cal;
		mid = distance / cal;
		if (mid * cal < distance)
		{
			mid++;
		}
		cout << (2 * cal - 1) + mid << '\n';
	}

	return 0;
}


