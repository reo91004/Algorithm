#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 메인 함수
int main()
{
	// n은 연봉, m은 가족 수, result은 나중에 나올 결과
	long long n, result;
	int m;

	double trate; // 소득세율
	long long perdeduc = 1500000; // 인적공제
	long long stadeduc = 1000000; // 표준공제

	scanf("%lld %d", &n, &m);

	if (n < 10000000) // 1천만원 이하 받을 시
		return;
	else
	{
		// 우선 소득세율 계산
		if (n <= 12000000) // 1200만원 이하 시
			trate = 0.06;
		else if (n > 12000000 && n <= 46000000) // 1200만원 초과 ~ 4600만원 이하
			trate = 0.15;
		else if (n > 46000000 && n <= 88000000) // 4600만원 초과 ~ 8800만원 이하
			trate = 0.24;
		else if (n > 88000000)
			trate = 0.33;

		// 과세표준과 소득세율 한꺼번에 계산
		result = (double)(n - (perdeduc * m + stadeduc)) * trate;

		int temp = result / 10.0; // 100의 자리에서 반올림해야 하므로
		temp = temp + 0.5; // 혹시 소수점이 나올 수 있으니 더하고
		result = (long long)temp; // 이를 다시 long long형으로 바꿈
		result *= 10;

		printf("%lld", result);
	}

	return 0;
}