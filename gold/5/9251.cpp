#include <iostream>
#include <cassert>
#include <vector>
#include <utility>
#include <numeric>

std::vector<std::vector<size_t>> LCS_length(const std::vector<char>& X, const std::vector<char>& Y)
{
	auto m = X.size() - 1;
	auto n = Y.size() - 1;
	std::vector<std::vector<size_t>> c(m + 1, std::vector<size_t>(n + 1));
	for (auto i = 1; i <= m; ++i) {
		for (auto j = 1; j <= n; ++j) {
			if (X[i] == Y[j]) {
				c[i][j] = c[i - 1][j - 1] + 1;
			}
			else if (c[i - 1][j] >= c[i][j - 1]) {
				c[i][j] = c[i - 1][j];
			}
			else {
				c[i][j] = c[i][j - 1];
			}
		}
	}
	return c;
}

int main()
{
	constexpr char dummy = '?';
	std::vector<char> X;
	std::vector<char> Y;
	X.push_back(dummy);
	Y.push_back(dummy);
	std::string s1;
	std::string s2;
	std::cin >> s1 >> s2;

	for (auto i = 0; i < s1.size(); ++i) {
		X.push_back(s1[i]);
	}
	for (auto i = 0; i < s2.size(); ++i) {
		Y.push_back(s2[i]);
	}

	auto c = LCS_length(X, Y);
	std::cout << c[X.size() - 1][Y.size() - 1];
}
