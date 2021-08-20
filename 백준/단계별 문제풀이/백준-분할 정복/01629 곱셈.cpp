#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);


long long solve(int a,int b,int c)
{
	if (b == 0)
	{
		return 1;
	}
	long long temp = solve(a, b / 2, c);
	temp = temp * temp % c;

	if (b % 2 == 0)
	{
		return temp;
	}
	else
	{
		return (temp * a) % c;
	}
}

int main()
{
	FAST;
	int a, b, c;
	cin >> a >> b >> c;
	cout << solve(a, b, c);

	return 0;
}