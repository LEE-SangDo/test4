#include <stdio.h>
#include <stdlib.h>

typedef struct fraction { /* a fraction, numer/denom */
	int numer; /* numerator of fraction */
	int denom; /* denominator of fraction */
} Fraction;

int gcd(int a, int b); // �ִ����� ����� 

Fraction makeFraction(int a, int b);

Fraction add(Fraction x, Fraction y); // �м����� ���ϱ�

void printFraction(Fraction x); // �м� ���

Fraction readfrac(); // �м��� �и�� ���ڸ� �޾Ƶ��̴� ��



int main() {

	Fraction p1 = readfrac();                   //ù��° �м� �Է� , ���

	Fraction p2 = readfrac();                   //�ι�° �м� �Է� , ���

	Fraction p3 = add(p1, p2);                   // �� �м��� ��
	printFraction(p1);
	printf("\n");
	printFraction(p2);
	printf("\n");
	printFraction(p3);              //�� �м��� ���ؼ� ���

}



/* greatest common divisor */
// ����
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
		printf("WARNING! Zero denom!\n"); // �и� 0�� ��� 
		b = 1;
	}
	if (b < 0) { /* put sign in the numerator */ // �и� 1���� ���� ��� 
		a = -a;
		b = -b;
	}
	z.numer = a;
	z.denom = b;
	z = reduce(z); // ���м��� ����� �� 
	return z;
}


/* add fractions x and y, answer in l. terms */
/* �� �м��� ���� ���ϴ� �� */
Fraction add(Fraction x, Fraction y) {
	Fraction z;

	z.numer = (x.numer * y.denom + y.numer * x.denom);
	z.denom = x.denom * y.denom;

	reduce(z); // ���м��� ������ �Ѵ�. 

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
