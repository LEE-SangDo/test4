#include <stdio.h>


struct Interval {    //입력받은 직선을 저장하는 구조체
	int start;
	int end;
};

struct Interval overlap(struct Interval intval1, struct Interval intval2)
	// 겹치는 구역 구하는 함수
{
	struct Interval result;   // 겹치는 구역을 저장할 구조체

	if (intval1.start <= intval2.start && intval2.start < intval1.end)
	{
		if (intval2.end > intval1.end)
		{
			result.start = intval2.start;
			result.end = intval1.start;
		}
		else if (intval2.end <= intval1.end)
		{
			result.start = intval2.start;
			result.end = intval2.end;
		}
	}

	if (intval2.start <= intval1.start && intval1.start < intval2.end)
	{
		if (intval1.end > intval1.end)
		{
			result.start = intval1.start;
			result.end = intval2.end;
		}
		else if (intval1.end <= intval2.end)
		{
			result.start = intval1.start;
			result.end = intval1.end;
		}
	}

	return result;
}



int main()
{
	struct Interval intval1, intval2;

	scanf_s("%d%d", &intval1.start, &intval1.end);
	scanf_s("%d%d", &intval2.start, &intval2.end);

	struct Interval result = overlap(intval1, intval2);

	int length;

	length = result.end - result.start;



	printf("%d\n", length);

	return 0;
}