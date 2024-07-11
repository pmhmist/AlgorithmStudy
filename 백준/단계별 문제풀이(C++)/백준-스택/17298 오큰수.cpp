#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

int arr[1000001];
int ans[1000001];

int main()
{
	FAST;
	int N;
	stack <int> S;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	for (int i = N-1; i >= 0; i--)
	{
		while (!S.empty() && S.top() <= arr[i])
		{
			S.pop();
		}
		if (S.empty())
		{
			ans[i] = -1;
		}
		else
		{
			ans[i] = S.top();
		}
		
		S.push(arr[i]);
	}

	for (int i = 0; i < N; i++)
	{
		cout << ans[i] << " ";
	}

	return 0;
}