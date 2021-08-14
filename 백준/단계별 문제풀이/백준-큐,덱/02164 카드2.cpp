#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);


int main()
{
	FAST;
	int N;
	queue <int> q;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		q.push(i);
	}

	while (1)
	{
		if (q.size() == 1)
		{
			break;
		}
		q.pop();
		q.push(q.front());
		q.pop();
		
	}

	cout << q.front();

	return 0;
}