#include <iostream>
#include<algorithm>
#include <cmath>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);
int main()
{
	FAST;
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	if (a == c)
	{
		cout << e << " ";
	}
	else if (c == e)
	{
		cout << a << " ";
	}
	else
	{
		cout << c << " ";
	}

	if (b == d)
	{
		cout << f;
	}
	else if (d == f)
	{
		cout << b;
	}
	else
	{
		cout << d;
	}
	
	return 0;
}


