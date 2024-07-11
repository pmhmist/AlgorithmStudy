#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);



int main()
{
	FAST;
	string sam;
	string temp = "";
	int size;
	int ans = 0;

	cin >> sam;
	size = sam.size();

	bool judge = false;

	for (int i = 0; i <= size; i++)
	{
		if (sam[i] == '+' || sam[i] == '-' || i == size)
		{
			if (judge)
			{
				ans -= stoi(temp);
				temp = "";
			}
			else
			{
				ans += stoi(temp);
				temp = "";
			}

			if (sam[i] == '-')
			{
				judge = true;
			}

		}
		else
		{
			temp += sam[i];
		}
	}

	cout << ans;

	return 0;

}