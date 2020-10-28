#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <utility>
#include <cmath>

int main()
{
	int test_case = 0;
	std::cin >> test_case;
	for (auto i = 0; i < test_case; ++i) {
		int x1 = 0;
		int x2 = 0;
		int y1 = 0;
		int y2 = 0;
		std::cin >> x1 >> y1 >> x2 >> y2;
		std::pair<int, int> start = { x1, y1 };
		std::pair<int, int> end = { x2,y2 };
		int planet = 0;
		std::cin >> planet;
		std::vector<std::vector<int>> pos(planet, std::vector<int>(3));
		for (auto i = 0; i < planet; ++i) {
			std::cin >> pos[i][0] >> pos[i][1] >> pos[i][2];
		}
		
		// 시작점을 포함하고 있는 행성들의 반지름을 저장
		std::vector<int> include1(planet);	
		// 끝점을 포함하고 있는 행성들의 반지름을 저장
		std::vector<int> include2(planet);

		for (auto i = 0; i < planet; ++i) {
			// 시작점, 끝점과 각 행성과의 거리.
			auto diff1 = std::sqrt(std::pow(start.first - pos[i][0], 2) + std::pow(start.second - pos[i][1], 2));
			auto diff2 = std::sqrt(std::pow(end.first - pos[i][0], 2) + std::pow(end.second - pos[i][1], 2));
			// 시작점, 끝점과 행성과의 거리가 행성의 반지름 보다 같거나 작다면 후보에 추가한다.
			if (diff1 <= pos[i][2]) {
				include1[i] = pos[i][2];
			}
			if (diff2 <= pos[i][2]) {
				include2[i] = pos[i][2];
			}
		}

		auto temp1 = std::find_if(include1.begin(), include1.end(), [](int i) {return i != 0; });
		auto temp2 = std::find_if(include2.begin(), include2.end(), [](int i) {return i != 0; });

		// case 1 : 한 점만 원에 들어가 있는 경우
		// 시작점만 원 안에 들어가 있는 경우
		if (temp1 != include1.end() && temp2 == include2.end()) {
			std::cout << std::count_if(include1.begin(), include1.end(), [](int i) {return i != 0; }) << '\n';
		}
		// 끝점만 원 안에 들어가 있는 경우
		else if (temp1 == include1.end() && temp2 != include2.end()) {
			std::cout << std::count_if(include2.begin(), include2.end(), [](int i) {return i != 0; }) << '\n';
		}

		// case 2 : 두 점 모두 원 안에 들어가 있는 경우
		if (temp1 != include1.end() && temp2 != include2.end()) {
			for (auto i = 0; i < planet; ++i) {
				if (include1[i] != 0 && include1[i] == include2[i]) {
					include1[i] = 0;
					include2[i] = 0;
				}
			}
			int num1 = std::count_if(include1.begin(), include1.end(), [](int i) {return i != 0; });
			int num2 = std::count_if(include2.begin(), include2.end(), [](int i) {return i != 0; });
			std::cout << num1 + num2 << '\n';
		}

		// case 3 : 두 점 모두 원 안에 들어가 있지 않은 경우
		if (temp1 == include1.end() && temp2 == include2.end()) {
			std::cout << 0 << '\n';
		}
	}
}
