#include <iostream>
#include <vector>

int count1 = 0;
int count2 = 0;
int count3 = 0;

void quad_tree(size_t x1, size_t y1, size_t n, std::vector<std::vector<int>>& v)
{
	if (n == 1) {
		if (v[x1][y1] == -1) {
			count1++;
		}
		else if (v[x1][y1] == 0) {
			count2++;
		}
		else {
			count3++;
		}
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
		if (v[x1][y1] == -1) {
			count1++;
		}
		else if (v[x1][y1] == 0) {
			count2++;
		}
		else {
			count3++;
		}
		return;
	}

	// case 1
	quad_tree(x1, y1, n / 3, v);
	// case 2
	quad_tree(x1, y1 + n / 3, n / 3, v);
	// case 3
	quad_tree(x1, y1 + 2 * n / 3, n / 3, v);
	// case 4
	quad_tree(x1 + n / 3, y1, n / 3, v);
	// case 5
	quad_tree(x1 + n / 3, y1 + n / 3, n / 3, v);
	// case 6
	quad_tree(x1 + n / 3, y1 + 2 * n / 3, n / 3, v);
	// case 7
	quad_tree(x1 + 2 * n / 3, y1, n / 3, v);
	// case 8
	quad_tree(x1 + 2 * n / 3, y1 + n / 3, n / 3, v);
	// case 9
	quad_tree(x1 + 2 * n / 3, y1 + 2 * n / 3, n / 3, v);
}

int main()
{
	int n = 0;
	std::cin >> n;

	std::vector<std::vector<int>> v(n, std::vector<int>(n, 0));
	for (size_t i = 0; i < n; ++i) {
		for (size_t j = 0; j < n; ++j) {
			std::cin >> v[i][j];
		}
	}

	quad_tree(0, 0, n, v);

	std::cout << count1 << '\n' << count2 << '\n' << count3;
}
