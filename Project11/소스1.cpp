#include <stdio.h>


struct Interval {    //�Է¹��� ������ �����ϴ� ����ü
	int start;
	int end;
};

struct Interval overlap(struct Interval intval1, struct Interval intval2)
	// ��ġ�� ���� ���ϴ� �Լ�
{
	struct Interval result;   // ��ġ�� ������ ������ ����ü

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