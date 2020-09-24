#include <iostream>
using namespace std;

int gcd(int a, int b);

int main()
{
	int a, b, tmp;
	while (1) {
		cin >> a >> b;

		if (b > a) {
			tmp = a;
			a = b;
			b = tmp;
		}

		cout << gcd(a,b) << endl;
	}
	return 0;
}

int gcd(int a, int b) {
	if (b != 0) {
		int c = b;
		b = a % b;
		a=gcd(c, b);
	}

	return a;
}