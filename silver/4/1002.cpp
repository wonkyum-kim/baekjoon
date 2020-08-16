#include <algorithm>
#include <iostream>
#include <cmath>

int main()
{
    double x1, x2, r1, r2, y1, y2;
    int test = 0;
    std::cin >> test;

    for (auto i = 0; i < test; ++i)
    {
        std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        double diff = std::sqrt(std::pow((x1 - x2), 2) + std::pow((y1 - y2), 2));

        // 외부에서 만나지않는다
        if (diff > r1 + r2)
            std::cout << 0 << '\n';
        // 외접한다
        else if (diff == r1 + r2)
            std::cout << 1 << '\n';
        // 동심원이다
        else if (x1 == x2 && y1 == y2)
        {
            if (r1 == r2)
                std::cout << -1 << '\n';
            else
                std::cout << 0 << '\n';
        }
        // 내접한다
        else if (diff + std::min(r1, r2) == std::max(r1, r2))
            std::cout << 1 << '\n';
        // 내부에서 만나지 않는다
        else if (diff + std::min(r1, r2) < std::max(r1, r2))
            std::cout << 0 << '\n';
        // 두점에서 만난다.
        else
            std::cout << 2 << '\n';

    }
}
