#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

int gcd(int a, int b)
{
	int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main()
{
	FAST;
	int t, a, b;

	cin >> t;

	while (t--)
	{

		cin >> a >> b;
		cout << a * b / gcd(a, b) << '\n';
	}
	return 0;
}