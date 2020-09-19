#include <iostream>
#include <vector>
#include <string>

using namespace std;
int S, B, T;
string s;
vector<string> v;
int check[1000];


int main() {
	cin >> T;
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			if (j != i) {
				for (int k = 1; k <= 9; k++) {
					if (k != i && k != j) {
						check[i * 100 + j * 10 + k] = 1;
					}
				}
			}
		}
	}

	for (int i = 0; i < T; i++) {
		cin >> s >> S >> B;
		for (int i = 123; i <= 999; i++) {
			if (check[i] == 1) {
				string a = to_string(i);
				int str = 0;
				int ball = 0;
				for (int i = 0; i < 3; i++) {
					if (a[i] == s[i]) {
						str++;
					}
				}
					if (a[0] == s[1] || a[0] == s[2]) {
						ball++;
					}
					if (a[1] == s[0] || a[1] == s[2]) {
						ball++;
					}
					if (a[2] == s[0] || a[2] == s[1]) {
						ball++;
					}

					if (str != S || ball != B) {
						check[i] = 0;
					}
			}
		}
	}

	int cnt = 0;
	for (int i = 123; i <= 999; i++) {
		if (check[i] == 1) {
			cnt++;
		}
	}
	cout << cnt;
}
