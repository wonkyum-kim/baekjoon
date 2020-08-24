#include <iostream>
#include <algorithm>
#include <limits>

int paint(int x, int y, char arr[][50])
{
    int count1 = 0, count2 = 0;
    for (auto i = x; i < x + 8; ++i)
    {
        for (auto j = y; j < y + 8; ++j)
        {
            if ((i + j) % 2 == 0 && 'W' != arr[i][j])
                count1++;
            else if ((i + j) % 2 == 1 && 'W' == arr[i][j])
                count1++;

            if ((i + j) % 2 == 0 && 'B' != arr[i][j])
                count2++;
            else if ((i + j) % 2 == 1 && 'B' == arr[i][j])
                count2++;
        }
    }
    int min = std::min(count1, count2);
    return min;
}

int main()
{
    char arr[50][50];
    int n, m;
    std::cin >> n >> m;

    for (auto i = 0; i < n; ++i)
        for (auto j = 0; j < m; ++j)
            std::cin >> arr[i][j];

    int count = 0;
    int min = std::numeric_limits<int>::max();

    for (auto i = 0; i <= n - 8; ++i)
    {
        for (auto j = 0; j <= m - 8; ++j)
        {
            count = paint(i, j, arr);
            if (min > count)
                min = count;
        }
    }

    std::cout << min;
}
