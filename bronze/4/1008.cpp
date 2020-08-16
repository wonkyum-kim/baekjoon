#include <iostream>
#include <iomanip>

int main()
{
	double A = 0, B = 0;
	std::cin >> A >> B;
	std::cout << std::fixed << std::setprecision(15) << A / B;
	return 0;
}
