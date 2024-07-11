#include <iostream>
#include <algorithm>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);


int arr[50] = { 0,1, };
int solve(int a)
{
	if (a == 0)
	{
		return 0;
	}
	if (a == 1)
	{
		return 1;
	}
	else
	{
		if (arr[a] != 0)
		{
			return arr[a];
		}
		else
		{
			arr[a] = solve(a - 2) + solve(a - 1);
			return arr[a];
		}
	}
}

int main()
{
	FAST;
	int T, temp;
	cin >> T;
	
	while (T--)
	{
		cin >> temp;
		if (temp == 0)
		{
			cout << 1 << " " << 0 << '\n';
		}
		else
		{
			cout << solve(temp - 1) << " " << solve(temp) << '\n';
		}

	}

	return 0;
}