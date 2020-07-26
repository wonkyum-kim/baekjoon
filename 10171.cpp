#include <iostream>
#include <string>

int main()
{
	std::string s1 = R"(\    /\)";
	std::string s2 = R"( )  ( '))";
	std::string s3 = R"((  /  ))";
	std::string s4 = R"( \(__)|)";

	std::cout << s1 << '\n' << s2 << '\n' << s3 << '\n' << s4;
}
