#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	long long a,b,c;
	std::cin>>a>>b>>c;
	std::vector<long long> v {a,b,c};
	std::sort(v.begin(), v.end());
	for(auto x : v)
		std::cout << x << ' ';
}
