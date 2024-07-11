#include <iostream>
#include<algorithm>
#include <cmath>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);
int main()
{
	FAST;
	int x, y, w, h;
	int arr[4];
	cin >> x >> y >> w >> h;
	arr[0] = x;
	arr[1] = y;
	arr[2] = w - x;
	arr[3] = h - y;
	cout << *min_element(arr, arr + 4) << '\n';

	return 0;
}


