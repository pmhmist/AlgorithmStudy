#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);


int main()
{
	FAST;
	int N, M, temp;
	cin >> N;

	vector <int> v;

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> temp;

		auto up = upper_bound(v.begin(), v.end(), temp);
		auto down = lower_bound(v.begin(), v.end(), temp);
		cout << up - down << " ";
	}
	return 0;
}