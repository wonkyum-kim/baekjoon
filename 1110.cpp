#include <iostream>
#include <vector>

int main()
{
	int a;
	cin >> a;
	std::vector<int> an;
	an.push_back(a);

	for (int i = 1;; ++i)
	{
 		// a % 10 == 일의자리 숫자
		a = (a % 10) * 10 + ((a % 10) + (a - a % 10) / 10) % 10;
		if (a == an[0])
		{
			std::cout << i;
			break;
		}
	}
}
