#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int dice1, dice2, dice3;
	std::cin >> dice1 >> dice2 >> dice3;
	std::vector<int> v{ dice1, dice2, dice3 };
	std::vector<int>::iterator result = std::max_element(v.begin(), v.end());

	if (v[0] == v[1] && v[1] == v[2])
		std::cout << 10000 + v[0] * 1000;
	else if (v[0] != v[1] && v[0] != v[2] && v[1] != v[2])
		std::cout << *result * 100;
	else
	{
		if (v[0] == v[1] || v[0] == v[2])
			std::cout << 1000 + v[0] * 100;
		else if (v[1] == v[2])
			std::cout << 1000 + v[1] * 100;
	}
}
