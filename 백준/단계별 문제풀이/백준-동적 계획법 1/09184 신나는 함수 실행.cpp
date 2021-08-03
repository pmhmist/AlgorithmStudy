#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

int arr[21][21][21];

int solve(int q,int w, int t)
{

	if (q <= 0 || w <= 0 || t <= 0)
	{
		return 1;
	}
	if (q > 20 || w> 20 || t > 20)
	{
		return solve(20, 20, 20);
	}
	else
	{
		if (arr[q][w][t] != 999999999)
		{
			return arr[q][w][t];
		}
		arr[q][w][t] = solve(q - 1, w, t) + solve(q - 1, w - 1, t) + solve(q - 1, w, t - 1) - solve(q - 1, w - 1, t - 1);
		return arr[q][w][t];
	}

}


int main()
{
	FAST;
	int a, b, c;
	while (1)
	{
		cin >> a >> b >> c;
		for (int i = 0; i < 21; i++)
		{
			for (int j = 0; j < 21; j++)
			{
				for (int k = 0; k < 21; k++)
				{
					arr[i][j][k] = 999999999;
				}
			}
		}
		if (a ==  -1 && b == -1 && c == -1)
		{
			break;
		}
		else
		{
			cout << "w(" << a << ", " << b << ", " << c << ") = " << solve(a, b, c) << '\n';
		}
	}

	return 0;
}