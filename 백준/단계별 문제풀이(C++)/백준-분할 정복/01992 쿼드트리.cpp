#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

int arr[65][65];

void solve(int a, int b, int size)
{
	if (size == 1)
	{
		cout << arr[a][b];
		return;
	}
	bool zero, one;
	zero = true;
	one = true;
	for (int i = a; i < a + size; i++)
	{
		for (int j = b; j < b + size; j++)
		{
			if (arr[i][j] == 0)
			{
				one = false;
			}
			if (arr[i][j] == 1)
			{
				zero = false;
			}
		}
	}

	if (zero)
	{
		cout << 0;
		return;
	}
	if (one)
	{
		cout << 1;
		return;
	}
	cout << "(";
	solve(a, b, size / 2);
	solve(a, b + size / 2, size / 2);
	solve(a + size / 2, b, size / 2);
	solve(a + size / 2, b + size / 2, size / 2);
	cout << ")";
}

int main()
{
	FAST;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = s[j] - '0';
		}
	}
	solve(0, 0, N);

	return 0;
}