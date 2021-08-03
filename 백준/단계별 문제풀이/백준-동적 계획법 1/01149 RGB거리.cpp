#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

int arr[1000][3] = { 0, };
int cost[3];


int main()
{
	FAST;
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> cost[0] >> cost[1] >> cost[2];
		arr[i][0] = min(arr[i - 1][1], arr[i - 1][2]) + cost[0];
		arr[i][1] = min(arr[i - 1][0], arr[i - 1][2]) + cost[1];
		arr[i][2] = min(arr[i - 1][0], arr[i - 1][1]) + cost[2];
	}

	cout << min(arr[N][0], min(arr[N][1], arr[N][2]));
	
	return 0;
}