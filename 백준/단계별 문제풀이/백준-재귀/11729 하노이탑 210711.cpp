#include <iostream>
#include <cmath>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

void tower(int floor, int start, int end, int mid)
{
	if (floor == 1)
	{
		cout << start << " " << end << '\n';
	}
	else
	{
		tower(floor - 1, start, mid, end);
		cout << start << " " << end << '\n';
		tower(floor - 1, mid, end, start);
	}
	
}

int main()
{
	FAST;
	int K;
	cin >> K;
	cout << (int)pow(2, K) - 1 << '\n';
	tower(K, 1, 3, 2);


	return 0;
}


