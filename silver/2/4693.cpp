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
		bool is_land = false;
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

	void set_land(size_t a) {
		info[a].is_land = true;
	}

	void check_cc() {
		std::vector<size_t> temp;
		for (auto i = 0; i < n; ++i) {
			if (info[i].cc != 0) {
				temp.emplace_back(info[i].cc);
			}
		}
		std::sort(temp.begin(), temp.end());
		auto last = std::unique(temp.begin(), temp.end());
		temp.erase(last, temp.end());
		std::cout << temp.size() << '\n';
	}

	void DFS() {
		size_t k = 1;
		for (auto i = 0; i < n; ++i) {
			if (info[i].color == Color::White && info[i].is_land) {
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
			if (info[v].color == Color::White && info[v].is_land) {
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
	// 1은 땅, 0은 바다
	while (true) {
		int w = 0;
		int h = 0;
		std::cin >> w >> h;
		if (w == 0 && h == 0) {
			break;
		}
		Graph g(h * w, Graph_Type::Undirected);
		std::vector<std::vector<int>> map(h, std::vector<int>(w));
		for (auto i = 0; i < h; ++i) {
			for (auto j = 0; j < w; ++j) {
				std::cin >> map[i][j];
				if (map[i][j] == 1) {
					g.set_land(i * w + j);
				}
			}
		}
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				if (map[i][j] == 1) {
					if (i + 1 < h && map[i + 1][j] == 1) {
						g.add_edge(i * w + j, (i + 1) * w + j);
					}
					if (j + 1 < w && map[i][j + 1] == 1) {
						g.add_edge(i * w + j, i * w + j + 1);
					}
					if (i + 1 < h && j + 1 < w && map[i + 1][j + 1] == 1) {
						g.add_edge(i * w + j, (i + 1) * w + j + 1);
					}
					if (i + 1 < h && j - 1 > -1 && map[i + 1][j - 1] == 1) {
						g.add_edge(i * w + j, (i + 1) * w + j - 1);
					}
				}
			}
		}
		g.DFS();
		g.check_cc();
	}
}
