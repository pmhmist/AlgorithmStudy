#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);
vector <long long> arr{ 0,1,2, };

void solve(int cal)
{
	long long temp = 0;
	for (int i = 3; i <= cal; i++)
	{
		temp = arr[i - 1] + arr[i - 2];
		arr.push_back(temp%15746);
	}

}
int main()
{
	FAST;
	int N;

	cin >> N;
	solve(N);
	cout << arr[N];

	return 0;
}