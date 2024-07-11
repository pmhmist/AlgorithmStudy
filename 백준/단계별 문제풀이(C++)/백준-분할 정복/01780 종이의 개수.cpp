#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

int arr[3000][3000];

int mone = 0;
int zero = 0;
int pone = 0;

void solve(int a, int b, int size)
{
	int check = arr[a][b];

	for (int i = a; i < a + size; i++)
	{
		for (int j = b; j < b + size; j++)
		{
			if (check != arr[i][j])
			{
				solve(a, b, size / 3);
				solve(a, b + size / 3, size / 3);
				solve(a, b + (size / 3) * 2, size / 3);
				solve(a + size / 3, b, size / 3);
				solve(a + size / 3, b + (size / 3), size / 3);
				solve(a + size / 3, b + (size / 3) * 2, size / 3);
				solve(a + (size / 3) * 2, b, size / 3);
				solve(a + (size / 3) * 2, b + (size / 3), size / 3);
				solve(a + (size / 3) * 2, b + (size / 3) * 2, size / 3);
				return;
			}
		}
	}

	if (check == -1)
	{
		mone++;
	}
	if (check == 0)
	{
		zero++;
	}
	if (check == 1)
	{
		pone++;
	}


}

int main()
{
	FAST;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}
	solve(0, 0, N);

	cout << mone << '\n';
	cout << zero << '\n';
	cout << pone << '\n';

	return 0;
}