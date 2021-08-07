#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

bool judge(pair<int,int> a, pair<int, int> b)
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}

	return a.second < b.second;
}

int main()
{
	FAST;
	int N;
	vector<pair<int, int>> v;
	pair<int, int> temp;
	int check = 0;
	int ans = 1;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> temp.first >> temp.second;
		v.push_back(temp);
	}

	sort(v.begin(), v.end(),judge);
	check = v[0].second;
	for (int i = 1; i < N; i++)
	{
		if (v[i].first >= check)
		{
			ans++;
			check = v[i].second;
		}
	}

	cout << ans;

	return 0;

}