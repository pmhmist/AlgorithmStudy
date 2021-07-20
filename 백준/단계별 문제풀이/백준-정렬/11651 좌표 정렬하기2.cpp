#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

bool judge(pair<int, int> x, pair<int, int> y)
{
	if (x.second == y.second)
	{
		return x.first < y.first;
	}
	else
	{
		return x.second < y.second;
	}
}

int main()
{
	FAST;
	vector<pair <int, int>> arr;
	int a, b;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		arr.push_back(pair<int,int>(a,b));
	}

	sort(arr.begin(), arr.end(), judge);

	for (int i = 0; i < N; i++)
	{
		cout << arr[i].first << " " << arr[i].second << '\n';
	}


	return 0;
}