#include <iostream>
using namespace std;

int DC(int n, int m)
{
	if (m == 0)
		return 1;
	else
		return DC(n, m - 1) * n;
}

int main()
{
	int n, m; // n은 숫자, m은 제곱

	cin >> n>>m;

	cout << DC(n, m);

	return 0;
}