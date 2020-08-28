#include <iostream>
#include <vector>

void color_paper(int i1, int j1, int n, std::vector<std::vector<int>>& v, int& white, int& blue)
{
	// base case
	if (n == 1) {
		if (v[i1][j1] == 0) {
			white++;
		}
		else {
			blue++;
		}
		return;
	}

	// first case
	bool flag = true;
	int i2 = i1 + n;
	int j2 = j1 + n;

	for (auto x = i1; x < i2; ++x) {
		for (auto y = j1; y < j2; ++y) {
			if (v[i1][j1] != v[x][y]) {
				flag = false;
				break;
			}
		}
		if (flag == false)
			break;
	}

	if (flag == true) {
		if (v[i1][j1] == 0) {
			white++;
		}
		else {
			blue++;
		}
		return;
	}

	color_paper(i1, j1, n / 2, v, white, blue);
	color_paper(i1 + n / 2, j1, n / 2, v, white, blue);
	color_paper(i1, j1 + n / 2, n / 2, v, white, blue);
	color_paper(i1 + n / 2, j1 + n / 2, n / 2, v, white, blue);
}

int main()
{
	int n = 0;
	std::cin >> n;

	std::vector<std::vector<int>> v(n, std::vector<int>(n, 0));

	for (auto i = 0; i < n; ++i) {
		for (auto j = 0; j < n; ++j) {
			std::cin >> v[i][j];
		}
	}

	int white = 0, blue = 0;
	color_paper(0, 0, n, v, white, blue);
	std::cout << white << '\n' << blue;
}
