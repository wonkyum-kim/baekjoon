#include <iostream>
#include <stack>
#include <string>

int main()
{
    int t = 0;
    std::cin >> t;

    for (auto i = 0; i < t; ++i) {
        std::string s;
        std::cin >> s;

        std::stack<char> stack;
        bool flag = false;

        for (auto j = 0; j < s.length(); ++j) {
            if (s[j] == '(') {
                stack.push(s[j]);
            }
            else if (s[j] == ')') {
                if (stack.empty() || stack.top() != '(') {
                    flag = true;
                    break;
                }
                else {
                    stack.pop();
                }
            }
        }

        if (!flag && stack.empty()) {
            std::cout << "YES\n";
        }
        else
            std::cout << "NO\n";
    }
}
