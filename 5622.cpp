#include <iostream>
#include <string>

int main()
{
	std::string s;
	std::cin >> s;
	int count = 0;

	for (auto p = s.begin(); p != s.end(); ++p)
	{
		if (*p == 'A' || *p == 'B' || *p == 'C')
			count += 3;
		else if (*p == 'D' || *p == 'E' || *p == 'F')
			count += 4;
		else if (*p == 'G' || *p == 'H' || *p == 'I')
			count += 5;
		else if (*p == 'J' || *p == 'K' || *p == 'L')
			count += 6;
		else if (*p == 'M' || *p == 'N' || *p == 'O')
			count += 7;
		else if (*p == 'P' || *p == 'Q' || *p == 'R' || *p == 'S')
			count += 8;
		else if (*p == 'T' || *p == 'U' || *p == 'V')
			count += 9;
		else if (*p == 'W' || *p == 'X' || *p == 'Y' || *p == 'Z')
			count += 10;
	}
	std::cout << count;
}
