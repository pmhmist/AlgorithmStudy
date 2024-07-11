#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

int main()
{
	FAST;
	int N, K;
	int temp1, temp2;

	cin >> N >> K;

	temp1 = 1; temp2 = 1;
	for (int i = 0; i < K; i++)
	{
		temp1 = temp1 * (N - i);
	}
	for (int i = K; i >= 1; i--)
	{
		temp2 = temp2 * i;
	}
	
	cout << temp1 / temp2;

	return 0;
}