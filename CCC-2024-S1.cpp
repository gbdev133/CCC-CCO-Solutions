#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] == a[(i + n / 2) % n]) {
			ans++;
		}
	}

	cout << ans << endl;
}