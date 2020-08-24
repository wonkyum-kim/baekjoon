#include <iostream>
#include <algorithm>

int main()
{
    int x = 0, y = 0;
    int w = 0, h = 0;
    
    std::cin >> x >> y >> w >> h;
    
    int short_line1 = std::min(x, w - x);
    int short_line2 = std::min(y, h - y);
    int shortest = std::min(short_line1, short_line2);
    std::cout << shortest;
}
