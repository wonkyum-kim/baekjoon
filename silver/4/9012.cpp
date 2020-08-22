#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    int test = 0;
    std::cin >> test;

    for (auto i = 0; i < test; ++i) {
        std::string ps;
        std::cin >> ps;
        int count = 0;

        // 괄호가 안 닫히는 경우
        if (ps.back() == '(' || ps.front() == ')') {
            std::cout << "NO\n";
            goto ONE;
        }
        else {
            for(int j = ps.length() - 1; j >= 0; --j) {
                if (ps[j] == ')')
                    count++;
                else {
                    count--;
                    if (count < 0) {
                        std::cout << "NO\n";
                        goto ONE;
                    }
                }
            }
        }
        if (count == 0)
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    ONE:;
    }
}
