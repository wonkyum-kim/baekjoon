#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
	int test = 0;
	std::cin >> test;

	std::vector<bool> baseball(1000, false);
	for (auto i = 1; i <= 9; ++i) {
		for (auto j = 1; j <= 9; ++j) {
			for (auto k = 1; k <= 9; ++k) {
				if (i != j && i != k && j != k) {
					baseball[i * 100 + j * 10 + k] = true;
				}
			}
		}
	}

	for (auto i = 0; i < test; ++i) {
		int thrown = 0;
		int strike = 0;
		int ball = 0;
		std::cin >> thrown >> strike >> ball;
		int thrown_a = thrown / 100;
		int thrown_c = thrown % 10;
		int thrown_b = (thrown - thrown_c - thrown_a * 100) / 10;
		for (auto j = 123; j <= 999; ++j) {
			if (baseball[j] == true) {
				int check_a = j / 100;
				int check_c = j % 10;
				int check_b = (j - check_c - check_a * 100) / 10;
				int temp_strike = 0;
				int temp_ball = 0;
				if (thrown_a == check_a) {
					temp_strike++;
				}
				if (thrown_b == check_b) {
					temp_strike++;
				}
				if (thrown_c == check_c) {
					temp_strike++;
				}
				if (thrown_a == check_b || thrown_a == check_c) {
					temp_ball++;
				}
				if (thrown_b == check_a || thrown_b == check_c) {
					temp_ball++;
				}
				if (thrown_c == check_a || thrown_c == check_b) {
					temp_ball++;
				}
				if (temp_ball != ball || temp_strike != strike) {
					baseball[j] = false;
				}
			}
		}
	}
	int possible = std::count(baseball.begin() + 123, baseball.end(), true);
	std::cout << possible;
}
