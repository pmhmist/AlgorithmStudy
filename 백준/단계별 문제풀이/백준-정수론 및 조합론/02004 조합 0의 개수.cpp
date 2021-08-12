#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

int solve(long long a, long long b)
{
	int check = 0;
	int temp = b;
	while (1)
	{
		if (a / b == 0)
		{
			break;
		}
		check += a / b;
		b = b * temp;
	}
	return check;
}

int main()
{
	FAST;
	int n, m;
	int temp, temp2, ans;

	cin >> n >> m;

	temp = solve(n, 5) - solve(n - m, 5) - solve(m, 5);
	temp2 = solve(n, 2) - solve(n - m, 2) - solve(m, 2);

	ans = min(temp, temp2);
	cout << ans;
	return 0;
}