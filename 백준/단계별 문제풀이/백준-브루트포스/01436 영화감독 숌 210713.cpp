#include <iostream>
#include <string>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);


int main()
{
	FAST;
	int N;
	string sample = "666";
	cin >> N;

	int start = 665;

	for (int i = 0; i < N; i++)
	{
		while (1)
		{
			start++;
			if (to_string(start).find(sample) != string::npos)
			{
				break;
			}
		}
	}
	
	cout << start;
	return 0;
}


