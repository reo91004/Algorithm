#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// ���� �Լ�
int main()
{
	// n�� ����, m�� ���� ��, result�� ���߿� ���� ���
	long long n, result;
	int m;

	double trate; // �ҵ漼��
	long long perdeduc = 1500000; // ��������
	long long stadeduc = 1000000; // ǥ�ذ���

	scanf("%lld %d", &n, &m);

	if (n < 10000000) // 1õ���� ���� ���� ��
		return;
	else
	{
		// �켱 �ҵ漼�� ���
		if (n <= 12000000) // 1200���� ���� ��
			trate = 0.06;
		else if (n > 12000000 && n <= 46000000) // 1200���� �ʰ� ~ 4600���� ����
			trate = 0.15;
		else if (n > 46000000 && n <= 88000000) // 4600���� �ʰ� ~ 8800���� ����
			trate = 0.24;
		else if (n > 88000000)
			trate = 0.33;

		// ����ǥ�ذ� �ҵ漼�� �Ѳ����� ���
		result = (double)(n - (perdeduc * m + stadeduc)) * trate;

		int temp = result / 10.0; // 100�� �ڸ����� �ݿø��ؾ� �ϹǷ�
		temp = temp + 0.5; // Ȥ�� �Ҽ����� ���� �� ������ ���ϰ�
		result = (long long)temp; // �̸� �ٽ� long long������ �ٲ�
		result *= 10;

		printf("%lld", result);
	}

	return 0;
}