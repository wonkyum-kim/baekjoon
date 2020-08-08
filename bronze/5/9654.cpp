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

//***//

#include <iostream>
#include <iomanip>

int main()
{
	std::cout.setf(std::ios::left);
	std::cout << std::setw(15) << "SHIP NAME" << std::setw(15) << "CLASS" << std::setw(11) << "DEPLOYMENT" << std::setw(10) << "IN SERVICE" << '\n';
	std::cout << std::setw(15) << "N2 Bomber" << std::setw(15) << "Heavy Fighter" << std::setw(11) << "Limited" << std::setw(10) << "21" << '\n';
	std::cout << std::setw(15) << "J-Type 327" << std::setw(15) << "Light Combat" << std::setw(11) << "Unlimited" << std::setw(10) << "1" << '\n';
	std::cout << std::setw(15) << "NX Cruiser" << std::setw(15) << "Medium Fighter" << std::setw(11) << "Limited" << std::setw(10) << "18" << '\n';
	std::cout << std::setw(15) << "N1 Starfighter" << std::setw(15) << "Medium Fighter" << std::setw(11) << "Unlimited" << std::setw(10) << "25" << '\n';
	std::cout << std::setw(15) << "Royal Cruiser" << std::setw(15) << "Light Combat" << std::setw(11) << "Limited" << std::setw(10) << "4" << '\n';
}

