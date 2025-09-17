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
// 이름은 sum이고, 안에서는 무조건 x + y만 계산하니까 덧셈만 가능한 코드임
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
