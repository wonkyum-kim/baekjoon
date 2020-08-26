#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int n = 0, l = 0;
	std::cin >> n >> l;

	std::vector<int> pos;
	for (size_t i = 0; i < n; ++i) {
		int a = 0;
		std::cin >> a;
		pos.push_back(a);
	}

	std::sort(pos.begin(), pos.end());

	size_t i = 0, j = 0;
	int count = 0;

	while (true) {
		if (j != pos.size() - 1 && pos[++j] - pos[i] > l - 1) {
			count++;
			i = j;
		}

		if (j == pos.size() - 1) {
			count++;
			break;
		}
	}
	std::cout << count;
}
