#include <iostream>
#include <vector>
#include <string>


void quad_tree(size_t r1, size_t c1, size_t n, std::vector<std::vector<int>>& v)
{
	if (n == 1) {
		std::cout << v[r1][c1];
		return;
	}

	size_t r2 = r1 + n;
	size_t c2 = c1 + n;
	bool flag = true;

	for (auto i = r1; i < r2; ++i) {
		for (auto j = c1; j < c2; ++j) {
			if (v[r1][c1] != v[i][j]) {
				flag = false;
				goto loop_out;
			}
		}
	}

loop_out:

	if (flag == true) {
		std::cout << v[r1][c1];
		return;
	}

	std::cout << '(';
	quad_tree(r1, c1, n / 2, v);
	quad_tree(r1, c1 + n / 2, n / 2, v);
	quad_tree(r1 + n / 2, c1, n / 2, v);
	quad_tree(r1 + n / 2, c1 + n / 2, n / 2, v);
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
