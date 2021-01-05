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
		bool wall = false;
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

	void set_wall(size_t a) {
		info[a].wall = true;
	}

	int safe_zone() {
		int count = 0;
		for (auto i = 0; i < n; ++i) {
			if (info[i].color == Color::White && !info[i].wall) {
				count++;
			}
		}
		return count;
	}

	void BFS(const std::vector<int>& virus) {
		std::queue<vertex> q;
		for (auto i = 0; i < virus.size(); ++i) {
			q.push(virus[i]);
			info[virus[i]].color = Color::Gray;
		}
		while (!q.empty()) {
			vertex u = q.front();
			q.pop();
			for (const auto& v : adj[u]) {
				if (info[v].color == Color::White && !info[v].wall) {
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
	int m = 0;
	std::cin >> n >> m;

	std::vector<std::vector<int>> map(n, std::vector<int>(m));
	std::vector<int> virus;	// 바이러스가 있는 지점들

	for (auto i = 0; i < n; ++i) {
		for (auto j = 0; j < m; ++j) {
			std::cin >> map[i][j];	// 초기 지도를 입력받는다.
			if (map[i][j] == 2) {	// 바이러스가 있는 지점들을 따로 모아서 저장한다.
				virus.push_back(i * m + j);
			}
		}
	}

	std::vector<int> nn;
	for (auto i = 0; i < n; ++i) {
		for (auto j = 0; j < m; ++j) {
			if (map[i][j] == 0) {
				nn.push_back(i * m + j);	// 벽을 세울 수 있는 지점들(비어있는 곳) 추가
			}
		}
	}

	std::vector<int> ind;
	int k = 3;	// 3개를 뽑아야 한다.
	for (auto i = 0; i < k; ++i) {
		ind.push_back(1);
	}
	for (auto i = 0; i < nn.size() - k; ++i) {
		ind.push_back(0);
	}
	std::sort(ind.begin(), ind.end());
	std::vector<int> ans;

	do {
		auto t_map = map;	// 지도를 복사
		std::vector<int> new_wall;	// 조합을 통해 벽을 추가할 지점 3개를 저장
		for (auto i = 0; i < ind.size(); ++i) {
			if (ind[i] == 1) {
				new_wall.push_back(nn[i]);
			}
		}
		for (auto i = 0; i < 3; ++i) {
			int b = new_wall[i] % m;
			int a = (new_wall[i] - b) / m;
			t_map[a][b] = 1;	// 새로운 벽을 세운다.
		}

		Graph g(n * m, Graph_Type::Undirected);
		for (auto i = 0; i < n; ++i) {
			for (auto j = 0; j < m; ++j) {
				if (t_map[i][j] == 1) {
					g.set_wall(i * m + j);	// 벽인 정점을 체크
				}
			}
		}

		for (auto i = 0; i < n; ++i) {
			for (auto j = 0; j < m; ++j) {
				if (t_map[i][j] != 1) {	// 벽이 아닌 곳에서 아닌 곳으로 간선 연결
					if (i + 1 < n && t_map[i + 1][j] != 1) {
						g.add_edge(i * m + j, (i + 1) * m + j);
					}
					if (j + 1 < m && t_map[i][j + 1] != 1) {
						g.add_edge(i * m + j, i * m + j + 1);
					}
				}
			}
		}
		g.BFS(virus);
		ans.push_back(g.safe_zone());


	} while (std::next_permutation(ind.begin(), ind.end()));

	std::cout << *std::max_element(ans.begin(), ans.end());
}
