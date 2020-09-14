#include<iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int count = 0;

void visit_Z(const int r, const int c, const int row, int x, int y)
{
	// base case
	if (row == 2) {
		if (x == r && y == c) {
			std::cout << count;
		}
		count++;
		if (x == r && y + 1 == c) {
			std::cout << count;
		}
		count++;
		if (x + 1 == r && y == c) {
			std::cout << count;
		}
		count++;
		if (x + 1 == r && y + 1 == c) {
			std::cout << count;
		}
		count++;
		return;
	}

	visit_Z(r, c, row / 2, x, y);
	visit_Z(r, c, row / 2, x, y + row / 2);
	visit_Z(r, c, row / 2, x + row / 2, y);
	visit_Z(r, c, row / 2, x + row / 2, y + row / 2);
}

int main()
{
	int N = 0;
	int r = 0, c = 0;
	std::cin >> N >> r >> c;
	int row = std::pow(2, N);
	visit_Z(r, c, row, 0, 0);
}
