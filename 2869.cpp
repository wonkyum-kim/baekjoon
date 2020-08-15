#include <iostream>
#include <cmath>

int main()
{
    long double A, B, V;
    std::cin >> A >> B >> V;
    long long day = std::ceil((V - B) / (A - B));
    std::cout << day;
}

/*
(A * n) - (B * n-1) >= V
(A-B)*n + B >= V
n >= V-B / A-B
*/
