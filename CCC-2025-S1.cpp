#include <bits/stdc++.h>
using namespace std;
#define dbg(v) cout << "Line("<<__LINE__<<")->" << #v << "=" << (v) << endl;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<int, pi> pii;
int x, y, a, b;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> x >> y >> a >> b;
    cout << min(x + 2*y + abs(x-a) + 2 * b + a, y + 2*x + abs(y-b) + 2*a + b);

}