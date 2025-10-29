#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	ll g, p, ans = 0;
    cin >> g >> p;
    set<int> gates;
    for (int i = 1; i <= g; i++) {
        gates.insert(i);
    }

    for (int i = 0, x; i < p; i++) {
        cin >> x;
        auto it = gates.upper_bound(x);
        if (it == gates.begin()) break;
        it--;
        ll gate = *it;
        gates.erase(gate);
        ans++;
    }
    cout << ans << '\n';
}