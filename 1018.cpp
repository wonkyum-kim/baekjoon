#include <iostream>

int paint(int x, int y, char arr[][50])
{
    int count = 0;
    for(auto i = x; i < x+8; ++i)
    {
        for(auto j = y; j < y+8; ++j)
        {
            if((i+j)%2 == 0 && arr[x][y] != arr[i][j])
                count++;
            else if((i+j)%2 == 1 && arr[x][y] == arr[i][j])
                count++;
        }
    }
    if(count > 32)
    	return 64 -count;
    else
    	return count;
}

int main()
{
    char arr[50][50];
    int n, m;
    std::cin >> n >> m;
    
    for(auto i = 0; i < n; ++i)
        for(auto j = 0; j < m; ++j)
            std::cin >> arr[i][j];
    
    int count = 0;
    int min = 32;
    
    for(auto i = 0; i <= n - 8; ++i)
    {
        for(auto j = 0; j <= m - 8; ++j)
        {
            count = paint(i, j, arr);
            if(min > count)
                min = count;
        }
    }
    
    std::cout << min;
}
