#include <iostream>

int main()
{
	int ax, ay, az;
	int cx, cy, cz;
	std::cin >>ax >> ay >> az >> cx >> cy >> cz;
	std::cout << cx - az << ' ' << cy / ay << ' ' << cz - ax;
}
