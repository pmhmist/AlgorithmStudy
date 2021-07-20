#include <iostream>
#include <algorithm>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

double arr[500001] = { 0, };
int check[8001] = { 0, };

int main()
{
	FAST;
	int N, mid, temp;
	int first, second;
	first = 0;
	second = 0;
	double sum;
	sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		arr[i] = temp;
		sum += arr[i];
		check[temp + 4000]++;
	}
	sort(arr, arr + N);
	mid = (N-1) / 2;
	cout << fixed;
	cout.precision(0);
	cout << sum / N << '\n';
	cout << arr[mid] << '\n';
	for (int i = 0; i < 8001; i++)
	{
		if (check[first] < check[i])
		{
			first = i;
		}
	}
	for (int j = first+1; j < 8001; j++)
	{
		if (check[first] == check[j])
		{
			second = j;
			break;
		}
	}
	if (second == 0)
	{
		cout << first - 4000 << '\n';
	}
	else
	{
		cout << second - 4000 << '\n';
	}

	cout << arr[N - 1] - arr[0] << '\n';

	return 0;
}