#include <iostream>

void day_of_the_week(const int x, const int y)
{
	// 1일이 월요일.
	if (x == 1 || x == 10) {
		if (y % 7 == 0) {
			std::cout << "SUN";
		}
		else if (y%7 == 1) {
			std::cout << "MON";
		}
		else if (y % 7 == 2) {
			std::cout << "TUE";
		}
		else if (y % 7 == 3) {
			std::cout << "WED";
		}
		else if (y % 7 == 4) {
			std::cout << "THU";
		}
		else if (y % 7 == 5) {
			std::cout << "FRI";
		}
		else if (y % 7 == 6) {
			std::cout << "SAT";
		}
	}
	// 1일이 화요일.
	else if (x == 5) {
		if (y % 7 == 0) {
			std::cout << "MON";
		}
		else if (y % 7 == 1) {
			std::cout << "TUE";
		}
		else if (y % 7 == 2) {
			std::cout << "WED";
		}
		else if (y % 7 == 3) {
			std::cout << "THU";
		}
		else if (y % 7 == 4) {
			std::cout << "FRI";
		}
		else if (y % 7 == 5) {
			std::cout << "SAT";
		}
		else if (y % 7 == 6) {
			std::cout << "SUN";
		}
	}
	// 1일이 수요일.
	else if (x == 8) {
		if (y % 7 == 0) {
			std::cout << "TUE";
		}
		else if (y % 7 == 1) {
			std::cout << "WED";
		}
		else if (y % 7 == 2) {
			std::cout << "THU";
		}
		else if (y % 7 == 3) {
			std::cout << "FRI";
		}
		else if (y % 7 == 4) {
			std::cout << "SAT";
		}
		else if (y % 7 == 5) {
			std::cout << "SUN";
		}
		else if (y % 7 == 6) {
			std::cout << "MON";
		}
	}
	// 1일이 목요일
	else if (x == 2 || x == 3 || x == 11) {
		if (y % 7 == 0) {
			std::cout << "WED";
		}
		else if (y % 7 == 1) {
			std::cout << "THU";
		}
		else if (y % 7 == 2) {
			std::cout << "FRI";
		}
		else if (y % 7 == 3) {
			std::cout << "SAT";
		}
		else if (y % 7 == 4) {
			std::cout << "SUN";
		}
		else if (y % 7 == 5) {
			std::cout << "MON";
		}
		else if (y % 7 == 6) {
			std::cout << "TUE";
		}
	}
	// 1일이 금요일
	else if (x == 6) {
		if (y % 7 == 0) {
			std::cout << "THU";
		}
		else if (y % 7 == 1) {
			std::cout << "FRI";
		}
		else if (y % 7 == 2) {
			std::cout << "SAT";
		}
		else if (y % 7 == 3) {
			std::cout << "SUN";
		}
		else if (y % 7 == 4) {
			std::cout << "MON";
		}
		else if (y % 7 == 5) {
			std::cout << "TUE";
		}
		else if (y % 7 == 6) {
			std::cout << "WED";
		}
	}
	// 1일이 토요일
	else if (x == 9 || x == 12) {
	if (y % 7 == 0) {
			std::cout << "FRI";
		}
		else if (y % 7 == 1) {
			std::cout << "SAT";
		}
		else if (y % 7 == 2) {
			std::cout << "SUN";
		}
		else if (y % 7 == 3) {
			std::cout << "MON";
		}
		else if (y % 7 == 4) {
			std::cout << "TUE";
		}
		else if (y % 7 == 5) {
			std::cout << "WED";
		}
		else if (y % 7 == 6) {
			std::cout << "THU";
		}
}
	// 1일이 일요일
	else if (x == 4 || x == 7) {
		if (y % 7 == 0) {
			std::cout << "SAT";
		}
		else if (y % 7 == 1) {
			std::cout << "SUN";
		}
		else if (y % 7 == 2) {
			std::cout << "MON";
		}
		else if (y % 7 == 3) {
			std::cout << "TUE";
		}
		else if (y % 7 == 4) {
			std::cout << "WED";
		}
		else if (y % 7 == 5) {
			std::cout << "THU";
		}
		else if (y % 7 == 6) {
			std::cout << "FRI";
		}
	}
}


int main()
{
	int x = 0;
	int y = 0;
	std::cin >> x >> y;
	day_of_the_week(x, y);
}
