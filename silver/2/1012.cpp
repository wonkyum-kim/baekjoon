#include <iostream>
#include <vector>
#include <algorithm>

enum class Graph_Type {
	Directed, Undirected
};

class Graph {
private:
	using vertex = size_t;
	using edge_weight = double;

	enum class Color {
		White, Gray, Black
	};

	struct vertex_info {
		Color color = Color::White;
		size_t d = 0;
		int parent = -1;
		size_t cc = 0;
		bool is_baechu = false;
	};

	vertex n;
	Graph_Type g_type;
	std::vector<std::vector<vertex>> adj;
	std::vector<vertex_info> info;
	size_t time = 0;

public:
	Graph(vertex n, Graph_Type g_type) : n{ n }, g_type{ g_type }, adj(n), info(n){}

	void add_edge(const vertex& u, const vertex& v) {
		adj[u].push_back(v);
		if (g_type == Graph_Type::Undirected) {
			adj[v].push_back(u);
		}
	}

	void foo(size_t a) {
		info[a].is_baechu = true;
	}


	void DFS() {
		time = 0;
		size_t k = 1;
		for (auto i = 0; i < n; ++i) {
			if (info[i].color == Color::White && info[i].is_baechu) {
				info[i].cc = k;
				++k;
				DFS_visit(i, k);
			}
		}
		std::cout << k-1 << '\n';
	}

private:
	void DFS_visit(const vertex& u, const size_t& k) {
		++time;
		info[u].d = time;
		info[u].color = Color::Gray;
		for (auto v : adj[u]) {
			info[v].cc = info[u].cc;
			if (info[v].color == Color::White && info[v].is_baechu) {
				info[v].parent = u;
				DFS_visit(v, k);
			}
		}
		info[u].color = Color::Black;
	}

};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int t = 0;
	std::cin >> t;
	for (auto i = 0; i < t; ++i) {
		int m = 0;
		int n = 0;
		int k = 0;
		std::cin >> m >> n >> k;
		Graph g(n * m, Graph_Type::Undirected);
		std::vector<std::vector<bool>> baechu(n, std::vector<bool>(m, false));
		for (auto j = 0; j < k; ++j) {
			int x = 0;
			int y = 0;
			std::cin >> x >> y;
			baechu[y][x] = true;
			g.foo(y * m + x);
		}

		for (auto r = 0; r < n; ++r) {
			for (auto c = 0; c < m; ++c) {
				if (baechu[r][c]) {
					if (r + 1 < n && baechu[r + 1][c]) {
						g.add_edge(r * m + c, (r + 1) * m + c);
					}
					if (c + 1 < m && baechu[r][c]) {
						g.add_edge(r * m + c, r * m + c + 1);
					}
				}
			}
		}
		g.DFS();
	}
}
