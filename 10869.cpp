#include <iostream>

using namespace std;

int main()
{
	auto A = 0, B = 0;
	cin >> A >> B;
	if (A >= 1 && B <= 10000)
		cout << A + B << '\n' << A - B << '\n' << A * B << '\n' << A / B << '\n' << A % B;
	return 0;
}
