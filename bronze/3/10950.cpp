#include <iostream>
#include <vector>
using namespace std;

int main()
{
	auto T = 0;
	cin >> T;
	
	for (int i = 0; i < T; ++i){
		int x, y;
		cin >> x >> y;
		cout << x + y << '\n';
	}
	return 0;
}
