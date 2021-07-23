#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

int main()
{
	FAST;
	int t;
	int a1, a2, b1, b2, f1, f2;
	int route, check;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> a1 >> a2 >> b1 >> b2 >> f1 >> f2;
		route = abs(b1 - a1) + abs(b2 - a2);
		if (a1 == b1 && a1 == f1)
		{
			int arr[3] = { a2,b2,f2 };
			sort(arr, arr + 3);
			if (arr[1] == f2)
			{
				route += 2;
			}
		}
		else if (a2 == b2 && a2 == f2)
		{
			int arr[3] = { a1,b1,f1 };
			sort(arr, arr + 3);
			if (arr[1] == f1)
			{
				route += 2;
			}
		}

		cout << route << "\n";
	}



	return 0;
}