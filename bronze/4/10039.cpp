#include <iostream>
#include <vector>

int main()
{
	int sum = 0;
	std::vector<int> score;

	for (int i = 0; i < 5; i++) {
		int a;
		std::cin >> a;
		if (a < 40)
			a = 40;
		score.push_back(a);
		sum += score[i];
	}
	std::cout << sum / 5;
	return 0;
}
