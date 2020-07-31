#include <iostream>
#include <string>

int main()
{
	int T = 0;
	std::cin >> T;

	int a;
	std::string b;
	
	for (auto i = 0; i < T; ++i)
	{
		std::cin >> a >> b;
		for (auto k = 0; k < b.length(); ++k)
		{
			for (auto j = 0; j < a; ++j)
				std::cout << b[k];
		}
		std::cout << '\n';
	}
}
