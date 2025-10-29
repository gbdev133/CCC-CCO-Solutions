#include <bits/stdc++.h>
using namespace std;

int t, n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t >> n;
	for (int i = 0; i < t; ++i) {
		unordered_map<char, int> d;
		string s; 
		cin >> s;
		for (auto x: s) {
			if (d.count(x)) {
				d[x]++;
			} else {
				d[x] = 1;
			}
		}
		bool flag;
		bool bad = false;
		if (d[s.at(0)] == 1) {
			flag = true;
		} else {
			flag = false;
		}

		for (int j = 1; j < n; ++j) {
			if ((flag && d[s.at(j)] == 1) || (!flag && d[s.at(j)] != 1)) {
				bad = true;
				break;
			}
			flag = !flag;
		}
		if (bad) cout << "F" << "\n";
		else cout << "T" << "\n";
	}
}