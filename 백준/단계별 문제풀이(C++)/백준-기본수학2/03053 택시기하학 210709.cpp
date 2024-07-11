#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);
int main()
{
	FAST;
	double R,pi;
	pi = M_PI;
	cin >> R;
	cout << fixed;
	cout.precision(6);
	cout << R * R * pi << '\n';
	cout << 2 * R * R << '\n';
	return 0;
}


