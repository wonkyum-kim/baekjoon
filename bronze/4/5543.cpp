#include <iostream>
#include <vector>

int main()
{
	vector<int> price;

	for (int i = 0; i < 5; i++) {
		int a;
		std::cin >> a;
		price.push_back(a);
	}

	int maxdrink = (price[3] < price[4]) ? price[3] : price[4];
	int maxburger = (price[0] < price[1]) ? (price[0] < price[2]) ? price[0] : price[2] : (price[1] < price[2]) ? price[1] : price[2];

	std::cout << maxdrink + maxburger - 50;
	return 0;
}
