#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <numeric>
#include <stack>
#include <utility>
#include <list>
#include <cassert>

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
	std::list<size_t> sorted;
	bool is_cycle = false;

public:
	Graph(size_t n, Graph_Type dir) : n{ n }, type{ dir }, adj(n) { }

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

	using vertex_info = std::tuple<Color, size_t, size_t, size_t>;	// u.color, u.d, u.f, u.phi

	void DFS() {
		std::vector<vertex_info> info(n, { Color::White, 0, 0, -1 });
		size_t time = 0;
		for (auto i = 0; i < n; ++i) {
			if (std::get<0>(info[i]) == Color::White) {
				DFS_visit(i, time, info);
			}
		}
	}

	std::list<size_t> topological_sort() {
		assert(type == Graph_Type::Directed);
		DFS();
		return sorted;
	}

	bool find_cycle() {
		return is_cycle;
	}

private:
	void DFS_visit(size_t u, size_t& time, std::vector<vertex_info>& info) {
		++time;
		std::get<1>(info[u]) = time;
		std::get<0>(info[u]) = Color::Gray;
		for (auto v : adj[u]) {
			if (std::get<0>(info[v]) == Color::White) {
				std::get<3>(info[v]) = u;
				DFS_visit(v, time, info);
			}
			else if (std::get<0>(info[v]) == Color::Gray) {
				is_cycle = true;
			}
		}
		std::get<0>(info[u]) = Color::Black;
		++time;
		std::get<2>(info[u]) = time;
		sorted.push_front(u);
	}
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n = 0;
	int m = 0;
	std::cin >> n >> m;
	Graph g(n, Graph_Type::Directed);

	for (auto i = 0; i < m; ++i) {
		int num = 0;
		std::cin >> num;
		std::vector<int> v;
		for (auto j = 0; j < num; ++j) {
			int a = 0;
			std::cin >> a;
			v.emplace_back(a - 1);
		}
		int s = v.size();
		for (auto k = 0; k < s - 1; ++k) {
			g.add_edge(v[k], v[k + 1]);
		}
	}
	auto sort = g.topological_sort();
	if (g.find_cycle()) {
		std::cout << 0;
		return 0;
	}
	while (!sort.empty()) {
		size_t temp = sort.front();
		sort.pop_front();
		std::cout << temp + 1 << '\n';
	}
}
