#include <iostream>
#include <algorithm>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

string N;
char temp;
int main()
{
	FAST;
	int size;
	cin >> N;
	size = N.size();
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size; j++)
		{
			if (N[i] < N[j])
			{
				temp = N[j];
				N[j] = N[i];
				N[i] = temp;
			}

		}
	}
	cout << N;
	return 0;
}