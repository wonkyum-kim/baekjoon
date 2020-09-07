#include <iostream>
#include <numeric>
#include <vector>

int main()
{
	std::vector<long long> num;
	std::vector<long long> save_gcd;

	int test = 0;
	std::cin >> test;
	for (auto i = 0; i < test; ++i) {
		int n = 0;
		std::cin >> n;
		for (auto j = 0; j < n; ++j) {
			long long temp = 0;
			std::cin >> temp;
			num.push_back(temp);
		}
		for (auto k = 0; k < num.size() - 1; ++k) {
			for (auto s = k + 1; s < num.size(); ++s) {
				long long temp2 = std::gcd(num[k], num[s]);
				save_gcd.push_back(temp2);
			}
		}
		std::cout << std::accumulate(save_gcd.begin(), save_gcd.end(), 0LL) << '\n';
		num.clear();
		save_gcd.clear();
	}
}
