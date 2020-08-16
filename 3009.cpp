#include <iostream>
#include <algorithm>

int main()
{
   int x1, y1, x2, y2, x3, y3, x4, y4;
   std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
   
    if(x1 == x2)
    {
        x4 = x3;
        if(y3 == y1)
            y4 = y2;
        else
            y4 = y1;
    }
    else if (x1 == x3)
    {
        x4 = x2;
        if(y2 == y1)
            y4 = y3;
        else
            y4 = y1;
    }
    else
    {
        x4 = x1;
        if(y1 == y2)
            y4 = y3;
        else
            y4 = y2;
    }
    
    std::cout << x4 << ' ' << y4;
}
