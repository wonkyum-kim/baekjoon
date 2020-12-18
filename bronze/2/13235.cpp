#include <iostream>
#include <string>
#include <algorithm>

std::string mirror_ends(const std::string& in)
{
    return std::string(in.begin(),
        std::mismatch(in.begin(), in.end(), in.rbegin()).first);
}

int main()
{
    std::string s;
    std::cin >> s;
    if (s == mirror_ends(s)) {
        std::cout << "true";
    }
    else {
        std::cout << "false";
    }
}
