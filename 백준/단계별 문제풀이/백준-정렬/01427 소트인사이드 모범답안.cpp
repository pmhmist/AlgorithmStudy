#include <iostream>
#include <algorithm>

using namespace std;
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);

string N;
bool desc(int a, int b)
{
	return a > b;
}

int main()
{
	FAST;
	cin >> N;
	sort(N.begin(), N.end(), desc);
	cout << N;
	return 0;
}