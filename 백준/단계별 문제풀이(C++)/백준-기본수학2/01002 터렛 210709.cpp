#include <iostream>
#include <cmath>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);
int main()
{
	FAST;
	int T;
	double x1, y1, r1, x2, y2, r2;
	double distance;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
		if (distance == 0 && r1 == r2)
		{
			cout << "-1" << endl;
		}
		else if (abs(r1 + r2) == distance || abs(r1 - r2) == distance)
		{
			cout << "1" << endl;
		}
		else if (abs(r1 - r2) < distance && abs(r1+r2) > distance)
		{
			cout << "2" << endl;
		}
		else
		{
			cout << "0" << endl;
		}

	}
	return 0;
}


