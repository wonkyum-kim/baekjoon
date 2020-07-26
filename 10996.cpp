#include <cstdio>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	for (int a = 1; a <= n * 2; a++)
	{
		for (int i = 1; i <= n && a%2==1 ; ++i)
		{
			if (i % 2 == 0)
				printf(" ");
			else
				printf("*");
		}
		for (int j = 1; j <= n && a % 2 == 0; ++j)
		{
			if (j % 2 == 0)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}
