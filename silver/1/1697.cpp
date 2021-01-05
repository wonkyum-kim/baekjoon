#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>

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

	void ans(int k) {
		std::cout << info[k].distance;
	}

	// 정점 s에서 BFS를 시작
	void BFS(const vertex& s) {
		std::queue<vertex> q;
		q.push(s);
		info[s].color = Color::Gray;
		while (!q.empty()) {
			vertex u = q.front();
			q.pop();
			for (const auto& v : adj[u]) {
				// 방문한 적이 없다면
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
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n = 0;
	int k = 0;
	std::cin >> n >> k;
	Graph g(1'000'000, Graph_Type::Directed);
	g.add_edge(0, 1);
	g.add_edge(1, 0);
	g.add_edge(1, 2);
	for (auto i = 2; i < 1'000'000; ++i) {
		if (i + 1 < 1'000'000) {
			g.add_edge(i, i + 1);
			g.add_edge(i, i - 1);
		}
		if (2 * i < 1'000'000) {
			g.add_edge(i, 2 * i);
		}
	}
	g.BFS(n);
	g.ans(k);
}
