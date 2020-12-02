#include<iostream>
#include<memory>
#include<utility>
#include<stack>

template<typename T>
class BT {
private:
	struct Node {
		T key;
		std::unique_ptr<Node> left;
		std::unique_ptr<Node> right;
		Node(const T& k) :
			key{ k }, left{ nullptr }, right{ nullptr } {}
	};
	std::unique_ptr<Node> root = nullptr;

public:
	Node* make_root(const T& k) {
		root = std::make_unique<Node>(k);
		return root.get();
	}

	Node* make_left(Node* x, const T& k) {
		auto child = std::make_unique<Node>(k);
		x->left = std::move(child);
		return x->left.get();
	}

	Node* make_right(Node* x, const T& k) {
		auto child = std::make_unique<Node>(k);
		x->right = std::move(child);
		return x->right.get();
	}

	Node* search(const T& k) {
		return search(root.get(), k);
	}

	void preorder_tree_walk() {
		preorder_tree_walk(root.get());
	}

	void inorder_tree_walk() {
		inorder_tree_walk(root.get());
	}

	void postorder_tree_walk() {
		postorder_tree_walk(root.get());
	}

private:

	void preorder_tree_walk(Node* x) {
		if (x) {
			std::cout << x->key;
			preorder_tree_walk(x->left.get());
			preorder_tree_walk(x->right.get());
		}
	}

	void inorder_tree_walk(Node* x) {
		if (x) {
			inorder_tree_walk(x->left.get());
			std::cout << x->key;
			inorder_tree_walk(x->right.get());
		}
	}

	void postorder_tree_walk(Node* x) {
		if (x) {
			postorder_tree_walk(x->left.get());
			postorder_tree_walk(x->right.get());
			std::cout << x->key;
		}
	}

	Node* search(Node* x, const T& k) {
		std::stack<Node*> s;
		s.push(x);
		while (!s.empty()) {
			auto x = s.top();
			while (x) {
				s.push(x->left.get());
				x = s.top();
			}
			s.pop();
			if (!s.empty()) {
				x = s.top();
				s.pop();
				if (x->key == k) {
					return x;
				}
				s.push(x->right.get());
			}
		}
		return nullptr;
	}

};


int main()
{
	int n = 0;
	std::cin >> n;

	//----------------------------------
	char a = 0;
	std::cin >> a;
	BT<char> bt;
	auto root = bt.make_root(a);
	char b;
	char c;
	std::cin >> b >> c;
	if (b != '.') {
		auto temp = bt.make_left(root, b);
	}
	if (c != '.') {
		auto temp = bt.make_right(root, c);
	}
	//----------------------------------

	for (auto i = 0; i < n - 1; ++i) {
		char first;
		char second;
		char third;
		std::cin >> first >> second >> third;
		auto node = bt.search(first);
		if (second != '.') {
			auto temp = bt.make_left(node, second);
		}
		if (third != '.') {
			auto temp = bt.make_right(node, third);
		}
	}

	bt.preorder_tree_walk();
	std::cout << '\n';
	bt.inorder_tree_walk();
	std::cout << '\n';
	bt.postorder_tree_walk();

}
