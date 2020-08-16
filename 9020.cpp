#include <iostream>

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
    int test = 0;
    std::cin >> test;
    
    int even;
    for(auto i = 0; i < test; ++i)
    {
        std::cin >> even;
        int mid = even / 2;
        for(int j = mid; j > 0; --j)
        {
            for(int k = mid; k < even; ++k)
            {
                if(j + k == even && is_prime(j) && is_prime(k))
                {
                    std::cout << j << ' ' << k << '\n';
                    goto ONE;
                }
            }
        }
        ONE:
            continue;
    }
}
