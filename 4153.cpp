#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

int main()
{
    std::vector<int> v;
    int temp1, temp2, temp3;
    
    while(true)
    {
        std::cin >> temp1 >> temp2 >> temp3;
        if(temp1 == 0 && temp2 == 0 && temp3 == 0)
            break;
            
        v.push_back(temp1);
        v.push_back(temp2);
        v.push_back(temp3);
        std::sort(v.begin(), v.end());
        
        int x, y, z;
        x = std::pow(v[0], 2);
        y = std::pow(v[1], 2);
        z = std::pow(v[2], 2);
        
        if(z == x + y)
            std::cout << "right\n";
        else
            std::cout << "wrong\n";
        
        v.erase(v.begin(), v.end());
    }
}
