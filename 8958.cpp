#include <iostream>
#include <vector>
#include <string>

int main()
{
	std::vector<std::string> A;
	int n = 0;
	std::cin >> n;	//문자열 개수 입력

	for (size_t i = 0; i < n; ++i)	// 문자열 입력
	{
		std::string OX;
		std::cin >> OX;
		A.push_back(OX);
	}

	int count = 0;
	int sum = 0;

	for (size_t i = 0; i < n; ++i)	// 문자열의 개수만큼
	{
		for (size_t j = 0; j < A[i].length(); j++)	// 문자열의 길이 만큼
		{
			if (A[i].at(j) == 'O')
			{
				count++;
				sum += count;
			}
			else
				count = 0;
		}

		std::cout << sum << '\n';
		sum = 0;
		count = 0;
	}
}
