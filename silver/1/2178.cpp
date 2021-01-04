#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

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
		size_t distance = 0;
		int parent = -1;
	};

	vertex n;
	Graph_Type type;
	std::vector<std::vector<size_t>> adj;
	std::vector<vertex_info> info;

public:
	Graph(size_t n, Graph_Type dir) : n{ n }, type{ dir }, adj(n), info(n) {}

	void add_edge(const vertex& u, const vertex& v) {
		adj[u].push_back(v);
		if (type == Graph_Type::Undirected) {
			adj[v].push_back(u);
		}
	}

	void BFS(const vertex& s) {
		std::queue<vertex> q;
		q.push(s);
		info[s].color = Color::Gray;
		while (!q.empty()) {
			vertex u = q.front();
			q.pop();
			for (const auto& v : adj[u]) {
				if (info[v].color == Color::White) {
					info[v].color = Color::Gray;
					info[v].distance = info[u].distance + 1;
					info[v].parent = u;
					q.push(v);
				}
			}
			info[u].color = Color::Black;
		}
	}

	void shortest_path() {
		std::cout << info[n - 1].distance + 1;
	}
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n = 0;
	int m = 0;
	std::cin >> n >> m;
	std::vector<std::vector<bool>> maze(n, std::vector<bool>(m, false));
	for (auto i = 0; i < n; ++i) {
		std::string s;
		std::cin >> s;
		for (auto j = 0; j < m; ++j) {
			if (s[j] == '1') {
				maze[i][j] = true;
			}
		}
	}

	Graph g(n * m, Graph_Type::Undirected);
	for (auto i = 0; i < n; ++i) {
		for (auto j = 0; j < m; ++j) {
			if (maze[i][j]) {
				if (i + 1 < n && maze[i+1][j]) {
					g.add_edge(i * m + j, (i + 1) * m + j);
				}
				if (j + 1 < m && maze[i][j + 1]) {
					g.add_edge(i * m + j, i * m + j + 1);
				}
			}
		}
	}

	g.BFS(0);
	g.shortest_path();
}
