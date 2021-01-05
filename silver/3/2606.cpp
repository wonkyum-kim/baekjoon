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

	void answer() {
		DFS();
		int ans = 0;
		for (auto i = 0; i < n; ++i) {
			if (info[i].cc == 1) {
				ans++;
			}
		}
		// 1번 컴퓨터는 제외한다.
		std::cout << ans - 1;
	}

	void DFS() {
		time = 0;
		size_t k = 1;
		for (auto i = 0; i < n; ++i) {
			if (info[i].color == Color::White) {
				info[i].cc = k;
				++k;
				DFS_visit(i, k);
			}
		}
	}

private:
	void DFS_visit(const vertex& u, const size_t& k) {
		++time;
		info[u].d = time;
		info[u].color = Color::Gray;
		for (auto v : adj[u]) {
			info[v].cc = info[u].cc;
			if (info[v].color == Color::White) {
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
	int v = 0;
	int e = 0;
	std::cin >> v >> e;
	Graph g(v, Graph_Type::Undirected);
	for (auto i = 0; i < e; ++i) {
		int a = 0;
		int b = 0;
		std::cin >> a >> b;
		g.add_edge(a - 1, b - 1);
	}
	g.answer();
}
