#include <iostream>

void hanoi1(int n, int from, int by, int to, int& count)
{
    if(n == 1)
        count++;
    else
    {
        hanoi1(n-1, from, to, by, count);
        count++;
        hanoi1(n-1, by, from, to, count);
    }
}

void hanoi2(int n, int from, int by, int to)
{
    if(n == 1)
        std::cout << from << ' ' << to << '\n';
    else
    {
        hanoi2(n-1, from, to, by);
        std::cout << from << ' ' << to << '\n';
        hanoi2(n-1, by, from, to);
    }
}

int main()
{
    int n = 0;
    int count = 0;
    std::cin >> n;
    hanoi1(n, 1, 2, 3, count);
    std::cout << count << '\n';
    hanoi2(n, 1, 2, 3);
}
