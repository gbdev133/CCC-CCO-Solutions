#include <bits/stdc++.h>
using namespace std;
#define dbg(v) cout << "Line("<<__LINE__<<")->" << #v << "=" << (v) << endl;
typedef long long ll;
int n;
const int MM = 100 * 500 * 200 + 10;
bitset<MM/2> dp;
ll sm = 0;


signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    vector<int> k(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> k[i] >> c[i]; sm += k[i] * c[i];
    }

    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int m = 1; m <= k[i]; m *= 2) {
            int w = m * c[i];
            dp |= dp << w; k[i] -= m;
        }
        if (k[i]) {
            int w = k[i] * c[i];
            dp |= dp << w;
        }
    }

    for (int i = sm/2; i >= 0; i--) {
        if (dp[i]) {
            cout << sm - 2 * i << '\n'; return 0;
        }
    }


    

}