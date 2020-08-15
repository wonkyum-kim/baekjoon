#include <iostream>
#include <vector>

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
	int n = 0;
	std::cin >> n;
	int input = 0;
	int count = 0;
	
	for(auto i = 0; i < n; i++)
	{
	    std::cin >> input;
	    if(is_prime(input))
	        count++;
	}
	
	std::cout << count;
}
