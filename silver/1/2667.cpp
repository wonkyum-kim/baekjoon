#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

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
		size_t in = 0;
		size_t out = 0;
		bool is_house = false;
	};

	vertex n;
	Graph_Type g_type;
	std::vector<std::vector<vertex>> adj;
	std::vector<vertex_info> info;
	size_t time = 0;
	size_t k = 1;

public:
	Graph(vertex n, Graph_Type g_type) : n{ n }, g_type{ g_type }, adj(n), info(n){}

	void add_edge(const vertex& u, const vertex& v) {
		adj[u].push_back(v);
		info[u].out++;
		info[v].in++;
		if (g_type == Graph_Type::Undirected) {
			adj[v].push_back(u);
		}
	}

	void DFS() {
		time = 0;
		for (auto i = 0; i < n; ++i) {
			if (info[i].color == Color::White) {
				info[i].cc = k;
				++k;
				DFS_visit(i);
			}
		}
	}

	void foo(size_t h) {
		info[h].is_house = true;
	}

	void check_cc() {
		std::vector<int> rc;
		for (auto i = 0; i < n; ++i) {
			if (info[i].is_house) {
				rc.push_back(info[i].cc);
			}
		}
		std::sort(rc.begin(), rc.end());
		std::vector<int> rrc = rc;
		auto last = std::unique(rrc.begin(), rrc.end());
		rrc.erase(last, rrc.end());
		auto components = rrc.size();
		std::cout << components << '\n';
		std::vector<int> temp;
		for (auto i = 0; i < components; ++i) {
			auto count = std::count(rc.begin(), rc.end(), rrc[i]);
			temp.push_back(count);
		}
		std::sort(temp.begin(), temp.end());
		for (auto x : temp) {
			std::cout << x << '\n';
		}
	}

private:
	void DFS_visit(const vertex& u) {
		++time;
		info[u].d = time;
		info[u].color = Color::Gray;
		for (auto v : adj[u]) {
			info[v].cc = info[u].cc;
			if (info[v].color == Color::White) {
				info[v].parent = u;
				DFS_visit(v);
			}
		}
		info[u].color = Color::Black;
	}
};


int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n = 0;
	std::cin >> n;
	Graph g(n * n, Graph_Type::Undirected);
	std::vector<std::vector<bool>> house(n, std::vector<bool>(n, false));
	for (auto i = 0; i < n; ++i) {
		std::string s;
		std::cin >> s;
		for (auto j = 0; j < n; ++j) {
			if (s[j] == '1') {
				house[i][j] = true;
				g.foo(i * n + j);

			}
		}
	}

	for (auto i = 0; i < n; ++i) {
		for (auto j = 0; j < n; ++j) {
			if (house[i][j]) {
				if (i + 1 < n && house[i+1][j]) {
					g.add_edge(i * n + j, (i + 1) * n + j);
				}
				if (j + 1 < n && house[i][j + 1]) {
					g.add_edge(i * n + j, i * n + j + 1);
				}
			}
		}
	}
	g.DFS();
	g.check_cc();

}
