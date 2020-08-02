#include <iostream>

int main()
{
	long long x, line;
	long long sum = 0;
	std::cin >> x;

	for (line = 1; line <= x; ++line)
	{
		sum += line;
		if (sum >= x)
			break;
	}

	sum -= line;
	auto idx_in_line = x - sum;

	if (line % 2 == 0)
		std::cout << idx_in_line << '/' << line - idx_in_line + 1;
	else
		std::cout << line - idx_in_line + 1 << '/' << idx_in_line;
}
