#include <iostream>

int main()
{
    int a = 0;
    std::cin >> a;
    int b = a / 5;
    if(a % 5 == 0)
        std::cout << b;
    else
        std::cout << b + 1;
}
