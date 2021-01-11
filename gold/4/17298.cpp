#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	int n = 0;
	std::cin >> n;
	std::vector<int> v;
	for (auto i = 0; i < n; ++i) {
		int temp = 0;
		std::cin >> temp;
		v.push_back(temp);
	}

	std::stack<std::pair<int,int>> st;
	std::vector<int> NGE(n, -1);
	for (auto i = 0; i < n; ++i) {
		if (st.empty() || st.top().first >= v[i]) {
			st.push({ v[i],i });
		}
		else {
			while (!st.empty() && st.top().first < v[i]) {
				NGE[st.top().second] = v[i];
				st.pop();
			}
			st.push({ v[i],i });
		}
	}
	for (auto& x : NGE) {
		std::cout << x << ' ';
	}
}
