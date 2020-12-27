#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <numeric>
#include <stack>
#include <utility>
#include <queue>

enum class Graph_Type {
	Directed, Undirected
};

class Graph {
private:
	using vertex = size_t;
	using edge_weight = double;
	using edge = std::tuple<vertex, vertex, edge_weight>;

	enum class Color {
		White, Gray, Black
	};

	vertex n;
	Graph_Type type;
	std::vector<std::vector<size_t>> adj;

public:
	Graph(size_t n, Graph_Type dir) : n{ n }, type{ dir }, adj(n) {}

	void add_edge(size_t u, size_t v) {
		adj[u].push_back(v);
		if (type == Graph_Type::Undirected) {
			adj[v].push_back(u);
		}
	}

	void sort_adj() {
		for (auto i = 0; i < n; ++i) {
			std::sort(adj[i].begin(), adj[i].end());
		}
	}

	using vertex_info1 = std::tuple<Color, size_t, size_t, size_t>;	// u.color, u.d, u.f, u.phi

	void DFS(size_t a) {
		std::vector<vertex_info1> info(n, { Color::White,0,0,-1 });
		size_t time = 0;
		std::stack<size_t> s;
		s.push(a);
		while (!s.empty()) {
			size_t v = s.top();
			s.pop();
			if (std::get<0>(info[v]) != Color::Black) {
				std::cout << v + 1 << ' ';
			}
			time++;
			std::get<1>(info[v]) = time;
			std::get<0>(info[v]) = Color::Black;
			std::stack<size_t> temp;
			for (auto w : adj[v]) {
				if (std::get<0>(info[w]) == Color::White || std::get<0>(info[w]) == Color::Gray) {
					std::get<0>(info[w]) = Color::Gray;
					std::get<3>(info[w]) = v;
					temp.push(w);
				}
			}
			while (!temp.empty()) {
				auto neighbor = temp.top();
				temp.pop();
				s.push(neighbor);
			}
			time++;
			std::get<2>(info[v]) = time;
		}
	}

	using vertex_info2 = std::tuple<bool, size_t, size_t>;	// u.visit, u.d, u.phi

	void BFS(size_t s) {
		std::vector<vertex_info2> info(n, { false, std::numeric_limits<size_t>::max(), -1 });
		info[s] = { true, 0, -1 };
		std::queue<size_t> q;
		q.push(s);
		while (!q.empty()) {
			size_t u = q.front();
			q.pop();
			std::cout << u + 1 << ' ';
			for (auto v : adj[u]) {
				if (!std::get<0>(info[v])) {
					info[v] = { true, std::get<1>(info[u]) + 1, u };
					q.push(v);
				}
			}
		}
	}
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n = 0;
	int m = 0;
	int v = 0;
	std::cin >> n >> m >> v;
	Graph g(n, Graph_Type::Undirected);
	for (auto i = 0; i < m; ++i) {
		int a = 0;
		int b = 0;
		std::cin >> a >> b;
		g.add_edge(a - 1, b - 1);
	}
	g.sort_adj();
	g.DFS(v - 1);
	std::cout << '\n';
	g.BFS(v - 1);
}
