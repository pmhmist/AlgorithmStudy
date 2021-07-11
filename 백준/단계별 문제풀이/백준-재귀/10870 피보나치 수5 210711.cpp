#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

int fib(int num)
{
	if (num == 0)
	{
		return 0;
	}
	if (num == 1 || num == 2)
	{
		return 1;
	}
	return fib(num - 2) + fib(num - 1);

}
int main()
{
	FAST;
	int N;
	cin >> N;
	cout << fib(N);

	return 0;
}


