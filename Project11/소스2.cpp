#include <stdio.h>
#include <stdlib.h>

typedef struct fraction { /* a fraction, numer/denom */
	int numer; /* numerator of fraction */
	int denom; /* denominator of fraction */
} Fraction;

int gcd(int a, int b); // 최대공약수 만들기 

Fraction makeFraction(int a, int b);

Fraction add(Fraction x, Fraction y); // 분수끼리 더하기

void printFraction(Fraction x); // 분수 출력

Fraction readfrac(); // 분수의 분모와 분자를 받아들이는 것



int main() {

	Fraction p1 = readfrac();                   //첫번째 분수 입력 , 출력

	Fraction p2 = readfrac();                   //두번째 분수 입력 , 출력

	Fraction p3 = add(p1, p2);                   // 두 분수의 합
	printFraction(p1);
	printf("\n");
	printFraction(p2);
	printf("\n");
	printFraction(p3);              //두 분수를 더해서 출력

}



/* greatest common divisor */
// 문제
int gcd(int a, int b) {
	if (b != 0)
	{
		int c = b;
		b = a % b;
		a = gcd(c, b);
	}

	return a;
}

/* reduce z to lowest terms */
Fraction reduce(Fraction x) {
	Fraction z;

	int number = gcd(z.numer, z.denom);
	z.numer = z.numer / number;
	z.denom = z.denom / number;

	return z;
}

/* create fraction a/b, in lowest terms */
Fraction makeFraction(int a, int b) {
	Fraction z;
	if (b == 0) { /* can't have 0 denom */
		printf("WARNING! Zero denom!\n"); // 분모가 0인 경우 
		b = 1;
	}
	if (b < 0) { /* put sign in the numerator */ // 분모가 1보다 작은 경우 
		a = -a;
		b = -b;
	}
	z.numer = a;
	z.denom = b;
	z = reduce(z); // 기약분수로 만드는 것 
	return z;
}


/* add fractions x and y, answer in l. terms */
/* 두 분수의 합을 구하는 것 */
Fraction add(Fraction x, Fraction y) {
	Fraction z;

	z.numer = (x.numer * y.denom + y.numer * x.denom);
	z.denom = x.denom * y.denom;

	reduce(z); // 기약분수로 나오게 한다. 

	return z;

}


/* write the fraction, not necessarily in l.t. */
void printFraction(Fraction x) {
	printf("%d/%d", x.numer, x.denom);
}

/* read two ints, create fraction, reduce */
Fraction readfrac() {
	int a, b;
	scanf_s("%i %i", &a, &b);
	return makeFraction(a, b);
}
