#include <iostream>
#include <vector>

int main()
{
    int n = 0, m = 0, a = 0;
    std::cin >> n >> m;
    
    std::vector<int> v;
    int temp = 0;
    for(auto i = 0; i < n; ++i)
    {
        std::cin >> a;
        v.push_back(a);
    }
    
    for(auto i = 0; i <= v.size() - 3; ++i)
    {
        for(auto j = i + 1; j <= v.size() - 2; ++j)
        {
            for(auto k = j+1; k <= v.size() - 1; ++k)
            {
                if(v[i]+v[j]+v[k] <= m)
                {
                    if(temp < v[i]+v[j]+v[k])
                        temp = v[i]+v[j]+v[k];
                }
            }
        }
    }
    std::cout << temp;
}
