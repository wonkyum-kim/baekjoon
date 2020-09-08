#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
#include <vector>

int main()
{
	int test = 0;
	std::cin >> test;

	for (auto i = 0; i < test; ++i) {
		int N = 0;
		int M = 0;
		std::cin >> N >> M;
		
		// 중요도
		std::priority_queue<int> pq;
		// 중요도, 문서 번호
		std::queue<std::pair<int, int>> q;

		// 중요도와 문서 번호 입력
		for (auto i = 0; i < N; ++i) {
			int temp = 0;
			std::cin >> temp;
			q.push({ temp,i });
			pq.push(temp);
		}

		int count = 0;

		while (true) {
			// 문서가 우선 순위가 낮아서 뒤로 밀린다.
			if (q.front().first < pq.top()) {
				std::pair<int, int> temp = q.front();
				q.pop();
				q.push(temp);
			}
			// 우선 순위가 같다면 출력한다.
			else if (q.front().first == pq.top()){
				count++;
				if (M == q.front().second) {
					break;
				}
				else {
					q.pop();
					pq.pop();
				}

			}
		}

		std::cout << count << '\n';
	}
}
