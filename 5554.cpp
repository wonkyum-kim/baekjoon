#include <iostream>
#include <vector>
#include <string>

int main()
{
	int a, b, c, d;
	std::cin >> a >> b >> c >> d;
	int sum = a + b + c + d;
	int min = sum / 60;
	int sec = sum - min * 60;
	std::cout << min << '\n' << sec;
}
