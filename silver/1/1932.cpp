#include <iostream>
#include <vector>
#include <algorithm>

void dp(int n, std::vector<std::vector<int>>& tree)
{
	if (n == 1) {
		std::cout << tree[1][1];
		return;
	}
	std::vector<std::vector<int>> r(n + 1, std::vector<int>(n + 1));
	r[1][1] = tree[1][1];
	/*
	r[2][1] = r[1][1] + tree[2][1];
	r[2][2] = r[1][1] + tree[2][2];
	r[3][1] = r[2][1] + tree[3][1];
	r[3][2] = std::max(r[2][1], r[2][2]) + tree[3][2];
	r[3][3] = r[2][2] + tree[3][3];
	r[4][1] = r[3][1] + tree[4][1];
	r[4][2] = std::max(r[3][1], r[3][2]) + tree[4][2];
	r[4][3] = std::max(r[3][2], r[3][3]) + tree[4][3];
	r[4][4] = r[3][3] + tree[4][4];
	*/

	for (auto i = 2; i <= n; ++i) {
		for (auto j = 1; j <= n; ++j) {
			if (j == 1) {
				r[i][j] = r[i - 1][j] + tree[i][j];
			}
			else if (j == i) {
				r[i][j] = r[i - 1][j - 1] + tree[i][j];
			}
			else {
				r[i][j] = std::max(r[i - 1][j - 1], r[i - 1][j]) + tree[i][j];
			}
		}
	}
	std::sort(r[n].begin(), r[n].end());
	std::cout << r[n].back();
}

int main()
{
	int n = 0;
	std::cin >> n;
	// 0행과 0열은 비워둔다.
	std::vector<std::vector<int>> tree(n + 1, std::vector<int>(n + 1));
	for (auto i = 1; i <= n; ++i) {
		for (auto j = 1; j <= i; ++j) {
			std::cin >> tree[i][j];
		}
	}
	dp(n, tree);
}
