#include <iostream>
#include <string>

int main()
{
	std::string s;
	getline(std::cin, s);
	char sp = 32;
	int count = 0;

	if (s[0] == sp)
	{
		for (auto i = 0; i < s.length() - 1; ++i)
		{
			if (s[i] == sp && s[i + 1] != sp)
				count++;
		}
		std::cout << count;
	}
	else
	{
		for (auto i = 0; i < s.length() - 1; ++i)
		{
			if (s[i] == sp && s[i + 1] != sp)
				count++;
		}
		std::cout << count + 1;
	}
}
