#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
int n, m, a[1001][1001];
vector<vector<pi>> adj(1e6+7);

void findFactors(int x) {
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            adj[x].push_back({x/i, i});
            if (x/i != i) {
                adj[x].push_back({i, x/i});
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    queue<pi> q;
    bool vis[1001][1001] = {};
    q.push({1, 1});
    vis[1][1] = true;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if (x == m && y == n) {
            cout << "yes" << "\n"; return 0;
        }
        
        if (adj[a[x][y]].size() == 0) findFactors(a[x][y]);
        for (auto [a, b]: adj[a[x][y]]) {
            if (a <= m && b <= n && !vis[a][b]) {
                vis[a][b] = true;
                q.push({a, b});
            }
        }
    }

    cout << "no" << '\n';

    
}