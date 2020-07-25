#include <iostream>

int main()
{
	auto a = 0, b = 0;
	std::cin >> a >> b;

		if (a > b) 
			std::cout << '>';
		else if (a < b) 
			std::cout << '<';
		else 
			std::cout << R"(==)";
	
	return 0;
}
