#include <stdio.h>
#include <stdlib.h>

typedef struct fraction { /* a fraction, numer/denom */
	int numer; /* numerator of fraction */
	int denom; /* denominator of fraction */
} Fraction;

int gcd(int a, int b);

Fraction makeFraction(int a, int b);

Fraction add(Fraction x, Fraction y);

void printFraction(Fraction x);

Fraction readfrac();



int main() {

	Fraction p1 = readfrac();                   //첫번째 분수 입력 , 출력

	Fraction p2 = readfrac();                   //두번째 분수 입력 , 출력

	Fraction p3 = add(p1, p2);
	printFraction(p1);
	printf("\n");
	printFraction(p2);
	printf("\n");
	printFraction(p3);              //두 분수를 더해서 출력

}



/* greatest common divisor */
int gcd(int a, int b) {
}

/* reduce z to lowest terms */
Fraction reduce(Fraction x) {
	Fraction z;

	return z;
}

/* create fraction a/b, in lowest terms */
Fraction makeFraction(int a, int b) {
	Fraction z;
	if (b == 0) { /* can't have 0 denom */
		printf("WARNING! Zero denom!\n");
		b = 1;
	}
	if (b < 0) { /* put sign in the numerator */
		a = -a;
		b = -b;
	}
	z.numer = a;
	z.denom = b;
	z = reduce(z);
	return z;
}


/* add fractions x and y, answer in l. terms */
Fraction add(Fraction x, Fraction y) {

}


/* write the fraction, not necessarily in l.t. */
void printFraction(Fraction x) {
	printf("%d/%d", x.numer, x.denom);
}

/* read two ints, create fraction, reduce */
Fraction readfrac() {
	int a, b;
	scanf("%i %i", &a, &b);
	return makeFraction(a, b);
}
