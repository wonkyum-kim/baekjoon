#include <iostream>
#include <vector>
#include <algorithm>

void dnc(std::vector<int>& length, int n)
{
	if (n == 1) {
		std::cout << 'm';
		return;
	}
	if (n == 2 || n == 3) {
		std::cout << 'o';
		return;
	}
	auto last = std::lower_bound(length.begin(), length.end(), n);
	auto i = std::distance(length.begin(), last);
	// case 1 : n이 길이와 딱 맞을 때
	if (length[i] == n) {
		std::cout << 'o';
		return;
	}
	// case 2 : n이 k + 3 안에 있을 때
	else if (n - length[i - 1] == 1) {
		std::cout << 'm';
		return;
	}
	else if (n - length[i - 1] != 1 && n - length[i - 1] <= i + 3) {
		std::cout << 'o';
		return;
	}
	// case 3 : length[i - 1] + i + 3이후에 있을 때
	else {
		dnc(length, n - length[i - 1] - (i + 3));
	}
	// length[i-1]안에 n이 있는 경우는 없다.
	// 왜냐하면 lower_bound를 사용했기 때문.
}


int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	int n = 0;
	std::cin >> n;
	std::vector<int> length(28);
	length[0] = 3;
	for (auto i = 1; i < 28; ++i) {
		length[i] = 2 * length[i - 1] + i + 3;
	}
	dnc(length, n);
}
