#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
const int MM = 1001;
int n, m, t;




int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        queue<pi> q;
        bool vis[n][m] = {};
        int dist[n][m] = {};
        char a[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
                if (a[i][j] == '*') vis[i][j] = true;
            }
        }

        
        q.push({0, 0});
        vis[0][0] = true;
        bool good = false;
        while (!q.empty()) {
            auto [cx, cy] = q.front();
            q.pop();

            if (cx == n - 1 && cy == m - 1) {
                cout << dist[cx][cy] + 1 << '\n'; good = true; break;
            }

            
            if (a[cx][cy] == '+') {
                if (cx > 0 && !vis[cx - 1][cy]) {
                    q.push({cx-1, cy});
                    vis[cx-1][cy] = true; dist[cx-1][cy] = dist[cx][cy] + 1;
                }
                if (cx < n - 1 && !vis[cx+1][cy]) {
                    q.push({cx+1, cy});
                    vis[cx+1][cy] = true; dist[cx+1][cy] = dist[cx][cy] + 1;
                }
                if (cy > 0 && !vis[cx][cy-1]) {
                    q.push({cx, cy-1});
                    vis[cx][cy-1] = true; dist[cx][cy-1] = dist[cx][cy] + 1;
                }
                if (cy < m - 1 && !vis[cx][cy + 1]) {
                    q.push({cx, cy + 1});
                    vis[cx][cy+1] = true; dist[cx][cy+1] = dist[cx][cy] + 1;
                }
            } else if (a[cx][cy] == '|') {
                if (cx > 0 && !vis[cx - 1][cy]) {
                    q.push({cx-1, cy});
                    vis[cx-1][cy] = true; dist[cx-1][cy] = dist[cx][cy] + 1;
                }
                if (cx < n - 1 && !vis[cx+1][cy]) {
                    q.push({cx+1, cy});
                    vis[cx+1][cy] = true; dist[cx+1][cy] = dist[cx][cy] + 1;
                }
            } else if (a[cx][cy] == '-') {
                if (cy > 0 && !vis[cx][cy-1]) {
                    q.push({cx, cy-1});
                    vis[cx][cy-1] = true; dist[cx][cy-1] = dist[cx][cy] + 1;
                }
                if (cy < m - 1 && !vis[cx][cy + 1]) {
                    q.push({cx, cy + 1});
                    vis[cx][cy+1] = true; dist[cx][cy+1] = dist[cx][cy] + 1;
                }
            }


            
        }
        if (!good) cout << -1 << '\n';
    }
    return 0;
}