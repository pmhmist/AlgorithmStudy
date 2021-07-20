#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

int main()
{
	FAST;
	int N, temp;
	vector<int> arr;
	vector<int> cal;
	int ans;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		arr.push_back(temp);
	}
	cal = arr;
	sort(cal.begin(), cal.end());
	cal.erase(unique(cal.begin(), cal.end()), cal.end());

	for (int i = 0; i < N; i++)
	{
		ans = lower_bound(cal.begin(), cal.end(), arr[i]) - cal.begin();
		cout << ans << " ";
	}
	return 0;
}