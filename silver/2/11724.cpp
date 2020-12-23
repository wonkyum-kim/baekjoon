#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

class Graph {
private:
	int n;
	std::vector<std::vector<int>> adj;
	std::vector<bool> visited;
public:
	Graph(int n) : n{n},adj(n),visited(n,false){}

	void add_edge(int u, int v) {
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	void dfs(int u) {
		if (visited[u]) {
			return;
		}
		visited[u] = true;
		for (auto v : adj[u]) {
			dfs(v);
		}
	}

	int component() {
		int count = 0;
		for (auto i = 0; i < n; ++i) {
			if (!visited[i]) {
				dfs(i);
				++count;
			}
		}
		return count;
	}
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n = 0;
	int m = 0;
	std::cin >> n >> m;
	Graph g(n);
	for (auto i = 0; i < m; ++i) {
		int u = 0;
		int v = 0;
		std::cin >> u >> v;
		g.add_edge(u - 1, v - 1);
	}
	std::cout << g.component();
}
