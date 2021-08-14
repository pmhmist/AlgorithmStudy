#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);


int main()
{
	FAST;
	queue <int> q;
	queue <int> ans;
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		q.push(i);
	}

	while (1)
	{
		if (q.empty())
		{
			break;
		}
		for (int i = 0; i < K - 1 ; i++)
		{
			q.push(q.front());
			q.pop();
		}
		ans.push(q.front());
		q.pop();

	}

	cout << "<";
	while (1)
	{
		if (ans.size() == 1)
		{
			cout << ans.front() << ">";
			break;
		}
		else
		{
			cout << ans.front() << ", ";
			ans.pop();
		}
		
	}


	return 0;
}