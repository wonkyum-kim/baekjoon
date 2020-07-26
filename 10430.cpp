#include <iostream>

int main()
{
	auto A = 0, B = 0, C = 0;
	std::cin >> A >> B >> C;

	int arr[] = { A,B,C };
	for (auto x : arr)
	{
		if (x >= 2 && x <= 10000)
			break;
		else
			std::cout << "error";
	}
	std::cout << (A + B) % C << '\n' << ((A % C) + (B % C)) % C << '\n' << (A * B) % C << '\n' << ((A % C) * (B % C)) % C;
	return 0;
}
