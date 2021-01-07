#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <set>

using points = std::vector<std::pair<int, int>>;
using point = std::pair<int, int>;

int dist(point& p1, point& p2)
{
	int x = (p1.first - p2.first) * (p1.first - p2.first);
	int y = (p1.second - p2.second) * (p1.second - p2.second);
	return x + y;
}

int dnc(points& X, points& Y, int n)
{
	if (n == 2) {
		return dist(X[0], X[1]);
	}
	if (n == 3) {
		return std::min({ dist(X[0],X[1]), dist(X[1],X[2]), dist(X[0],X[2]) });
	}

	int mid = n / 2 ;
	points PL;
	points PR;
	std::set<point> lookup;
	for (auto i = 0; i < mid; ++i) {
		PL.push_back(X[i]);
		lookup.insert(X[i]);
	}
	for (auto i = mid; i < n; ++i) {
		PR.push_back(X[i]);
	}
	points& XL = PL;
	points& XR = PR;
	points YL(PL.size());
	points YR(PR.size());

	int yl = -1;
	int yr = -1;
	for (auto i = 0; i < n; ++i) {
		auto it = lookup.find(Y[i]);
		if (it != lookup.end()) {
			yl++;
			YL[yl] = Y[i];
		}
		else {
			yr++;
			YR[yr] = Y[i];
		}
	}


	int dl = dnc(XL, YL, n / 2);
	int dr = dnc(XR, YR, n - n / 2);
	int d = std::min(dl, dr);

	points YY;
	int line_x = (X[mid - 1].first + X[mid].first) / 2;
	for (auto i = 0; i < n; ++i) {
		int temp = Y[i].first - line_x;
		if (temp * temp < d) {
			YY.push_back(Y[i]);
		}
	}

	int yy_size = YY.size();
	for (auto i = 0; i < yy_size - 1; ++i) {
		for (auto j = i + 1; j < yy_size && ((YY[j].second - YY[i].second) * (YY[j].second - YY[i].second)) < d; ++j) {
			d = std::min(d, dist(YY[i], YY[j]));
		}
	}

	return d;
}

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	int n = 0;
	std::cin >> n;
	points p;
	for (auto i = 0; i < n; ++i) {
		int x = 0;
		int y = 0;
		std::cin >> x >> y;
		p.push_back({ x,y });
	}
	points X;
	points Y;
	std::sort(p.begin(), p.end());
	X = p;
	auto it = std::adjacent_find(p.begin(), p.end());
	if (it != p.end()) {
		std::cout << 0;
		return 0;
	}
	auto comp = [](auto a, auto b) {return a.second != b.second ? a.second < b.second : a.first < b.first; };
	std::sort(p.begin(), p.end(), comp);
	Y = p;
	std::cout << dnc(X, Y, n);
}
