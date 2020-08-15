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
    std::vector<int> v;
    
    for(auto i = m; i <=n; ++i)
    {
        if(is_prime(i))
            v.push_back(i);
    }
    
    int sum = std::accumulate(v.begin(), v.end(), 0);
    
    if(std::empty(v))
        std::cout << -1;
    else
        std::cout << sum << '\n' << v.front();
}
