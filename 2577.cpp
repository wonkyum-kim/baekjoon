#include <iostream>
#include <vector>
#include <cmath>

int main()
{
	int a, b, c;
	std::cin >> a >> b >> c;
	int result = a * b * c;

	int i = 6;		

	while(i<=8)	
	{
		if (result / pow(10, i) >= 1)
			i++;
		else
			break;
	}

	int j = i-1;	
	
	std::vector<int> A(10);			

	while (j >= 0)	
	{
		int x = result / pow(10, j);

		if (x == 0)
			A[0] += 1;
		else
		{
			A[x] += 1;
			result -= x * pow(10, j);
		}
		j--;
	}
	
	for (auto& x : A)
		std::cout << x << '\n';
	return 0;
}
