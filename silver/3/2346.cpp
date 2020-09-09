
#include<list>
#include<iostream>
#include <utility>

template<typename T>
struct CircularDeque {
	std::list<T> cd;

	// front access
	T front() {
		return cd.front();
	}
	// back access
	T back() {
		return cd.back();
	}
	// push_front
	void push_front(const T& key) {
		cd.push_front(key);
	}
	// push_back
	void push_back(const T& key) {
		cd.push_back(key);
	}
	// pop_front
	void pop_front() {
		cd.pop_front();
	}
	// pop_back
	void pop_back() {
		cd.pop_front();
	}
	// next access
	T next() {
		// shift left
		T temp = cd.front();
		cd.pop_front();
		cd.push_back(temp);
		return cd.front();
	}
	// prev access
	T prev() {
		// shift right
		T temp = cd.back();
		cd.pop_back();
		cd.push_front(temp);
		return cd.front();
	}
	// empty
	bool empty() {
		return cd.empty() ? true : false;
	}
};

int main()
{
	int N = 0;
	std::cin >> N;
	CircularDeque<std::pair<int, int>> cd;

	for (auto i = 1; i <= N; ++i) {
		int temp = 0;
		std::cin >> temp;
		cd.push_back({ temp, i });
	}

	while (true) {
		std::pair<int, int> ballon = cd.front();
		std::cout << ballon.second << ' ';
		cd.pop_front();
		int loop = ballon.first;
		if (cd.empty()) {
			break;
		}

		if (ballon.first > 0) {
			for (auto i = 1; i < loop; ++i) {
				ballon = cd.next();
			}
		}
		else if (ballon.first < 0) {
			for (auto i = 1; i <= -1 * loop; ++i) {
				ballon = cd.prev();
			}
		}

	}
}
