#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<long long> v;
	long long a;

	for (int c = 0; c < n; ++c)
	{
		cin >> a;
		v.push_back(a);
	}

	long long max = v[0];
	long long min = v[0];

	for (int b = 0; b < n; ++b)
	{
		if (max <= v[b])
			max = v[b];

		if (min >= v[b])
			min = v[b];
	}

	cout << min << " " << max;
	return 0;
}
