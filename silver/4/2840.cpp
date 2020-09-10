#include<list>
#include<iostream>
#include <vector>
#include <algorithm>

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
		shift_left();
		return cd.front();
	}
	// prev access
	T prev() {
		cd.shift_right();
		return cd.front();
	}
	// empty
	bool empty() {
		return cd.empty() ? true : false;
	}

	// shift_right
	void shift_right() {
		T temp = cd.back();
		cd.pop_back();
		cd.push_front(temp);
	}

	// shift_left
	void shift_left() {
		T temp = cd.front();
		cd.pop_front();
		cd.push_back(temp);
	}

};

int main()
{
	int N = 0;
	int K = 0;
	std::cin >> N >> K;

	CircularDeque<char> cd;
	std::vector<char> v;

	for (auto i = 1; i <= N; ++i) {
		cd.push_back('?');
	}

	bool flag = true;
	for (auto i = 1; i <= K; ++i) {
		size_t change = 0;
		char input = 0;
		std::cin >> change >> input;

		for (auto j = 1; j <= change; ++j) {
			cd.shift_right();
		}
		// 아직 비어 있으면 삽입한다.
		if (cd.front() == '?') {
			cd.pop_front();
			cd.push_front(input);
			v.push_back(input);
		}
		// 같은 문자가 적혀 있으면 아무것도 하지 않는다.
		else if (cd.front() == input) {
		}
		// 비어있지않은 상태에서 다른 문자가 적혀 있으면 안된다.
		else {
			flag = false;
		}
	}

	// do not input same characters.
	std::sort(v.begin(), v.end());
	auto it = std::adjacent_find(v.begin(), v.end());
	if (it != v.end() && N != 1) {
		std::cout << '!';
		return 0;
	}

	if (flag) {
		std::cout << cd.front();
		for (auto i = 1; i < N; ++i) {
			std::cout << cd.next();
		}
	}
	else {
		std::cout << '!';
	}
}
