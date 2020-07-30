#include <cstdio>

int main()
{
	std::printf("%-15s%-15s%-11s%-10s\n", "SHIP NAME", "CLASS", "DEPLOYMENT", "IN SERVICE");
	std::printf("%-15s%-15s%-11s%-10s\n", "N2 Bomber", "Heavy Fighter", "Limited", "21");
	std::printf("%-15s%-15s%-11s%-10s\n", "J-Type 327", "Light Combat", "Unlimited", "1");
	std::printf("%-15s%-15s%-11s%-10s\n", "NX Cruiser", "Medium Fighter", "Limited", "18");
	std::printf("%-15s%-15s%-11s%-10s\n", "N1 Starfighter", "Medium Fighter", "Unlimited", "25");
	std::printf("%-15s%-15s%-11s%-10s", "Royal Cruiser", "Light Combat", "Limited", "4");
}
