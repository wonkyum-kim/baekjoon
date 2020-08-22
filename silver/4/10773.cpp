#include <iostream>
#include <string>
#include <stack>
#include <numeric>
 
int main()
{
    int test = 0;
    std::cin >> test;
    std::stack<int> s;
 
    for(auto i = 0; i < test; ++i) {
        int a = 0;
        std::cin >> a;
        if(a != 0) 
            s.push(a);
        else 
            s.pop();
    }
 
    long long sum = 0;
    // s.size() 바뀌는걸 조심해야 한다.
    int size = s.size();
    for(auto j = 0; j < size; ++j) {
        sum += s.top();
        s.pop();
    }
 
    std::cout << sum;
}
