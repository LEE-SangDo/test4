#include <iostream>
using namespace std;

int Add(int n)
{
	if (n == 0)
		return 0;
	else return n % 10 + Add(n / 10);
}

int main(void)
{
	int a;
	cin >> a;
	if (a < 0)
		a = -a;
	cout << Add(a) << endl;
}