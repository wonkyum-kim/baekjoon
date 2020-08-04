#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int sum = 0;
    std::vector<int> A;
    for(auto i = 0; i < 9; i++)
    {
        int a;
        std::cin >> a;
        A.push_back(a);
        sum += a;
    }
    
    int temp1, temp2;
    
    for(auto i = 0; i < 8; i++)
    {
        for(auto j = i + 1; j <= 9; j++)
        {
            if(sum - A[i] - A[j] == 100)
            {
                temp1 = i;
                temp2 = j;
                break;
            }
        }
    }
    
    std::vector<int> B;
    
    for(auto x : A)
    {
        if(x != A[temp1] && x != A[temp2])
            B.push_back(x);
    }
    
    std::sort(B.begin(), B.end());
    
    for(auto y : B)
        std::cout << y << ' '; 
}
