#include <iostream>
#include <vector>
#include <string>


void quad_tree(size_t x1, size_t y1, size_t n, std::vector<std::vector<int>>& v)
{
	if (n == 1) {
		std::cout << v[x1][y1];
		return;
	}

	size_t x2 = x1 + n;
	size_t y2 = y1 + n;
	bool flag = true;

	for (auto i = x1; i < x2; ++i) {
		for (auto j = y1; j < y2; ++j) {
			if (v[x1][y1] != v[i][j]) {
				flag = false;
				break;
			}
		}
		if (flag == false) {
			break;
		}
	}

	if (flag == true) {
		std::cout << v[x1][y1];
		return;
	}

	std::cout << '(';
	quad_tree(x1, y1, n / 2, v);
	quad_tree(x1, y1 + n / 2, n / 2, v);
	quad_tree(x1 + n / 2, y1, n / 2, v);
	quad_tree(x1 + n / 2, y1 + n / 2, n / 2, v);
	std::cout << ')';
}

int main()
{
	int n = 0;
	std::cin >> n;

	std::string s;

	std::vector<std::vector<int>> v(n, std::vector<int>(n, 0));
	for (size_t i = 0; i < n; ++i) {
		std::cin >> s;
		for (size_t j = 0; j < n; ++j) {
			v[i][j] = s[j] - 48;
		}
	}
	quad_tree(0, 0, n, v);
}
