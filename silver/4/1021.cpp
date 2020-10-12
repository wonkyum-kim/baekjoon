#include <iostream>
#include <queue>
#include <vector>
#include <list>

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

void fill_cd(const int N, CircularDeque<int>& cd)
{
	for (auto i = 1; i <= N; ++i) {
		cd.push_back(i);
	}
}

void fill_key(const int M, std::vector<int>& key)
{
	for (auto i = 0; i < M; ++i) {
		int index = 0;
		std::cin >> index;
		key.push_back(index);
	}
}


int main()
{
	int n = 0;
	int m = 0;
	std::cin >> n >> m;

	CircularDeque<int> cd;
	fill_cd(n, cd);
	std::vector<int> key;
	fill_key(m, key);
	size_t count_total = 0;

	for (auto i = 0; i < m; ++i) {

		size_t count_left = 0;
		size_t count_right = 0;

		if (cd.front() == key[i]) {
			cd.pop_front();
		} 
		else {
			CircularDeque<int> temp1 = cd;
			CircularDeque<int> temp2 = cd;

			while (temp1.front()!=key[i]) {
				temp1.shift_left();
				count_left++;
			}
			while (temp2.front() != key[i]) {
				temp2.shift_right();
				count_right++;
			}
			if (count_left > count_right) {
				count_total += count_right;
				cd = temp2;
			}
			else {
				count_total += count_left;
				cd = temp1;
			}
			cd.pop_front();
		}
	}
	std::cout << count_total;
}
