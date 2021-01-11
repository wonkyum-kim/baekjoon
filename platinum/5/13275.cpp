#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

void manacher(std::string& s)
{
	int n = s.size();
	std::vector<int> A(n);
	int right = 0;
	int center = 0;
	for (auto i = 0; i < n; ++i) {
		if (i <= right) {
			A[i] = std::min(A[2 * center - i], right - i);
		}
		while (i - A[i] - 1 >= 0 && i + A[i] + 1 < n && s[i - A[i] - 1] == s[i + A[i] + 1]) {
			A[i]++;
		}
		if (right < i + A[i]) {
			right = i + A[i];
			center = i;
		}
	}
	std::cout << *std::max_element(A.begin(), A.end());
}

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::string s;
	std::cin >> s;
	std::string ns = "#";
	for (auto& x : s) {
		ns += x;
		ns += '#';
	}
	manacher(ns);
}
