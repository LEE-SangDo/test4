#include<iostream>
using namespace std;

struct location {
	int X1;
	int X2;
};

int main()
{
	struct location L1, L2;
	int diff=0;

	cin >> L1.X1 >> L1.X2;
	cin >> L2.X1 >> L2.X2;

	if (L1.X1 > L1.X2)
		swap(L1.X1, L1.X2);
	if (L2.X1 > L2.X2)
		swap(L2.X1, L2.X2);

	if (L1.X1 <= L2.X1 && L2.X1 < L1.X2)
	{
		if (L2.X2 > L1.X2)
			diff = L1.X2 - L2.X1;
		else if (L2.X2 <= L1.X2)
			diff = L2.X2 - L2.X1;
	}

	if (L2.X1 <= L1.X1 && L1.X1 < L2.X2)
	{
		if (L1.X2 > L2.X2)
			diff = L2.X2 - L1.X1;
		else if (L1.X2 <= L2.X2)
			diff = L1.X2 - L1.X1;
	}


	cout << diff;

	return 0;
}