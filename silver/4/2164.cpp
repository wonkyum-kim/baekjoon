#include <iostream>
#include <queue>
#include <string>

int main()
{
	int n = 0;
	std::cin >> n;
	std::queue<int> q;

	for (auto i = 1; i <= n; ++i) {
		q.push(i);
	}

	while (true) {
		if (q.size() != 1) {
			q.pop();	
			int a = q.front();	
			q.pop();	
			q.push(a);	
		}
		else {
			std::cout << q.front();
			break;
		}
	}
}
