#include <iostream>
#include <vector>
#include <algorithm>

int count = 0;
std::vector<int> col(100);
std::vector<int> diag1(100);
std::vector<int> diag2(100);


void search(int y, int n)
{
	if (y == n) {
		count++;
		return;
	}
	for (auto x = 0; x < n; ++x) {
		if (col[x] || diag1[x + y] || diag2[x - y + n - 1]) {
			continue;
		}
		col[x] = diag1[x + y] = diag2[x - y + n - 1] = 1;
		search(y + 1, n);
		col[x] = diag1[x + y] = diag2[x - y + n - 1] = 0;
	}
}

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	int n = 0;
	std::cin >> n;
	search(0, n);
	std::cout << count;
}
