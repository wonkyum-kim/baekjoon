#include<iostream>
#include <vector>
#include <cmath>

int dc(int n, int r, int c)
{
	// 4분할 했을 때 한 변의 길이
	int size = std::pow(2, n - 1);

	if (n == 0) {
		return 0;
	}
	// 사각형 상단에 위치
	if (r < size) {
		// 왼쪽
		if (c < size) {
			return dc(n-1,r,c);
		}
		// 오른쪽
		else {
			return size * size + dc(n - 1, r, c - size);
		}
	}
	// 사각형 하단에 위치
	else {
		// 왼쪽
		if (c < size) {
			return size * size * 2 +  dc(n - 1, r - size, c);
		}
		// 오른쪽
		else {
			return size * size * 3 + dc(n - 1, r - size, c - size);
		}
	}
}


int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	int n = 0;
	int r = 0;
	int c = 0;
	std::cin >> n >> r >> c;
	std::cout << dc(n, r, c);
}
