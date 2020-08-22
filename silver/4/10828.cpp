#include <iostream>
#include <string>
#include <stack>

int main()
{
    std::stack<int> s;
    int test = 0;
    std::cin >> test;
    
    for(auto i = 0; i < test; ++i) {
        std::string s1;
        std::cin >> s1;
        if(s1 == "push"){
            int a = 0;
            std::cin >> a;
            s.push(a);
        }
        else if(s1 == "pop") {
            if(s.empty()) 
                std::cout << "-1\n";
            else {
                std::cout << s.top() << '\n';
                s.pop();
            }
            
        }
        else if(s1 == "size") 
            std::cout << s.size() << '\n';
        else if(s1 == "empty") {
            if(s.empty())
                std::cout << "1\n";
            else
                std::cout << "0\n";
        }
        else if(s1 == "top") {
            if(s.empty())
                std::cout << "-1\n";
            else
                std::cout << s.top() << '\n';
        }
    }
}
