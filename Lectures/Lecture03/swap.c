#include <stdio.h>

void swap(int *x, int *y);

int main(void)
{
	int a = 3;
	int b = 8;
	printf("%d, %d\n", a, b);
	printf("Memory addresses of a and b: %p, %p\n", &a, &b);
	swap(&a, &b);
	printf("%d, %d\n", a, b);

	return 0;
}

void swap(int *x, int *y)
{
	printf("Memory addresses of x and y: %p, %p\n", &x, &y);
	printf("Memory addresses of a and b: %p, %p\n", x, x);
	int a_copy = *x;
	int b_copy = *y;
	*y = a_copy;
	*x = b_copy;
	/* when this exits, 'a' and 'b' here will disappear
	 * remember: we can't return stuff we create inside here
	 * (with one exception we'll talk about later!)
	 */
}
