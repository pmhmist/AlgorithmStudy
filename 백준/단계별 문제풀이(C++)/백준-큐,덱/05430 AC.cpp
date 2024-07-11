#include <iostream>
#include <algorithm>
#include <deque>
#include <string>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);


int main()
{
	FAST;
	int T,N;
	string sam, arr,temp;

	cin >> T;
	while (T--)
	{
		deque<int> dq;
		bool judge = true;
		int check = 0;
		cin >> sam;
		cin >> N;
		cin >> arr;
		for (int i = 0; i < arr.size(); i++)
		{
			if (arr[i] >= '0' && arr[i] <= '9')
			{
				temp += arr[i];
			}
			else if (arr[i] == ',' || arr[i] == ']')
			{
				if (!temp.empty())
				{
					dq.push_back(stoi(temp));
					temp.clear();
				}
			}
		}

		for (int i = 0; i < sam.size(); i++)
		{
			if (sam[i] == 'R')
			{
				check++;
			}
			else if(sam[i] == 'D')
			{
				if (dq.empty())
				{
					judge = false;
					break;
				}
				
				if (check % 2 == 0)
				{
					dq.pop_front();
				}
				else
				{
					dq.pop_back();
				}
			}
		}

		if (judge == false)
		{
			cout << "error" << '\n';
		}
		else
		{
			cout << "[";
			if (check % 2 == 0)
			{
				while (1)
				{
					if (dq.empty())
					{
						cout << ']' << '\n';
						break;
					}
					cout << dq.front();
					dq.pop_front();
					if (!dq.empty())
					{
						cout << ',';
					}
				}
			}
			else
			{
				while (1)
				{
					if (dq.empty())
					{
						cout << ']' << '\n';
						break;
					}
					cout << dq.back();
					dq.pop_back();
					if (!dq.empty())
					{
						cout << ',';
					}
				}

			}
		}

	}
	return 0;
}