#include <iostream>
#include <cmath>
// ������� ���۸� �ؼ� ������
using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);
int main()
{
	FAST;
	int N;
	cin >> N;
	if (N > 1)
	{
		for (int i = 2; i <= N; i++)
		{
			while (N % i == 0)
			{
				N = N / i;
				cout << i << '\n';
			}
			if (N == 1)
			{
				break;
			}
		}
	}
	return 0;
}


