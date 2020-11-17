#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>

int main()
{
	int n = 0;
	int k = 0;
	std::cin >> n >> k;
	std::vector<int> v;
	for (auto i = 1; i <= n; ++i) {
		v.push_back(i);
	}
	
	int head = 0;
	std::cout << '<';
	for (auto i = n; i > 0; --i) {
		if (i != 1) {
			std::cout << v[(head + k - 1) % i] << ", ";
		}
		else {
			std::cout << v[(head + k - 1) % i];
		}
		head = (head + k - 1) % i;
		v.erase(v.begin() + head);
	}
	std::cout << '>';
}
