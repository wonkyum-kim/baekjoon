#include <iostream>
#include <string>

int main()
{
  // 문자열에 숫자를 집어 넣는다.
	int num;
	std::string s;
	std::cin>>num>>s;
	int sum = 0;
  
  // 문자열을 문자로 하나씩 꺼내고 아스키 코드값을 정수 값으로 변환하기 위해 '0'을 뺀다.
	for(size_t i = 0; i<s.length(); i++)
	{
		sum += s[i] - '0';
	}
	std::cout<<sum;
}
