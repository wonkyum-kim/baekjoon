#include <iostream>

int main()
{
	std::cin.unsetf(std::ios::dec);
	std::cin.unsetf(std::ios::oct);
	std::cin.unsetf(std::ios::hex);
	
	auto a;
	std::cin >> a;
	std::cout << a;
}
