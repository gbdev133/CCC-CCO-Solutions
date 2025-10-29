#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
int a, b, x, y;
vector<pi> moves = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> a >> b >> x >> y;
    queue<pi> q;
    int vis[9][9] = {};
    int dist[9][9] = {};
    vis[a][b] = true;
    q.push({a, b});
    while (!q.empty()) {
        auto [n, m] = q.front();
        q.pop();

        if (n == x && m == y) {
            cout << dist[x][y];
            return 0;
        }
        for (auto [dx, dy]: moves) {
            if (n + dx <= 8 && n + dx > 0 && m + dy <= 8 && m + dy > 0) {
                vis[n + dx][m + dy] = true;
                dist[n + dx][m + dy] = dist[n][m] + 1;
                q.push({n + dx, m + dy});
            }
        }
    }


    
    
}