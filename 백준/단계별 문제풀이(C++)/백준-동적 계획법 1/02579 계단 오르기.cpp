#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

int score[301] = { 0, };
int stair[301] = { 0, };

int main()
{
	FAST;
	int N;
	int temp1, temp2;

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> stair[i];
	}
	
	for (int i = 1; i <= N; i++)
	{
		if (i == 1)
		{
			score[i] = stair[i];
		}
		if (i == 2)
		{
			score[i] = stair[i - 1] + stair[i];
		}
		else
		{
			temp1 = score[i - 2] + stair[i];
			temp2 = score[i - 3] + stair[i - 1] + stair[i];
			score[i] = max(temp1, temp2);

		}

	}
	
	cout << score[N];


	return 0;
}