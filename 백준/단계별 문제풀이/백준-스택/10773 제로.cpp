#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

int main()
{
	FAST;
	int K, n;
	long long sum = 0;

	stack<int> s;

	cin >> K;
	while (K--)
	{
		cin >> n;
		if (n != 0)
		{
			s.push(n);
		}
		else
		{
			s.pop();
		}

	}

	while (!s.empty())
	{
		sum += s.top();
		s.pop();
	}
	
	cout << sum;

	return 0;
}