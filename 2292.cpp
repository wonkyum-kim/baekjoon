#include <iostream>

int main()
{
	long long n = 0;
	std::cin >> n;

	long long an = 1;

	if (n == 1)
		std::cout << 1;
	else
	{
		for (long long i = 1; i <= 20000000000; i++)
		{
			
			if (an < n && n <= an + 6 * i)
			{
				std::cout << i + 1;
				break;
			}
			an += 6 * i;
		}
	}
}
/*
1번째 1
2번째 6
3번째 12
4번째 18
5번째 24

1 = 1
2~7 = 2
8~19 = 3
20~37 = 4

1+6+12+18+24+...

1 + 6*1 + 6*2 + 6*3 + 6*4 + 6*5

if (n = 1)
ans = 1;
else if (1 < n <=1+6*1)
ans = 2;
else if (1+6*1 < n <= 1+6*1+6*2)
ans = 3;
*/
