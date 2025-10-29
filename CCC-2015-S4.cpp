#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
typedef pair<ll, pi> pii;
ll n, m, k;


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> k >> n >> m;
    vector<vector<pii>> adj(n+1);
    for (int i = 0, w, x, y, z; i < m; i++) {
        cin >> w >> x >> y >> z;
        adj[w].push_back({y, {x, z}}); // adj[u] = {weight, {v,  hull}}
        adj[x].push_back({y, {w, z}});
    }
    ll a, b;
    cin >> a >> b;
    vector<vector<ll>> dist(n+7, vector<ll>(k, LLONG_MAX));
    bool vis[n+7][k] = {};
    priority_queue<pii, vector<pii>, greater<>> pq; // {dist, {v,  curhull}}
    dist[a][0] = 0;
    pq.push({0, {a, 0}});
    while (!pq.empty()) {
        auto [d, x] = pq.top(); pq.pop();
        auto [nd, h] = x;
        if (vis[nd][h]) continue;
        if (nd == b) {
            cout << d << '\n'; return 0;
        }
        vis[nd][h] = true;

        for (auto [w, p]: adj[nd]) {
            auto [v, hull] = p;
            int nstate = h+hull;
            if (nstate < k && dist[v][nstate] >= dist[nd][h] + w) {
                dist[v][nstate] = dist[nd][h] + w;
                pq.push({dist[v][nstate], {v, nstate}});
            }
        }
    }

    // for (int i = 0; i < 2; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << dist[j][i] << " ";
    //     }
    //     cout << '\n';
    // }

    cout << -1 << '\n';
    
}