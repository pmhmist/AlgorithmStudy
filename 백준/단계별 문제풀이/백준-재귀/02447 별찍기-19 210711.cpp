#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

int star(int num, int x, int y)
{
	if (x / num % 3 == 1 && y / num % 3 == 1)
	{
		cout << " ";
	}
	else
	{
		if (num /3 == 0)
		{
			cout << "*";
		}
		else
		{
			return star(num / 3, x, y);
		}
	}
	return 0;
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
			star(N, i, j);
		}
		cout << '\n';
	}
	
	return 0;
}


