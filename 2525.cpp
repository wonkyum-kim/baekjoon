#include <iostream>

int main()
{
	int a, b, c;
	std::cin >> a>> b >> c;
	int ca = c/60;
	int cb = c%60;
	
	if(cb+b < 60)
	{
		if(a+ca < 24)
			std::cout << a + ca << ' ' << cb + b;
		else
			std::cout << a + ca - 24 << ' ' << cb + b;
	}
	else
	{
		if(a+ca+1 < 24)
			std::cout << a + ca + 1 << ' ' << cb + b - 60;
		else
			std::cout << a + ca + 1 - 24 << ' ' << cb + b - 60;
	}
	
}
