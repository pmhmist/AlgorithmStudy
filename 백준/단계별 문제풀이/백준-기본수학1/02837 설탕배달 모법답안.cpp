#include <iostream>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

int main()
{
	FAST;
	int N;
	cin >> N;
	int a, b;
	a = N / 5;

	while(1)
	{
		if (a < 0)
		{
			cout << "-1";
			return 0;
		}
		if ((N - (5 * a)) % 3 == 0)
		{
			b = (N - (5 * a)) / 3;
			break;
		}
		a--;
	}

	cout << a + b;
	return 0;
}



