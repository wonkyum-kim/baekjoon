#include <stack>
#include <iostream>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int n = 0;
	std::cin >> n;
	std::vector<int> sticks;
	for (auto i = 0; i < n; ++i) {
		int temp = 0;
		std::cin >> temp;
		sticks.push_back(temp);
	}
	std::stack<int> ans;
	for (int i = n - 1; i >= 0; --i) {
		if (ans.empty() || ans.top() < sticks[i]) {
			ans.push(sticks[i]);
		}
	}
	std::cout << ans.size();
}
