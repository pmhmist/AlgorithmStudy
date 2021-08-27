#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

int arr[503][503];
int main()
{
	FAST;
	int L;
	string s;
	cin >> L;
	int r = 31;
	long long clar = 1;
	int M = 1234567891;
	long long sum = 0;

	cin >> s;
	for (int i = 0; i < L; i++)
	{
		int temp = s[i] - 'a' + 1;
		sum = (sum + temp * clar) % M;
		clar = (clar * r) % M;
	}
	
	cout << sum;

	return 0;
}