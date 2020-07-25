#include <iostream>
#include <vector>

int main()
{
	std::cout.setf(std::ios::fixed);
	std::cout.precision(3);

	int c;
	std::cin >> c;

	std::vector<double> a;
	
	for (size_t i = 0; i < c; ++i)
	{
		int num=0;
		std::cin >> num;

		double sum = 0;
		double average = 0;
		double count = 0;
		

		for (size_t j = 0; j < num; ++j)
		{
			double n = 0;
			std::cin >> n;
			a.push_back(n);
			sum += a[j];
		}
		average = sum / num;

		for (size_t j = 0; j < num; ++j)
		{
			if (a[j] > average)
				count++;
		}
		std::cout << count / num * 100 << "%\n";
		a.clear();
	}
}
