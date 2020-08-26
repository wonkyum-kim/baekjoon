#include <iostream>
#include <vector>

int main()
{
	std::vector<int> triangle;
	triangle.push_back(0);

	for (auto i = 1; i <= 45; ++i) {
		triangle.push_back(i * (i + 1) / 2);
	}

	int test = 0, k = 0, sum = 0;
	std::cin >> test;

	for (auto i = 0; i < test; ++i) {
		std::cin >> k;
		for (auto j = 1; j < triangle.size(); ++j) {
			for (auto m = 1; m < triangle.size(); ++m) {
				for (auto n = 1; n < triangle.size(); ++n) {
					sum = triangle[j] + triangle[m] + triangle[n];
					if (sum == k) {
						std::cout << "1\n";
						goto ONE;
					}
				}
			}
		}
		std::cout << "0\n";
	ONE:;
	}
}
