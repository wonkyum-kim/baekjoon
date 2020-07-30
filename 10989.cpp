#include <iostream>
#include <vector>
#include <cstdio>

int main()
{
	std::vector<int> A(10001);
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int temp;
		std::scanf("%d", &temp);
		A[temp]++;
	}

	for (int i = 1; i <= 10000; ++i)
	{
		for (int j = 0; j < A[i]; ++j)
			std::printf("%d\n", i);
	}
	return 0;
}
