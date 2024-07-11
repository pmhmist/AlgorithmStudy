#include <iostream>
#include <string>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);


int main()
{
	FAST;
	int N, size, ans;
	size = 0;
	cin >> N;
	int temp = N;
	while (temp != 0)
	{
		temp = temp / 10;
		size++;
	}
	ans = 0;
	for (int i = N - 9 * size; i <= N; i++)
	{
		temp = i;
		ans = i;
		while (temp != 0)
		{
			ans += temp % 10;
			temp = temp / 10;
		}
		if (ans != N)
		{
			ans = 0;
		}
		else
		{
			ans = i;
			break;
		}


	}

	cout << ans;

	return 0;
}


