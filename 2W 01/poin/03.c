#include<stdio.h>

/*
void sum(int x, int y, int rcsult)
{
	recsult = x + y;

}

int main()
{
	int a = 3;
	int b = 2;
	int c = 0;

	sum(a, b, c);

	printf("%d", c);

	return 0;
}
// �̸��� sum�̰�, �ȿ����� ������ x + y�� ����ϴϱ� ������ ������ �ڵ���
*/

void sum(int x, int y, int *rcsult)
{
	*rcsult = x + y;

}

int main()
{
	int a = 3;
	int b = 2;
	int c = 0;

	sum(a, b, &c); 
	printf("%d", c);

	return 0;
}
