#include <iostream>
#include <vector>
using namespace std;

int main()
{
	auto T = 0;
	cin >> T;

	vector<int> a;
	vector<int> b;

	for (int i = 0; i < T; ++i)
	{
		int x, y;
		cin >> x >> y;
		a.push_back(x);
		b.push_back(y);
	}

	for (int i = 0; i < T; ++i)
	{
		if (0 < a[i] && 0 < b[i] && a[i] < 10 && b[i] < 10)
			cout << "Case #" << (i + 1) << ':' << ' ' <<a[i]<<' '<<'+'<<' '<<b[i]<< ' '<< '=' <<' '<< a[i] + b[i] << '\n';
	}

	return 0;
}
