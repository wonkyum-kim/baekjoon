#include <iostream>
#include <vector>
#include <numeric>

bool is_prime(const int i)
{
	if (i == 1)
		return false;

	else if (i == 2)
		return true;

	for (auto j = 2; j * j <= i; ++j)
		if (i % j == 0)
			return false;

	return true;
}

int main()
{
    int m = 0;
    int n = 0;
    std::cin >> m >> n;

    for(auto i = m; i <=n; ++i)
    {
        if(is_prime(i))
            std::cout << i << '\n';
    }
}
