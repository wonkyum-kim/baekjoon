#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::string s;
	std::string bomb;
	std::cin >> s >> bomb;
	std::string ans;
	auto bsize = bomb.size();
	for (auto& i : s) {
		ans.push_back(i);
		if (ans.size() >= bsize && ans.substr(ans.size() - bsize, bsize) == bomb) {
			for (auto j = 0; j < bsize; ++j) {
				ans.pop_back();
			}
		}
	}
	if (ans.empty()) {
		ans = "FRULA";
	}
	std::cout << ans;
}
