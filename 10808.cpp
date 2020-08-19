#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string s1;
    std::cin >> s1;
    
    std::vector<int> alpha(26);
    for(auto i = 0; i < s1.length(); ++i){
        alpha[s1[i] - 'a']++;
    }
    
    for(auto x : alpha){
        std::cout << x << ' ';
    }
}
