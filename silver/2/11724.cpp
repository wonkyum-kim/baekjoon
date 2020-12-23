#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

class Undirected_Graph {
private:	
	int n;
	std::vector<std::vector<int>> adj;
	std::vector<bool> visited;
public:
	Undirected_Graph(int n) : n{ n }, adj(n), visited(n) {}

	void add_edge(int u, int v) {
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	void dfs() {
		std::fill(visited.begin(), visited.end(), false);
		dfs(0);
	}

	int component() {
		int count = 0;
		std::fill(visited.begin(), visited.end(), false);
		for (auto i = 0; i < n; ++i) {
			if (!visited[i]) {
				dfs(i);
				count++;
			}
		}
		return count;
	}

private:
	void dfs(int s) {
		if (visited[s]) {
			return;
		}
		visited[s] = true;
		for (auto u : adj[s]) {
			dfs(u);
		}
	}
};

int main()
{
	int n = 0;
	int m = 0;
	std::cin >> n >> m;
	Undirected_Graph udg(n);
	for (auto i = 0; i < m; ++i) {
		int u = 0;
		int v = 0;
		std::cin >> u >> v;
		udg.add_edge(u - 1, v - 1);
	}
	std::cout << udg.component();
}
