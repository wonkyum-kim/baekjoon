#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <numeric>
#include <queue>
#include <utility>

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

	vertex n;
	Graph_Type type;
	std::vector<std::vector<std::pair<size_t, int>>> adj;
	int diameter = 0;
	int end_point = 0;

public:
	Graph(size_t n, Graph_Type dir) : n{ n }, type{ dir }, adj(n) {}

	void add_edge(size_t u, size_t v, int w) {
		adj[u].push_back({ v,w });
		if (type == Graph_Type::Undirected) {
			adj[v].push_back({ u, w });
		}
	}

	using vertex_info = std::tuple<Color, size_t, size_t, size_t>;	// u.color, u.d, u.f, u.phi

	void DFS(size_t point) {
		std::vector<vertex_info> info(n, { Color::White, 0, 0, -1 });
		size_t time = 0;
		int length = 0;
		for (auto i = point; i < n; ++i) {
			if (std::get<0>(info[i]) == Color::White) {
				DFS_visit(i, time, info, length);
			}
		}
	}

	int tree_diameter() {
		DFS(0);
		DFS(end_point);
		return diameter;
	}

private:
	void DFS_visit(size_t u, size_t& time, std::vector<vertex_info>& info, int length) {
		++time;
		std::get<1>(info[u]) = time;
		std::get<0>(info[u]) = Color::Gray;
		if (diameter < length) {
			diameter = length;
			end_point = u;
		}
		for (auto v : adj[u]) {
			if (std::get<0>(info[v.first]) == Color::White) {
				std::get<3>(info[v.first]) = u;
				DFS_visit(v.first, time, info, length + v.second);
			}
		}
		std::get<0>(info[u]) = Color::Black;
		++time;
		std::get<2>(info[u]) = time;
	}
};

int main()
{
	int n = 0;
	std::cin >> n;
	Graph g(n, Graph_Type::Undirected);
	for (auto i = 0; i < n - 1; ++i) {
		int p = 0;
		int c = 0;
		int w = 0;
		std::cin >> p >> c >> w;
		g.add_edge(p - 1, c - 1, w);
	}
	std::cout << g.tree_diameter();
}
