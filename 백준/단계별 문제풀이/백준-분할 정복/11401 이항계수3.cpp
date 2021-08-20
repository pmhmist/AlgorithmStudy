#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

const long long CAL = 1000000007;

long long solve(long long b, long long p)
{
	if (p == 0)
	{
		return 1;
	}
	long long temp = solve(b, p / 2);
	temp = (temp * temp) % CAL;
	if (p % 2 == 0)
	{
		return temp;
	}
	else
	{
		return (temp * b)% CAL;
	}

}

int main()
{
	FAST;
	long long  N, K, A, B;
	A = 1; B = 1;

	cin >> N >> K;

	for (long long i = N; i >= N - K + 1; i--)
	{
		A = (A * i) % CAL;
	}

	for (long long i = 1; i <= K; i++)
	{
		B = (B * i) % CAL;
	}

	B = solve(B,CAL - 2);

	cout << A * B % CAL;

	return 0;
}