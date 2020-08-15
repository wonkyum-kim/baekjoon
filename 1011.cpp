#include <iostream>
#include <cmath>

int main()
{
    int test = 0;
    std::cin >> test;
    
    long long destination = 0;
    long long start = 0;
    long long difference = 0;
    
    for(auto i = 0; i <test; ++i)
    {
        std::cin >> start >> destination;
        difference = destination - start;
        long long n = std::sqrt(difference);
        
        if(difference == n*n)
            std::cout << 2 * n - 1 << '\n';
        else if(difference > n*n && difference < std::pow(n+1,2))
        {
            if(difference <= n*n + n + 0.5)
                std::cout << 2 * n << '\n';
            else
                std::cout << 2 * n + 1 << '\n';
        }
    }
}

/*
1  1     2n-1
2  11    2n
3  111   2n+1
4  121   2n-1
5  1211  2n
6  1221  2n
7  12211 2n+1
8  12221 2n+1
9  12321 2n-1
*/
