#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

class Graph {
private:
	int n;
	std::queue<int> q;
	std::vector<std::vector<int>> adj;
	std::vector<bool> visited;
public:
	Graph(int n) : n{n},adj(n),visited(n,false){}

	void add_edge(int u, int v) {
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	void reset() {
		std::fill(visited.begin(), visited.end(), false);
	}

	void sort_adj() {
		for (auto i = 0; i < n; ++i) {
			std::sort(adj[i].begin(), adj[i].end());
		}
	}

	void dfs(int u) {
		if (visited[u]) {
			return;
		}
		visited[u] = true;
		std::cout << u + 1 << ' ';
		for (auto v : adj[u]) {
			dfs(v);
		}
	}

	void bfs(int x) {
		visited[x] = true;
		std::vector<int> distance(n);
		q.push(x);
		while (!q.empty()) {
			int s = q.front();
			q.pop();
			std::cout << s + 1 << ' ';
			for (auto u : adj[s]) {
				if (visited[u]) {
					continue;
				}
				visited[u] = true;
				distance[u] = distance[s] + 1;
				q.push(u);
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
	Graph g(n);
	for (auto i = 0; i < m; ++i) {
		int a = 0;
		int b = 0;
		std::cin >> a >> b;
		g.add_edge(a - 1, b - 1);
	}
	g.sort_adj();
	g.dfs(v - 1);
	std::cout << '\n';
	g.reset();
	g.bfs(v - 1);
}
