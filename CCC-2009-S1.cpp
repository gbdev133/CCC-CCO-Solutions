#include <bits/stdc++.h>
using namespace std;
#define dbg(v) cout << "Line("<<__LINE__<<")->" << #v << "=" << (v) << endl;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<int, pi> pii;
const int mod = 998244353;
int a, b;
signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> a >> b;
    int i = 0, ans = 0;
    for (; i * i * i * i * i * i <= b; i++) {
        if (i * i * i * i * i * i >= a) {
            ans++;
        }
    }
    cout << ans << '\n';

}