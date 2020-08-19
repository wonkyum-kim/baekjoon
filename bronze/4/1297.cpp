#include <iostream>
#include <cmath>

int main() 
{
	int diagonal, rheight, rwidth;
	std::cin>>diagonal>>rheight>>rwidth;
	
	auto ratio = std::sqrt(std::pow(diagonal, 2) / (std::pow(rheight,2)+pow(rwidth,2)));
	int height = rheight * ratio;
	int width = rwidth * ratio;
	std::cout << height <<' '<< width;
}
