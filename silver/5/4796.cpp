#include <iostream>

int main()
{
	int count = 1;    
  int l, p, v;

    while(true) {
        std::cin >> l >> p >> v;
        if (l == 0 && p == 0 && v == 0) {
            break;
        }
        int a = v / p;
        if (l >= (v - a * p)) {
            std::cout << "Case " << count++ << ": " << l * a + v - a * p << '\n';
        }
        else {
            std::cout << "Case " << count++ << ": " << l * a + l << '\n';
        }
    }
    return 0;
}
