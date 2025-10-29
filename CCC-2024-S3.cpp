#include <bits/stdc++.h>
using namespace std;
#define dbg(v) cout << "Line("<<__LINE__<<")->" << #v << "=" << (v) << endl;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<int, pi> pii;
int n;


signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<pi> intervals;
    int l = 0; 
    for (int i = 0; i < n; i++) {
        if (b[l] != b[i]) {
            intervals.push_back({l, i-1});
            l = i;
        }
    }
    intervals.push_back({l, n-1});

    // for (int i = 0; i < intervals.size(); i++) {
    //     cout << intervals[i].first << " " << intervals[i].second << '\n';
    // }
    int idx = 0;
    vector<pi> rswipe, lswipe;
    for (int i = 0; i < intervals.size(); i++) {
        auto [x, y] = intervals[i];
        while (a[idx] != b[x]) {
            idx++;
            if (idx >= n) {
                cout << "NO" << '\n'; return 0;
            }
        }
        if (x < idx) {
            lswipe.push_back({x, idx});
        }
        if (y > idx) {
            rswipe.push_back({idx, y});
        }
    }

    cout << "YES" << '\n';
    cout << (lswipe.size() + rswipe.size()) << '\n';
    for (auto [x, y]: lswipe) {
        cout << "L " << x << " " << y << '\n';
    }

    sort(rswipe.begin(), rswipe.end(), greater<>());
    for (auto [x, y]: rswipe) {
        cout << "R " << x << " " << y << '\n';
    }

}