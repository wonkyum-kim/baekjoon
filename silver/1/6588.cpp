#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>

bool is_prime(const int i)
{
	if (i == 1)
		return false;

	else if (i == 2)
		return true;

	for (auto j = 2; j * j <= i; ++j)
		if (i % j == 0)
			return false;
	return true;
}

void goldbach() {
	int a = 0;
	int b = 0;

	while (true) {
		int num = 0;
		std::cin >> num;
		if (num == 0) {
			break;
		}
		else {
			for (auto i = 3; i <= num/2; ++i) {
				if (is_prime(i) && is_prime(num - i)) {
					a = i;
					b = num - i;
					std::cout << num << ' ' << '=' << ' ' << a << ' ' << '+' << ' ' << b << '\n';
					break;
				}
				else if (i != num / 2) {
					continue;
				}
				else if (i == num / 2) {
					std::cout << "Goldbach's conjecture is wrong.\n";
					break;
				}
			}
		}
	}

}

int main()
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	goldbach();
}
