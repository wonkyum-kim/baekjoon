#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

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
		bool possible = false;
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

	void is_toma(int a) {
		info[a].possible = true;
	}

	void check() {
		bool flag = true;
		// 토마토가 들어 있는 칸을 모두 방문했는지 확인한다.
		for (auto i = 0; i < n; ++i) {
			if (info[i].possible && info[i].color != Color::White) {
				continue;
			}
			else if (info[i].possible && info[i].color == Color::White) {
				flag = false;
			}
		}

		int min_day = -1;

		// 모든 가능한 칸에 방문했다면
		if (flag) {
			for (auto i = 0; i < n; ++i) {
				min_day = std::max(min_day, (int)info[i].distance);
			}
		}

		std::cout << min_day;
	}

	void BFS(const std::vector<size_t>& p) {
		std::queue<vertex> q;
		for (auto x : p) {
			q.push(x);
			info[x].color = Color::Gray;
		}
		while (!q.empty()) {
			vertex u = q.front();
			q.pop();
			for (const auto& v : adj[u]) {
				if (info[v].color == Color::White) {
					info[v].color = Color::Gray;
					info[v].distance = info[u].distance + 1;
					q.push(v);
				}
			}
			info[u].color = Color::Black;
		}
	}
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int m = 0;
	int n = 0;
	std::cin >> m >> n;

	Graph g(n * m, Graph_Type::Undirected);
	std::vector<size_t> points;	// 익은 토마토가 들어있는 지점들

	std::vector<std::vector<int>> toma(n, std::vector<int>(m));
	for (auto i = 0; i < n; ++i) {
		for (auto j = 0; j < m; ++j) {
			std::cin >> toma[i][j];
			// 익은 토마토 칸 
			if (toma[i][j] == 1) {
				points.push_back(i * m + j);
			}
			// 익거나 익지 않은 칸
			if (toma[i][j] != -1) {
				g.is_toma(i * m + j);
			}
		}
	}

	// 0 또는 1 지점끼리 간선 연결
	for (auto i = 0; i < n; ++i) {
		for (auto j = 0; j < m; ++j) {
			if (toma[i][j] != -1) {
				if (i + 1 < n && toma[i + 1][j] != -1) {
					g.add_edge(i * m + j, (i + 1) * m + j);
				}
				if (j + 1 < m && toma[i][j + 1] != -1) {
					g.add_edge(i * m + j, i * m + j + 1);
				}
			}
		}
	}

	g.BFS(points);
	g.check();
}
