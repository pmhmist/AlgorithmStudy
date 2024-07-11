#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);


bool judge(string s1, string s2)
{
	if (s1.length() == s2.length())
	{
		return s1 < s2;
	}
	else
	{
		return s1.length() < s2.length();
	}
}

int main()
{
	FAST;
	vector<string> sam;
	string temp;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		sam.push_back(temp);
	}

	sort(sam.begin(), sam.end(), judge);

	for (int i = 0; i < N; i++)
	{
		if (i >= 1 && sam[i - 1] == sam[i])
		{
			continue;
		}
		cout << sam[i] << '\n';
	}

	return 0;
}