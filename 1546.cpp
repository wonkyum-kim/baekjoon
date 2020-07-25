#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	
	int num = 0;
	std::cin >> num;

	std::vector<int> score;
	for (size_t i = 0; i < num; i++)
	{
		int a = 0;
		std::cin >> a;
		score.push_back(a);
	}

	std::sort(score.begin(), score.end());
	double max = score.back();

	double sum = 0;

	for (auto x : score)
	{
		sum += x / max * 100;
	}

	double average = sum / num;

	std::cout.fixed;
	std::cout.precision(15);

	std::cout<< average;
}
