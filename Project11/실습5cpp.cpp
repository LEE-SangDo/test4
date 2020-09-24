#include <iostream>

using namespace std;

struct f
{
	int mole; // 분자
	int deno; // 분모

};

int gcd(int a, int b);
void reduce(struct f& c);


struct f add(struct f a, struct f b)
{
	struct f c;

	c.mole = (a.mole * b.deno + b.mole * a.deno);
	c.deno = a.deno * b.deno;

	reduce(c);

	return c;
}

void reduce(struct f &c)
{
	int number = gcd(c.mole, c.deno);
	c.mole = c.mole / number;
	c.deno = c.deno / number;

}

int gcd(int a, int b)
{
	if (b != 0) {
		int c = b;
		b = a % b;
		a=gcd(c, b);
	}

	return a;
}

int main()
{
	struct f number,number2;
	struct f p;
	cin >> number.mole >> number.deno;
	cin >> number2.mole >> number2.deno;

	p = add(number, number2);

	cout << p.mole << "/" << p.deno;

	return 0;

}
