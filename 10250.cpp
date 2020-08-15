#include <iostream>

int main()
{
    int test = 0;
    int hotel_floor = 0;
    int hotel_room = 0;
    int n = 0;
    int x = 0;
    int y = 0;
    
    std::cin >> test;
    
    for(int i = 0; i < test; ++i)
    {
        std::cin >> hotel_floor >> hotel_room >> n;
        
        if(n % hotel_floor != 0)
        {
            x = n / hotel_floor + 1;
            y = n % hotel_floor;
        }
        else
        {
            x = n / hotel_floor;
            y = hotel_floor;
        }
        
        if(x < 10)
            std::cout << y << '0' << x << '\n';
        else
            std::cout << y << x << '\n';
    }
}
