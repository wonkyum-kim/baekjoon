#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cmath>

int main()
{
    int n = 0, a = 0;
    std::cin >> n;
    std::vector<int> v;
    std::vector<int> count(8001);
    
    for(auto i = 0; i < n; ++i) {
        std::cin >> a;
        v.push_back(a);
        count[a + 4000]++;
    }

    std::sort(v.begin(), v.end());
    double sum = std::accumulate(v.begin(), v.end(), 0);
    double size = v.size();
    // 산술평균
    std::cout << std::round(sum / size) << '\n';
    
    int mid_idx = (v.size() - 1) / 2;
    // 중앙값
    std::cout << v[mid_idx] << '\n';
    
    auto it1 = std::max_element(count.begin(), count.end());    // 최빈값을 찾음
    auto it2 = std::find(it1 + 1, count.end(), *it1);           // 최빈값이더있나?
    if(it2 != count.end()) {
        int index = std::distance(count.begin(), it2);
        // 최빈값중두번째
        std::cout << index - 4000 << '\n';
    } else  // 최빈값
        std::cout << std::distance(count.begin(), it1) - 4000 << '\n';
        
    std::cout << v[v.size() - 1] - v[0] << '\n';
}
