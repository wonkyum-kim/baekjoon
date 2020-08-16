#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
    long double r = 0;
    std::cin >> r;
    const double PI = std::acos(-1);
    std::cout << std::fixed << std::setprecision(8) << r * r * PI << '\n' << r * r * 2;
}
