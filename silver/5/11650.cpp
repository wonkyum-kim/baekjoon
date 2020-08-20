#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

int main()
{
    int test = 0;
    std::cin >> test;
    std::vector<std::pair<int, int>> pos;

    using ans = std::pair<int, int>;

    for (auto i = 0; i < test; ++i) {
        int x = 0, y = 0;
        std::cin >> x >> y;
        pos.push_back({ x, y });
    }

    std::sort(pos.begin(), pos.end(), [](const ans& a, const ans& b) {return a.first != b.first ? a.first < b.first : a.second < b.second; });

    for (auto x : pos) {
        std::cout << x.first << ' ' << x.second << '\n';
    }
}
