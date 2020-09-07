#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>


// pivot : up-left point.

void tetromino(const std::vector<std::vector<int>>& cell, const int n, const int m) {
	int max_sum = -1;
	int running_sum = 0;

	// case1 : I mino
	/*
		----
	*/
	for (auto i = 1; i <= n; ++i) {
		for (auto j = 1; j <= m - 3; ++j) {
			running_sum += (cell[i][j] + cell[i][j+1] + cell[i][j+2] + cell[i][j+3]);
			max_sum = std::max(max_sum, running_sum);
			running_sum = 0;
		}
	}
	/*
		|
		|
		|
		|
	*/
	for (auto i = 1; i <= n - 3; ++i) {
		for (auto j = 1; j <= m; ++j) {
			running_sum += (cell[i][j] + cell[i+1][j] + cell[i+2][j] + cell[i+3][j]);
			max_sum = std::max(max_sum, running_sum);
			running_sum = 0;
		}
	}
	// case2 : O mino
	/*
		|--|
		|--|
	
	*/
	for (auto i = 1; i <= n - 1; ++i) {
		for (auto j = 1; j <= m - 1; ++j) {
			running_sum += (cell[i][j] + cell[i][j + 1] + cell[i + 1][j] + cell[i + 1][j + 1]);
			max_sum = std::max(max_sum, running_sum);
			running_sum = 0;
		}
	}
	// case3 : L mino
	/*
		|
		|
		|-
	*/
	for (auto i = 1; i <= n - 2; ++i) {
		for (auto j = 1; j <= m - 1; ++j) {
			running_sum += (cell[i][j] + cell[i + 1][j] + cell[i + 2][j] + cell[i + 2][j + 1]);
			max_sum = std::max(max_sum, running_sum);
			running_sum = 0;
		}
	}
	/*
		 |
		 |
		-|
	*/
	for (auto i = 1; i <= n - 2; ++i) {
		for (auto j = 2; j <= m; ++j) {
			running_sum += (cell[i][j] + cell[i + 1][j] + cell[i + 2][j] + cell[i + 2][j - 1]);
			max_sum = std::max(max_sum, running_sum);
			running_sum = 0;
		}
	}
	/*
		-|
		 |
		 |
	
	*/
	for (auto i = 1; i <= n - 2; ++i) {
		for (auto j = 1; j <= m - 1; ++j) {
			running_sum += (cell[i][j] + cell[i][j + 1] + cell[i + 1][j + 1] + cell[i + 2][j + 1]);
			max_sum = std::max(max_sum, running_sum);
			running_sum = 0;
		}
	}
	/*
		 |-
		 |
		 |
	*/
	for (auto i = 1; i <= n - 2; ++i) {
		for (auto j = 1; j <= m - 1; ++j) {
			running_sum += (cell[i][j] + cell[i][j + 1] + cell[i + 1][j] + cell[i + 2][j]);
			max_sum = std::max(max_sum, running_sum);
			running_sum = 0;
		}
	}
	/*
		|
		- - -
	*/
	for (auto i = 1; i <= n - 1; ++i) {
		for (auto j = 1; j <= m - 2; ++j) {
			running_sum += (cell[i][j] + cell[i + 1][j] + cell[i + 1][j + 1] + cell[i + 1][j + 2]);
			max_sum = std::max(max_sum, running_sum);
			running_sum = 0;
		}
	}
	/*
		    |
		- - -
	*/
	for (auto i = 1; i <= n - 1; ++i) {
		for (auto j = 3; j <= m; ++j) {
			running_sum += (cell[i][j] + cell[i + 1][j] + cell[i + 1][j - 1] + cell[i + 1][j - 2]);
			max_sum = std::max(max_sum, running_sum);
			running_sum = 0;
		}
	}
	/*
		- - -
		     |
	*/
	for (auto i = 1; i <= n - 1; ++i) {
		for (auto j = 1; j <= m - 2; ++j) {
			running_sum += (cell[i][j] + cell[i][j + 1] + cell[i][j + 2] + cell[i + 1][j + 2]);
			max_sum = std::max(max_sum, running_sum);
			running_sum = 0;
		}
	}
	/*
		- - -
		|
	*/
	for (auto i = 1; i <= n - 1; ++i) {
		for (auto j = 1; j <= m - 2; ++j) {
			running_sum += (cell[i][j] + cell[i + 1][j] + cell[i][j + 1] + cell[i][j + 2]);
			max_sum = std::max(max_sum, running_sum);
			running_sum = 0;
		}
	}
	// case4 : S mino
	/*
	shape :
	   |--
	 --|
	*/
	for (auto i = 2; i <= n; ++i) {
		for (auto j = 1; j  <= m - 2; ++j) {
			running_sum += (cell[i][j] + cell[i][j + 1] + cell[i - 1][j + 1] + cell[i - 1][j + 2]);
			max_sum = std::max(max_sum, running_sum);
			running_sum = 0;
		}
	}
	/*
	shape :
	  --|
		|--
	*/

	for (auto i = 1; i <= n - 1; ++i) {
		for (auto j = 1; j <= m - 2; ++j) {
			running_sum += (cell[i][j] + cell[i][j + 1] + cell[i + 1][j + 1] + cell[i + 1][j + 2]);
			max_sum = std::max(max_sum, running_sum);
			running_sum = 0;
		}
	}
	/*
	shape :
	|
	ㄴㄱ
	   |
	*/
	for (auto i = 1; i <= n - 2; ++i) {
		for (auto j = 1; j <= m - 1; ++j) {
			running_sum += (cell[i][j] + cell[i + 1][j] + cell[i + 1][j + 1] + cell[i + 2][j + 1]);
			max_sum = std::max(max_sum, running_sum);
			running_sum = 0;
		}
	}
	/*
	shape :
	   |
	|--|
	|
	*/
	for (auto i = 3; i <= n; ++i) {
		for (auto j = 1; j <= m - 1; ++j) {
			running_sum += (cell[i][j] + cell[i - 1][j] + cell[i - 1][j + 1] + cell[i - 2][j + 1]);
			max_sum = std::max(max_sum, running_sum);
			running_sum = 0;
		}
	}
	// case5 : T mino
	/*
	shape :
	 |
	---
	*/
	for (auto i = 1; i <= n - 1; ++i) {
		for (auto j = 2; j <= m - 1; ++j) {
			running_sum += (cell[i][j] + cell[i + 1][j] + cell[i + 1][j - 1] + cell[i + 1][j + 1]);
			max_sum = std::max(max_sum, running_sum);
			running_sum = 0;
		}
	}
	/*
	shape :
	---
	 |
	*/
	for (auto i = 1; i <= n - 1; ++i) {
		for (auto j = 1; j <= m - 2; ++j) {
			running_sum += (cell[i][j] + cell[i][j + 1] + cell[i][j + 2] + cell[i + 1][j + 1]);
			max_sum = std::max(max_sum, running_sum);
			running_sum = 0;
		}
	}
	/*
	shape :
	|
	|--
	|
	*/
	for (auto i = 1; i <= n - 2; ++i) {
		for (auto j = 1; j <= m - 1; ++j) {
			running_sum += (cell[i][j] + cell[i + 1][j] + cell[i + 1][j + 1] + cell[i + 2][j]);
			max_sum = std::max(max_sum, running_sum);
			running_sum = 0;
		}
	}

	/*
	shape :
	  |
	--|
	  |
	*/
	for (auto i = 1; i <= n - 2; ++i) {
		for (auto j = 2; j <= m; ++j) {
			running_sum += (cell[i][j] + cell[i + 1][j] + cell[i + 1][j - 1] + cell[i + 2][j]);
			max_sum = std::max(max_sum, running_sum);
			running_sum = 0;
		}
	}

	std::cout << max_sum;
}


int main()
{
	int n = 0;
	int m = 0;
	std::cin >> n >> m;

	// 0행과 0열은 비어둔다.
	std::vector<std::vector<int>> cell(n + 1, std::vector<int>(m + 1));

	for (auto i = 1; i <= n; ++i) {
		for (auto j = 1; j <= m; ++j) {
			std::cin >> cell[i][j];
		}
	}

	tetromino(cell, n, m);

}
