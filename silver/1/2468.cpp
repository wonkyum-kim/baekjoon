#include <iostream>
#include <vector>
#include <algorithm>

enum class Graph_Type {
	Directed, Undirected
};

class Graph {
private:

	enum class Color {
		White, Gray, Black
	};

	struct vertex_info {
		Color color = Color::White;
		size_t cc = 0;
		bool is_water = false;
	};

	size_t n;
	Graph_Type type;
	std::vector<std::vector<size_t>> adj;
	std::vector<vertex_info> info;

public:
	Graph(size_t n, Graph_Type type) : n{n},type{type},adj(n),info(n){}

	void add_edge(size_t u, size_t v) {
		adj[u].push_back(v);
		if (type == Graph_Type::Undirected) {
			adj[v].push_back(u);
		}
	}

	void set_water(size_t a) {
		info[a].is_water = true;
	}

	int check_cc() {
		std::vector<size_t> temp;
		for (auto i = 0; i < n; ++i) {
			if (info[i].cc != 0) {
				temp.emplace_back(info[i].cc);
			}
		}
		std::sort(temp.begin(), temp.end());
		auto last = std::unique(temp.begin(), temp.end());
		temp.erase(last, temp.end());
		return temp.size();
	}

	void DFS() {
		size_t k = 1;
		for (auto i = 0; i < n; ++i) {
			if (info[i].color == Color::White && !info[i].is_water) {
				info[i].cc = k;
				++k;
				DFS_visit(i);
			}
		}
	}

private:
	void DFS_visit(size_t u) {
		info[u].color = Color::Gray;
		for (auto v : adj[u]) {
			info[v].cc = info[u].cc;
			if (info[v].color == Color::White && !info[v].is_water) {
				DFS_visit(v);
			}
		}
		info[u].color = Color::Black;
	}

};

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	int n = 0;
	std::cin >> n;
	std::vector<std::vector<int>> map(n, std::vector<int>(n));
	int max_height = 0;
	for (auto i = 0; i < n; ++i) {
		for (auto j = 0; j < n; ++j) {
			std::cin >> map[i][j];
			max_height = std::max(max_height, map[i][j]);
		}
	}

	std::vector<int> temp;
	for (int i = 0; i <= max_height; ++i) {
		Graph g(n * n, Graph_Type::Undirected);
		for (auto a = 0; a < n; ++a) {
			for (auto b = 0; b < n; ++b) {
				if (map[a][b] <= i) {
					g.set_water(a * n + b);
				}
			}
		}
		for (int a = 0; a < n; ++a) {
			for (int b = 0; b < n; ++b) {
				if (map[a][b] > i) {
					if (a + 1 < n && map[a + 1][b] > i) {
						g.add_edge(a * n + b, (a + 1) * n + b);
					}
					if (b + 1 < n && map[a][b + 1] > i) {
						g.add_edge(a * n + b, a * n + b + 1);
					}
				}
			}
		}

		g.DFS();
		temp.push_back(g.check_cc());
	}
	std::cout << *max_element(temp.begin(), temp.end());
}
