#include <iostream>
#include <stack>
#include <string>

int main()
{
    while(true) {
        std::string s;
        std::getline(std::cin, s);
        if(s == ".")
            break;
            
        std::stack<char> stack;
        int flag = false;
        
        for(int i = 0; i < s.length(); ++i) {
            if(s[i] == '(' || s[i] == '[') {
                stack.push(s[i]);
            } 
            else if(s[i] == ')') {
                if(stack.empty() || stack.top() != '(') {
                    flag = true;
                    break;
                } 
                else {
                   stack.pop();
                }
            }
            else if(s[i] == ']') {
                if(stack.empty() || stack.top() != '[') {
                    flag = true;
                    break;
                } 
                else {
                   stack.pop();
                }
            }
        }
        if(stack.empty() && !flag)
            std::cout << "yes\n";
        else
            std::cout << "no\n";
    }
}
