#include <iostream>
#include <cmath>

int main()
{
	std::cout.precision(10);
	int day;
	int growing;
	int area;
	int price;
	std::cin >> day >> growing >> area >> price;
	int possible = (day - 1) / growing;
	std::cout << price * area * std::floor(possible);
}
