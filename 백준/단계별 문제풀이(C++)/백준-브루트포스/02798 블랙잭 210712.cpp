#include <iostream>
#include <cmath>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);


int main()
{
	FAST;
	int N, M, sum;
	cin >> N >> M;
	int* arr = new int[N];
	sum = -1;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < N - 2; i++)
	{
		for (int j = i+1; j < N - 1; j++)
		{
			for (int k = j+1; k < N; k++)
			{
				if (arr[i] + arr[j] + arr[k] <= M && abs(M - sum) > abs(M - arr[i] - arr[j] - arr[k]))
				{
					sum = arr[i] + arr[j] + arr[k];
				}
			}
		}
	}



	cout << sum;
	delete[] arr;
	return 0;
}


