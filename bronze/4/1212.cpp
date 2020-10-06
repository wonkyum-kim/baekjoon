#include <iostream>
#include <vector>
#include <string>

int main()
{
	std::string octal_number;
	std::cin >> octal_number;
	std::vector<std::string> digits = { "000", "001", "010", "011", "100", "101", "110", "111" };
	std::vector<std::string> exception = { "0", "1", "10", "11" };
	for (auto i = 0; i < octal_number.size(); ++i) {
		size_t temp = octal_number[i] - '0';
		if (i == 0 && temp <= 3) {
			std::cout << exception[temp];
		}
		else {
			std::cout << digits[temp];
		}
	}
}
