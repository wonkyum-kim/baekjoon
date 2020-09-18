#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

int main()
{
	int a = 0;
	int b = 0;
	std::cin >> a >> b;

	std::vector<int> A;
	std::vector<int> B;

	for (auto i = 0; i < a; ++i) {
		int temp = 0;
		std::cin >> temp;
		A.push_back(temp);
	}
	for (auto i = 0; i < b; ++i) {
		int temp = 0;
		std::cin >> temp;
		B.push_back(temp);
	}
	std::sort(A.begin(), A.end());
	std::sort(B.begin(), B.end());

	std::vector<int> diff1;
	std::vector<int> diff2;
	
	std::set_difference(A.begin(), A.end(), B.begin(), B.end(), std::inserter(diff1, diff1.begin()));
	std::set_difference(B.begin(), B.end(), A.begin(), A.end(), std::inserter(diff2, diff2.begin()));

	std::cout << diff1.size() + diff2.size();
}
