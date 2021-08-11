#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

int arr[101];

int gcd(int a, int b)
{
	int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main()
{
	FAST;
	int N;
	vector<int> v;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);

	int check = arr[1] - arr[0];

	for (int i = 2; i < N; i++)
	{
		check = gcd(check, arr[i] - arr[i - 1]);
	}
	for (int i = 2; i * i <= check; i++)
	{
		if (check % i == 0)
		{
			v.push_back(i);
			v.push_back(check / i);
		}
	}
	v.push_back(check);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}



	return 0;
}