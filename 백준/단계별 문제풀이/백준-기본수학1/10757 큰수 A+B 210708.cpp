#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

int main()
{
	FAST;
	string A, B;
	string ans = "";
	cin >> A >> B;

	int n = A.length() - 1;
	int m = B.length() - 1;

	string tmp = "";
	if (n < m)
	{
		for (int i = 0; i < m - n; i++)
		{
			tmp += "0";
		}
		A = tmp + A;
	}
	else if (n > m)
	{
		for (int i = 0; i < n - m; i++)
		{
			tmp += "0";
		}
		B = tmp + B;
	}

	int len = A.size();
	int x, y, z;
	int carry = 0;

	for (int i = len - 1; i >= 0; i--)
	{
		x = A[i] - '0';
		y = B[i] - '0';
		z = x + y;
		if (carry == 1)
		{
			z += 1;
			carry = 0;
		}

		if (z > 9)
		{
			ans += to_string(z % 10);
			carry = 1;
		}
		else
		{
			ans += to_string(z);
		}

	}

	if (carry == 1)
	{
		ans += "1";
	}

	reverse(ans.begin(), ans.end());
	cout << ans << '\n';

	return 0;
}


