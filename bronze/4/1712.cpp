#include <iostream>
#include <vector>

int main()
{
	long long A, B, C;
	std::cin>>A>>B>>C;
	
	if(C<=B)
		std::cout<<-1;
	else
	{
		long long temp = static_cast<long long>(A/(C-B));
		std::cout<<temp+1;
	}
		
}
