#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);


int main()
{
	FAST;
	vector<int> v;
	int n,num;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> num;
		auto a = lower_bound(v.begin(), v.end(), num);
		if (a != v.end())
		{
			*a = num;
		}
		else
		{
			v.push_back(num);
		}
	}

	cout << v.size();
	return 0;
}