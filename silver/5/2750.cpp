#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int num;
	std::cin >> num;

	std::vector<int> a;
	for (size_t i = 0; i < num; i++) {
		int x = 0;
		std::cin >> x;
		a.push_back(x);
	}

	std::sort(a.begin(), a.end());
	for (auto& x : a)
		std::cout << x << '\n';
}
