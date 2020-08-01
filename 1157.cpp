#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::string s;
	std::cin >> s;

	std::vector<int> count(26);

	if (s.length() == 1)
	{
		if (s[0] <= 90)
			std::cout << s[0];
		else
			std::cout << static_cast<char>(s[0] - 32);
		return 0;
	}
	else
	{
		for (auto i = 0; i < s.length(); ++i)
		{
			if (s[i] <= 90)
				count[static_cast<size_t>(s[i] - 65)]++;
			else if(s[i] >= 97)
				count[static_cast<size_t>(s[i] - 97)]++;
		}
	}

	int max = 0;

	for (auto i = 0; i < count.size(); ++i)
	{
		if (count[max] <= count[i])
			max = i;
	}

	for (auto i = 0; i < count.size(); ++i)
	{
		if (count[max] == count[i] && i != max)
		{
			std::cout << '?';
			return 0;
		}
	}

	char a = static_cast<char>(max + 65);
	std::cout << a;
}
