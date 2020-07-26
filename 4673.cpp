#include <vector>
#include <iostream>
#include <algorithm>


void number(std::vector<int>& A)
{
	// n 벡터에 1 부터 10000까지 넣어둔다.
	for (size_t i = 0; i < 10000; ++i)
		A.push_back(i + 1);
}

void dnnumber(std::vector<int>& A, std::vector<int>& B)
{
	// n으로 만들 수 있는 수를 dn벡터에 넣어둔다.
	for (size_t i = 0; i < 10000; ++i)
	{
		int result = A[i];
		int temp = A[i];

		while (temp > 0)
		{
			int y = temp % 10;
			result += y;
			temp /= 10;
		}
		B.push_back(result);
	}
}

int main()
{
	std::vector<int> n;
	std::vector<int> diff;	// n에서 n과 dn의 교집합을 뺌
	std::vector<int> dn;

	number(n);
	dnnumber(n, dn);
	

	// 정렬하고 중복제거 한 dn
	std::sort(dn.begin(), dn.end());
	auto last = std::unique(dn.begin(), dn.end());
	dn.erase(last, dn.end());
	dn.shrink_to_fit();

	std::set_difference(n.begin(), n.end(), dn.begin(), dn.end(), std::inserter(diff, diff.begin()));
	

	for (auto x : diff)
		std::cout << x << '\n';
		
}
