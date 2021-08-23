#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

int arr[100001];


int main()
{
	FAST;
	int N,M, temp;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> temp;
		if (binary_search(arr, arr + N, temp))
		{
			cout << 1 << '\n';
		}
		else
		{
			cout << 0 << '\n';
		}
		
	}



	return 0;
}