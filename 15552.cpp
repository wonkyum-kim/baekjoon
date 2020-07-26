#include <stdio.h>

int main()
{

	auto T = 0;
	scanf("%d", &T);

	for(int i = 0; i< T;++i)
		if (T >= 1 && 1 <= 1000000)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			if (a >= 1 && b >= 1 && a <= 1000 && b <= 1000)
				printf("%d\n", a+b);
		}

	return 0;
}
