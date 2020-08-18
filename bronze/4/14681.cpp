#include <iostream>

using namespace std;

int main()
{
	struct Point {
		int xpos;
		int ypos;
	};

	Point a;
	cin >> a.xpos >> a.ypos;

	if (a.xpos >= -1000 && a.xpos <= 1000 && a.xpos != 0)
	{
		if (a.ypos >= -1000 && a.ypos <= 1000 && a.ypos != 0)
		{
			if (a.xpos > 0 && a.ypos > 0)
				cout << '1';
			else if (a.xpos < 0 && a.ypos > 0)
				cout << '2';
			else if (a.xpos < 0 && a.ypos < 0)
				cout << '3';
			else
				cout << '4';
		}
	}

	return 0;
}
