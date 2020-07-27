#include <iostream>
#include <vector>
#include <string>

int main()
{
	std::string s1 = R"(.  .   .)";
	std::string s2 = R"(|  | _ | _. _ ._ _  _)";
	std::string s3 = R"(|/\|(/.|(_.(_)[ | )(/.)";
	std::cout << s1 << '\n' << s2 << '\n' << s3;
}
