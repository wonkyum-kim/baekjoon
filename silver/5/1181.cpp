#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

int main()
{
    int test = 0;
    std::cin >> test;
    std::vector<std::string> pos;

    using ans = std::string;

    for (auto i = 0; i < test; ++i) {
        std::string s;
        std::cin >> s;
        pos.push_back(s);
    }
    std::sort(pos.begin(), pos.end());
    auto last = std::unique(pos.begin(), pos.end());
    pos.erase(last, pos.end());
    std::sort(pos.begin(), pos.end(), [](const ans& a, const ans& b) {return a.length() != b.length() ? a.length() < b.length() : a < b; });

    for (auto x : pos) {
        std::cout << x << '\n';
    }
}
