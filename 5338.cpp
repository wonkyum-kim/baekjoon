#include <iostream>
#include <string>

int main()
{
    std::string s1 = R"(       _.-;;-._)";
    std::string s2 = R"('-..-'|   ||   |)";
    std::string s3 = R"('-..-'|_.-;;-._|)";
    std::string s4 = R"('-..-'|   ||   |)";
    std::string s5 = R"('-..-'|_.-''-._|)";
    
    std::cout<<s1<<'\n'<<s2<<'\n'<<s3<<'\n'<<s4<<'\n'<<s5;
}
