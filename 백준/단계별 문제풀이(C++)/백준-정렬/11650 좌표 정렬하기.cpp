#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

bool judge(pair<int, int>a, pair<int, int>b)
{
	if (a.first == b.first)
	{
		return a.second < b.second;
	}
	else
	{
		return a.first < b.first;
	}
}

int main()
{
	FAST;
	int N,a,b;
	vector<pair<int, int>> arr;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		arr.push_back(pair<int, int>(a, b));
	}
	sort(arr.begin(), arr.end(), judge);
	for (int i = 0; i < N; i++)
	{
		cout << arr[i].first << " " << arr[i].second << '\n';
	}


	return 0;
}