#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

int arr[101];

int gcd(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return gcd(b, a % b);
	}
}

int main()
{
	FAST;
	int N;
	int temp;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i < N; i++)
	{
		temp = gcd(arr[0], arr[i]);
		cout << arr[0] /temp << "/" << arr[i]/temp << '\n';
	}
	
	return 0;
}