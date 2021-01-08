#include <iostream>
#include <stack>
#include <string>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::string s;
	std::cin >> s;
	int count = 0;
	int iron = 0;
	auto size = s.size();
	for (auto i = 0; i < size; ++i) {
		if (s[i] == '(') {
			iron++;
		}
		else {
			iron--;
			if (i > 0 && s[i - 1] == '(') {
				count += iron;
			}
			else {
				count++;
			}
		}
	}
	std::cout << count;
}
