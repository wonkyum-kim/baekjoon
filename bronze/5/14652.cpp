#include <iostream>

int main()
{
    int a = 0, b = 0, k = 0;
    std::cin >> a >> b >> k;
    
    int x = k / b;
    int y = k % b;
    std::cout << x << ' ' << y;
}
