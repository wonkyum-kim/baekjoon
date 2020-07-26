#include <iostream>
using namespace std;

int main()
{
	int n, x, i;
	cin >> n >> x;
	for (int k = 0; k < n; k++)
	{
		cin >> i;
		if (i < x)
			cout << i << ' ';
	}
}
