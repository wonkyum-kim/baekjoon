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
    int count = 0;
    
    while(true)
    {
        int n = 0;
        std::cin >> n;
        
        if(n == 0)
            break;
            
        for(auto i = n + 1; i <= 2 * n; ++i)
        {
            if(is_prime(i))
                count++;
        }
        std::cout << count << '\n';
        count = 0;
    }
}
