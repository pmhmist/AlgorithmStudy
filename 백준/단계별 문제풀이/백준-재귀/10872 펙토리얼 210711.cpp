#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

int fac(int num)
{
	if (num == 0)
	{
		return 1;
	}
	if (num == 1)
	{
		return 1;
	}
	else
	{
		return num * fac(num - 1);
	}
}
int main()
{
	FAST;
	int N;
	cin >> N;
	cout << fac(N);

	return 0;
}


