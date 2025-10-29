#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
const int MM = 10003;
int n, x, y;
vector<int> g(MM), dep(MM, 0), vis(MM, 0);
int ans = 100009;
bool good = false;

void dfs(int cur, int d) {
    if (cur == 0) return;
    vis[cur] = 1;
    dep[cur] = d;
    if (vis[g[cur]] == 0) {
        dfs(g[cur], d + 1);
    } 
    if (vis[g[cur]] == 1 && vis[y] == 1) {
        good = true;
    }
    if (cur == y) {
        ans = min(ans, d - 1);
    }
    vis[cur] = 2;

}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        g[x] = y;
    }

    cin >> x >> y;
    while (x != 0 && y != 0) {
        dfs(x, 0);
        if (good) {
            int t = x; x = y; y = t;
            dfs(x, 0);
            cout << "Yes" << ' ' << ans;
        } else {
            cout << "No";
        }
        cout << '\n';
        good = false;
        ans = 100009;
        fill(dep.begin(), dep.end(), 0);
        fill(vis.begin(), vis.end(), 0);
        cin >> x >> y;
    } 
    
}