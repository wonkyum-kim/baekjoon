#include <iostream>
#include <vector>

int main()
{
    int test = 0;
    std::cin >> test;

    int arr[50][50] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14 };

    for (auto i = 1; i <= 14; ++i)
    {
        arr[i][0] = 1;
        for (auto j = 1; j <= 13; ++j)
        {
            arr[i][j] = arr[i][j - 1] + arr[i - 1][j];
        }
    }

    int k = 0, n = 0;

    for (auto i = 1; i <= test; ++i)
    {
        std::cin >> k >> n;
        std::cout << arr[k][n - 1] << '\n';
    }
}
