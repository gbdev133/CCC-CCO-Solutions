#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
int n, m;
vector<vector<pi>> adj;

struct cmp {
    bool operator()(pi a, pi b) {
        return a.second > b.second;
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    adj.resize(n+1);
    for (int i = 0, x, y, z; i < m; i++) {
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }
    int k;
    cin >> k;
    unordered_map<int, int> mp;
    for (int i = 0, x, y; i < k; i++) {
        cin >> x >> y;
        mp[x] = y;
    }
    int d; cin >> d;

    priority_queue<pi, vector<pi>, cmp> pq;
    bool vis[n+1] = {};
    int dist[n+1];
    fill(dist, dist+n+1, INT_MAX);
    dist[d] = 0;
    pq.push({d, 0});
    while (!pq.empty()) {
        auto [cur, w] = pq.top(); pq.pop();
        if (vis[cur]) continue;
        vis[cur] = true;
        for (auto [x, y]: adj[cur]) {
            if (y + dist[cur] < dist[x]) {
                dist[x] = y+dist[cur];
                if (!vis[x]) pq.push({x, y+dist[cur]});
            }
        }
    }

    int ans = INT_MAX;
    for (auto [x, y]: mp) {
        ans = min(ans, y+dist[x]);
    }
    cout << ans << '\n';
    
}