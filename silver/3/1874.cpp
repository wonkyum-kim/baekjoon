#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    // test case
    int test = 0;
    std::cin >> test;

    //
    std::stack<int> st;
    std::vector<char> v;
    int max = 0;

    for (auto i = 0; i < test; ++i) {

        int a = 0;
        std::cin >> a;

        if (max < a) {
            for (auto j = max + 1; j <= a; ++j) {
                st.push(j);
                v.push_back('+');
            }
            st.pop();
            v.push_back('-');
            max = a;
        }
        else if (max > a) {
            if (st.top() == a) {
                st.pop();
                v.push_back('-');
            }
            else {
                v.push_back('n');
                break;
            }
             
        }
    }
    
    auto it = std::find(v.begin(), v.end(), 'n');
    if (it == v.end()) {        // 정상적이라면
        for (auto x : v) {
            std::cout << x << '\n';
        }
    }
    else {
        std::cout << "NO";
    }
}
