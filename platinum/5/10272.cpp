#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <iomanip>

using Point = std::pair<long double, long double>;

long double distance(const Point& p1, const Point& p2)
{
	return std::hypot(p1.first - p2.first, p1.second - p2.second);
}

long double bitonic_tour(std::vector<Point>& p) 
{
	std::sort(p.begin(), p.end());
	const size_t n = p.size();
	std::vector<std::vector<long double>> dp(n, std::vector<long double>(n, -1));
	dp[0][0] = 0;
	for (auto i = 1; i < n; ++i) {
		dp[0][i] = dp[0][i - 1] + distance(p[i - 1], p[i]);
	}
	for (auto i = 1; i < n; ++i) {
		for (auto j = i; j < n; ++j) {
			auto minimum = std::numeric_limits<long double>::max();
			if (i == j || i == j - 1) {
				for (auto k = 0; k < i; ++k) {
					auto opt = dp[k][i] + distance(p[k], p[j]);
					minimum = std::min(minimum, opt);
				}
				dp[i][j] = minimum;
			}
			else {
				dp[i][j] = dp[i][j - 1] + distance(p[j - 1], p[j]);
			}
		}
	}
	return dp[n - 1][n - 1];
}



int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int t = 0;
	std::cin >> t;
	for (auto i = 0; i < t; ++i) {
		int n = 0;
		std::cin >> n;
		std::vector<Point> p;
		for (auto j = 0; j < n; ++j) {
			long double x = 0;
			long double y = 0;
			std::cin >> x >> y;
			p.push_back({ x,y });
		}
		std::cout << std::setprecision(13) << bitonic_tour(p) << '\n';
	}
}
