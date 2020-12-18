#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

std::vector<std::vector<bool>> dp(const std::vector<int>& v) 
{
	int n = v.size();
	std::vector<std::vector<bool>> is_palindrome(n, std::vector<bool>(n, false));
	for (auto i = 0; i < n; ++i) {
		is_palindrome[i][i] = true;
		if (i && v[i - 1] == v[i]) {
			is_palindrome[i - 1][i] = true;
		}
	}

	for (auto k = 2; k < n; ++k) {
		for (auto l = 0; l < n - k; ++l) {
			auto r = l + k;
			if (v[l] == v[r] && is_palindrome[l + 1][r - 1]) {
				is_palindrome[l][r] = true;
			}
		}
	}
	return is_palindrome;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n = 0;
	std::cin >> n;
	std::vector<int> v;
	for (auto i = 0; i < n; ++i) {
		int x = 0;
		std::cin >> x;
		v.push_back(x);
	}
	
	int m = 0;
	std::cin >> m;
	auto is_palindrome = dp(v);
	for (auto i = 0; i < m; ++i) {
		size_t l = 0;
		size_t r = 0;
		std::cin >> l >> r;
		if (is_palindrome[l - 1][r - 1]) {
			std::cout << 1 << '\n';
		}
		else {
			std::cout << 0 << '\n';
		}
	}

}
