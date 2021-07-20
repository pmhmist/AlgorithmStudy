#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

bool judge(pair <int, string> a, pair <int, string> b)
{
	return a.first < b.first;
}

int main()
{
	FAST;
	int N;
	int age;
	string name;
	vector<pair <int, string>> sam;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> age >> name;
		sam.push_back(pair <int, string>(age, name));
	}

	stable_sort(sam.begin(), sam.end(), judge);

	for (int i = 0; i < N; i++)
	{
		cout << sam[i].first << " " << sam[i].second << '\n';
	}

	return 0;
}