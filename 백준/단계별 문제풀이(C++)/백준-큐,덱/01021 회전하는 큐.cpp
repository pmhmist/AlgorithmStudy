#include <iostream>
#include <algorithm>
#include <deque>


using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);


int main()
{
	FAST;
	int N, M;
	int temp, temp2, temp3,check, count;
	deque <int> dq;
	count = 0;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		dq.push_back(i);
	}

	while (M--)
	{

		cin >> temp;

		for (int i = 0; i < dq.size(); i++)
		{
			if (dq[i] == temp)
			{
				temp2 = i;
				temp3 = dq.size() - 1 - i;
				break;
			}
		}

		check = min(temp2, temp3);
		if (check == temp2)
		{
			while (1)
			{
				if (dq.front() == temp)
				{
					dq.pop_front();
					break;
				}
				dq.push_back(dq.front());
				dq.pop_front();
				count++;
			}
		}
		else
		{
			while (1)
			{
				if (dq.front() == temp)
				{
					dq.pop_front();
					break;
				}
				dq.push_front(dq.back());
				dq.pop_back();
				count++;
			}
		}
	}
	cout << count;
	return 0;
}