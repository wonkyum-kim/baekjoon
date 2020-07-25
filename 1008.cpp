#include <iostream>

int main()
{
	double A = 0, B = 0;
	std::cin >> A >> B;
  
  // 소수점 
	std::cout.precision(15);
	std::cout << A / B;
	return 0;
}
