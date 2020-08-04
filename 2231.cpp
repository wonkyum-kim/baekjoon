#include <iostream>
#include <vector>

int main()
{
    long long n;
    std::cin >> n;

    long long sum = 0;

    for (long long i = 1; i <= n; i++)
    {
        long long temp = i;
        while (temp > 0)
        {
            int x = temp % 10;
            sum += x;
            temp /= 10;
        }

        if (sum + i == n)
        {
            std::cout << i;
            return 0;
        }
        sum = 0;
    }
    std::cout << 0;
}
