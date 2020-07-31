#include <vector>
#include <iostream>
#include <string>

int main()
{
	std::string s;
	std::cin >> s;

	std::vector<char> alphabet{ 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
	std::vector<int> count(alphabet.size(), -1);

	for (auto i = 0; i < alphabet.size(); ++i)
	{
		for (auto j = 0; j < s.length(); ++j)
		{
			if (alphabet[i] == s[j] && count[i] == -1)
				count[i] = j;
		}
	}
	
	for (auto x : count)
		std::cout << x << ' ';
}
