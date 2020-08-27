#include <iostream>

long long powercalc(long long a, long long b, long long c)
{
	if (b == 0) 		
		return 1;
	long long temp = powercalc(a, b / 2, c);
	long long result;

	if (b % 2 == 0) {
		result = temp * temp % c;
		return result;
	}
	else {
		result = ((temp * temp % c) * a) % c;	// modulo 성질을 이용하여 long long범위를 넘어가지 않게 한다.
		return result;
	}
}

int main()
{
	long long a, b, c;
	std::cin >> a >> b >> c;
	std::cout << powercalc(a, b, c);
}
